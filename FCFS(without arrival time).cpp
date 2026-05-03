#include <stdio.h>

int main() {
    int n, bt[20], at[20], wt[20], tat[20], ct[20];
    float avwt = 0, avtat = 0;
    int i, j;
    
    printf("Enter total number of processes (maximum 20): ");
    scanf("%d", &n);
    
    printf("Enter Process Arrival Time and Burst Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }
    
    // Calculate completion time
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        if (at[i] > ct[i-1]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i-1] + bt[i];
        }
    }
    
    // Calculate turnaround time and waiting time
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i]; // Turnaround time
        wt[i] = tat[i] - bt[i]; // Waiting time
        avwt += wt[i];
        avtat += tat[i];
    }
    
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i], ct[i]);
    }
    
    avwt /= n;
    avtat /= n;
    printf("\nAverage Waiting Time: %f\n", avwt);
    printf("\nAverage Turnaround Time: %f\n", avtat);
    
    return 0;
}


