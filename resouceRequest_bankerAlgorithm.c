#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int max[100][100], alloc[100][100], need[100][100], avail[100], n, r;
void input()
{
    int i, j;
    printf("Enter the no of Processes\t");
    scanf("%d", &n);
    printf("Enter the no of resources instances\t");
    scanf("%d", &r);
    printf("Enter the Max Matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("\nEnter for position[%d][%d]: ", i, j);
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Allocation Matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("\nEnter for position[%d][%d]: ", i, j);
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the available Resources\n");
    for (j = 0; j < r; j++)
    {
        printf("\nEnter for position[%d]: ", j);
        scanf("%d", &avail[j]);
    }
}
void show()
{
    int i, j;
    printf("Process\t Allocation\t Max\t\t Need\t Available");
    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t ", i);
        for (j = 0; j < r; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("\t\t");
        for (j = 0; j < r; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\t\t");
        for (j = 0; j < r; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\t");
        if (i == 0)
        {
            for (j = 0; j < r; j++)
                printf("%d ", avail[j]);
        }
    }
}
void cal()
{
    int finish[100], flag = 1, k, c1 = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("\n");
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            int c = 0;
            for (j = 0; j < r; j++)
            {
                if ((finish[i] == 0) && (need[i][j] <= avail[j]))
                {
                    c++;
                    if (c == r)
                    {
                        for (k = 0; k < r; k++)
                        {
                            avail[k] += alloc[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }
                        printf("P%d->", i);
                        if (finish[i] == 1)
                        {
                            i = n;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 1)
        {
            c1++;
        }
        else
        {
            printf("P%d->", i);
        }
    }
    if (c1 == n)
    {
        printf("\n The system is in safe state\n");
    }
    else
    {
        printf("\n Process are in dead lock\n");
        printf("\n System is in unsafe state\n");
    }
}
void request()
{
    int c, pid, request[100][100], i;
    printf("\n Do you want make an additional request for any of the process ? (1=Yes|0=No): ");
    scanf("%d", &c);
    if (c == 1)
    {
        printf("\n Enter process number : ");
        scanf("%d", &pid);
        printf("\n Enter additional request : \n");
        for (i = 0; i < r; i++)
        {
            printf(" Request for resource %d : ", i + 1);
            scanf("%d", &request[0][i]);
        }
        for (i = 0; i < r; i++)
        {
            if (request[0][i] > need[pid][i])
            {
                printf("\n ******Error encountered******\n");
                exit(0);
            }
        }
        for (i = 0; i < r; i++)
        {
            avail[i] -= request[0][i];
            alloc[pid][i] += request[0][i];
            need[pid][i] -= request[0][i];
        }
        cal();
        // getch();
    }
    else
    {
        exit(0);
    }
}
int main()
{
    int i, j;
    printf("********** Banker's Algo ************\n");
    input();
    cal();
    show();
    request();
    // getch();
    return 0;
}

/*
********** Banker's Algo ************
Enter the no of Processes       5
Enter the no of resources instances     3
Enter the Max Matrix      

Enter for position[0][0]: 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3

Enter for position[0][1]:
Enter for position[0][2]:
Enter for position[1][0]:
Enter for position[1][1]:
Enter for position[1][2]:
Enter for position[2][0]:
Enter for position[2][1]:
Enter for position[2][2]:
Enter for position[3][0]:
Enter for position[3][1]:
Enter for position[3][2]:
Enter for position[4][0]:
Enter for position[4][1]:
Enter for position[4][2]: Enter the Allocation Matrix

Enter for position[0][0]: 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2

Enter for position[0][1]:
Enter for position[0][2]:
Enter for position[1][0]:
Enter for position[1][1]:
Enter for position[1][2]:
Enter for position[2][0]:
Enter for position[2][1]:
Enter for position[2][2]:
Enter for position[3][0]:
Enter for position[3][1]:
Enter for position[3][2]:
Enter for position[4][0]:
Enter for position[4][1]:
Enter for position[4][2]: Enter the available Resources

Enter for position[0]: 3

Enter for position[1]: 3

Enter for position[2]: 2

P1->P3->P4->P2->P0->
 The system is in safe state
Process  Allocation      Max             Need    Available
P0       0 1 0          7 5 3           7 4 3   8 8 7
P1       2 0 0          3 2 2           1 2 2
P2       3 0 2          9 0 2           6 0 0
P3       2 1 1          2 2 2           0 1 1
P4       0 0 2          4 3 3           4 3 1
 Do you want make an additional request for any of the process ? (1=Yes|0=No): 1

 Enter process number : 0

 Enter additional request :
 Request for resource 1 : 7
 Request for resource 2 : 4
 Request for resource 3 : 3

P0->P1->P3->P4->P2->
 The system is in safe state
*/
