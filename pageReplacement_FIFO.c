#include <stdio.h>
int main()
{
    int i, j, n, a[50], frame[10], number_of_frames, k, available, count = 0;
    
    printf("\nEnter the Number of Pages: ");
    scanf("%d", &n);
    printf("\nEnter the Page Numbers: ");
    
    for (i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    printf("\nEnter the Number of Frames: ");
    scanf("%d", &number_of_frames);
    
    for (i = 0; i < number_of_frames; i++){
        frame[i] = -1;
    }
        
    j = 0;
    
    printf("Reference String\t\t Page Frames\n");
    
    for (i = 1; i <= n; i++){
        printf("%d\t\t", a[i]);
        available = 0;
        
        for (k = 0; k < number_of_frames; k++){
            if (frame[k] == a[i])
                available = 1;
        }
        
        if (available == 0){
            frame[j] = a[i];
            j = (j + 1) % number_of_frames;
            count++;
            for (k = 0; k < number_of_frames; k++)
                printf("%d\t", frame[k]);
        }
        
        printf("\n");
    }
    
    printf("Page Fault: %d", count);
    
    return 0;
}

/*
Output :::>


Enter the Number of Pages: 22

Enter the Page Numbers: 7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1

Enter the Number of Frames: 3
Reference String           Page Frames
        7               7      -1      -1
        0               7       0      -1
        1               7       0       1
        2               2       0       1
        0
        3               2       3       1
        0               2       3       0
        4               4       3       0
        2               4       2       0
        3               4       2       3
        0               0       2       3
        3
        0
        3
        2
        1               0       1       3
        2               0       1       2
        0
        1
        7               7       1       2
        0               7       0       2
        1               7       0       1
Page Fault: 15
*/
