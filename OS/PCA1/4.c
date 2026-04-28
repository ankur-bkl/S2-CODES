#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];

    printf("Enter Burst Time:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    int complete = 0, time = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    int check = 0;

    while(complete != n) {
        for(int j = 0; j < n; j++) {
            if(rt[j] < minm && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if(check == 0) {
            time++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if(minm == 0)
            minm = INT_MAX;

        if(rt[shortest] == 0) {
            complete++;
            check = 0;
            finish_time = time + 1;

            wt[shortest] = finish_time - bt[shortest];
            if(wt[shortest] < 0)
                wt[shortest] = 0;
        }
        time++;
    }

    for(int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat/n);

    return 0;
}