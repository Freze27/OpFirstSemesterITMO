#include <stdio.h>
#include <string.h>
#include <math.h>

struct Header {
    char mark_id3[3];
    char ver;
    char sub_ver;
    char flag;
    char size[4];
};
struct Frame {
    char name[4];
    char size[4];
    char flags[2];
};

void CalcNewFrameSize(char *frame_size, int value_size) {
    for (int i = 0; i < 4; i++) {
        frame_size[i] = value_size / pow(2, 7 * (3 - i));
        value_size -= frame_size[i] * pow(2, 7 * (3 - i));
    }
}


void PrintFrame(FILE *f, long long int frame_size) {
    while (frame_size > 0) {
        char a = fgetc(f);
        if (a >= 32 && a <= 127)
            printf("%c", a);
        frame_size--;
    }
};

int CalcFrameSize(char *arr) {
    int size = 0;
    unsigned char a;
    for (int i = 0; i < 4; i++) {
        a = arr[i];
        printf("%c", a);
        size += a * pow(2, 7 * (3 - i));
    }
    return size;
}

void ShowAllFrames(const char *filename) {
    FILE *f = fopen(filename, "rb");
    struct Header main_header;
    fread(&main_header, 10, 1, f);
    long long frames_size = CalcFrameSize(main_header.size);
    long long counter = 0;
    struct Frame frame;
    while (counter <= frames_size) {
        fread(&frame, sizeof(frame), 1, f);
        long long frame_size = CalcFrameSize(frame.size);
        counter += 10 + frame_size;
        if (strcmp(frame.name, "APIC") == 0) {
            fseek(f, frame_size, SEEK_CUR);
        } else if ((frame.name[0] >= 65) && (frame.name[0] <= 91) && (strcmp(frame.name, "APIC") != 0)) {
            printf("%s ", frame.name);
            PrintFrame(f, frame_size);
            printf("\n");
        } else {
            break;
        }
    }
    fclose(f);
}


void GetFrame(const char *filename, const char *prop_name) {
    FILE *f = fopen(filename, "rb");
    struct Header main_header;
    fread(&main_header, 10, 1, f);
    long long frames_size = CalcFrameSize(main_header.size);
    long long counter = 0;
    struct Frame frame;
    while (counter <= frames_size) {
        fread(&frame, sizeof(frame), 1, f);
        long long frame_size = CalcFrameSize(frame.size);
        counter += 10 + frame_size;
        if ((strcmp(frame.name, prop_name) == 0)) {
            printf("%s ", frame.name);
            PrintFrame(f, frame_size);
            printf("\n");
        } else {
            fseek(f, frame_size, SEEK_CUR);
        }
    }
    fclose(f);
}

void SetValue(const char *filename, const char *prop_name, char *value) {
    FILE *f = fopen(filename, "rb+");
    FILE *new_file = fopen("newfile.mp3", "wb+");
    struct Header main_header;
    fread(&main_header, 10, 1, f);
    long long int frames_size = CalcFrameSize(main_header.size);
    long long int counter = 0;
    struct Frame frame;
    while (counter <= frames_size) {
        int frame_pos = ftell(f);
        fread(&frame, sizeof(frame), 1, f);
        long long int frame_size = CalcFrameSize(frame.size);
        counter += 10 + frame_size;
        if ((strcmp(frame.name, prop_name) == 0)) {
            long long int old_frame_size = frame_size;
            CalcNewFrameSize(main_header.size, CalcFrameSize(main_header.size) - frame_size + strlen(value));
            int current = ftell(f);
            fseek(f, old_frame_size, SEEK_CUR);
            unsigned char a = fgetc(f);
            while (!feof(f)) {
                fwrite(&a, 1, 1, new_file);
                a = fgetc(f);
            }
            fseek(f, 6, SEEK_SET);
            fwrite(main_header.size, sizeof(main_header.size), 1, f);
            CalcNewFrameSize(frame.size, strlen(value));
            fseek(f, frame_pos, SEEK_SET);
            fwrite(&frame, sizeof(frame), 1, f);
            fseek(f, current, SEEK_SET);
            fwrite(value, strlen(value), 1, f);
            fseek(new_file, 0, SEEK_SET);
            unsigned char t = fgetc(new_file);
            while (!feof(new_file)) {
                fwrite(&t, 1, 1, f);
                t = fgetc(new_file);
            }
        } else if (frame_size >= 0) {
            fseek(f, frame_size, SEEK_CUR);
        }
    }
    fclose(f);
    fclose(new_file);
}

int main(int argc, char **argv) {
    char *filename = argv[1] + 11;
    char *prop_name = NULL;
    char *value = NULL;
    if (strncmp("--get", argv[2], 5) == 0) {
        prop_name = argv[2] + 6;
        GetFrame(filename, prop_name);
    } else if (strncmp("--set", argv[2], 5) == 0) {
        prop_name = argv[2] + 6;
        value = argv[2 + 1] + 8;
        SetValue(filename, prop_name, value);
    } else if (strcmp("--show", argv[2]) == 0) {
        ShowAllFrames(filename);
    }
    return 0;
}