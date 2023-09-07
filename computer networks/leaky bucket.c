#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#define BUCKET_CAPACITY 10 // Bucket capacity (in data units)
#define OUTPUT_RATE 2      // Output rate (data units per second)
typedef struct
{
    int size;       // Current bucket size
    int outputRate; // Output rate
} Bucket;
void initializeBucket(Bucket *bucket, int rate)
{
    bucket->size = 0;
    bucket->outputRate = rate;
}
void leak(Bucket *bucket)
{
    if (bucket->size > 0)
    {
        bucket->size = (bucket->size - OUTPUT_RATE) >= 0 ? (bucket->size -
                                                            OUTPUT_RATE)
                                                         : 0;
    }
}
bool sendData(Bucket *bucket, int dataSize)
{
    if (bucket->size + dataSize <= BUCKET_CAPACITY)
    {
        bucket->size += dataSize;
        return true; // Data sent successfully
    }
    return false; // Bucket overflow (congestion)
}
int main()
{
    Bucket bucket;
    initializeBucket(&bucket, OUTPUT_RATE);
    int data[] = {2, 5, 1, 4, 7, 3, 6}; // Sample data to send
    int numData = sizeof(data) / sizeof(data[0]);
    int i = 0;

    while (i < numData)
    {
        if (sendData(&bucket, data[i]))
        {
            printf("Data %d sent successfully! Bucket size: %d\n", data[i], bucket.size);
            i++;
        }
        else
        {
            printf("Bucket overflow! Waiting for bucket to empty...\n");
        }
        leak(&bucket);
        sleep(1); // Simulate 1-second time intervals (adjust as needed)
    }
    return 0;
}
