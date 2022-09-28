#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread1(){
    printf("\nThis is Thread 1\n");
    for (int i = 0; i <= 100; i++)
    {
        if (i % 2 != 0)
        {
            printf("%d\t", i);
        }
    }
}

void *thread2(){
    printf("\nThis is Thread 1\n");
    for (int i = 0; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\t", i);
        }
    }
}

int main()
{
    int status;
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
    
}
