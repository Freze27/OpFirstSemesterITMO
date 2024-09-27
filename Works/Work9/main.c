#include <stdio.h>


void subscription(int time, int cost, int cost_over) {
    int answer;
    if (time <= 499) {
        answer = cost;
    } else {
        answer = cost + ((time - 499) * cost_over);
    }
    printf("subscription fee = %d\n", answer);
}

void prime_numbers(int n) {
    int mass[n + 1];
    for (int i = 0; i < n + 1; i++) {
        mass[i] = i;
    }
    int index = 2;
    while (index <= n) {
        if (mass[index] != 0) {
            int next_number = 2*index;
            while (next_number<=n){
                mass[next_number] = 0;
                next_number+=index;
            }
        }
        index+=1;
    }
    printf("Prime numbers: ");
    for(int i=2;i<n+1;i++){
        if(mass[i]!=0){
            printf("%d ",mass[i]);
        }
    }
}


int main() {
    int time, cost, cost_over, n;
    scanf("%d", &time);
    scanf("%d", &cost);
    scanf("%d", &cost_over);
    subscription(time, cost, cost_over);
    scanf("%d", &n);
    prime_numbers(n);
    return 0;
}
