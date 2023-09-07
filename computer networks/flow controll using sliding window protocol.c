#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void transmission(int *i, int *N, int *frames, int *total)
{
    int k;
    while (*i <= *frames)
    {
        int z = 0;
        for (k = *i; k < *i + *N && k <= *frames; k++)
        {
            printf("Sending Frame %d...\n", k);
            (*total)++;
        }
        for (k = *i; k < *i + *N && k <= *frames; k++)
        {
            int f = rand() % 2;
            if (!f)
            {
                printf("Acknowledgment for Frame %d...\n", k);
                z++;
            }
            else
            {
                printf("Timeout!! Frame Number: %d Not Received\n", k);
                printf("Retransmitting Window...\n");
                break;
            }
        }
        printf("\n");
        *i = *i + z;
    }
}
int main()
{
    int frames, N, total = 0;
    srand(time(NULL));
    printf("Enter the Total number of frames: ");
    scanf("%d", &frames);
    printf("Enter the Window Size: ");
    scanf("%d", &N);
    int i = 1;
    transmission(&i, &N, &frames, &total);
    printf("Total number of frames which were sent and resent are: %d\n", total);
    return 0;
}