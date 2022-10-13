#include<stdio.h>
#include <stdlib.h>

int main()
{
  	int p, c, count = 0, i, j, safe[5], available[3], finish[5], terminate = 0;
  	printf("Enter the Number of Processes and Resources: ");
  	scanf("%d %d", & p, & c);
  	
  	int **alc = (int **)malloc(p * sizeof(int*));
  	int **max = (int **)malloc(p * sizeof(int*));
    int **need = (int **)malloc(p * sizeof(int*));
    
	for(i = 0; i < p; i++)
	{
        alc[i] = (int *)malloc(c * sizeof(int));
  		max[i] = (int *)malloc(c * sizeof(int));
  		need[i] = (int *)malloc(c * sizeof(int));
	}
	
  	printf("Enter Allocation of Resource of all Process %dx%d Matrix: ", p, c);
  	for (i = 0; i < p; i++) 
	{
    	for (j = 0; j < c; j++) 
		{
      		scanf("%d", & alc[i][j]);
      	}
    }

	  printf("Enter the Max Resource Process Required %dx%d Matrix: ", p, c);
	  for (i = 0; i < p; i++) {
	    for (j = 0; j < c; j++) {
	      scanf("%d", & max[i][j]);
	    }
	  }
	  printf("Enter the  Available Resource: ");
	  for (i = 0; i < c; i++)
	    scanf("%d", & available[i]);
	
	  printf("\nNeed Resources Matrix are: \n");
	  for (i = 0; i < p; i++) {
	    for (j = 0; j < c; j++) {
	      need[i][j] = max[i][j] - alc[i][j];
	      printf("%d\t", need[i][j]);
	    }
	    printf("\n");
	  }
	
	  for (i = 0; i < p; i++) {
	    finish[i] = 0;
	  }
	
	  while (count < p) {
	    for (i = 0; i < p; i++) {
	      if (finish[i] == 0) {
	        for (j = 0; j < c; j++) {
	          if (need[i][j] > available[j])
	            break;
	        }
	        
	        if (j == c) {
	          safe[count] = i;
	          finish[i] = 1;
	          
	          for (j = 0; j < c; j++) {
	            available[j] += alc[i][j];
	          }
	          count++;
	          terminate = 0;
	        } else {
	          terminate++;
	        }
	      }
	    }
	    if (terminate == (p - 1)) {
	      printf("Safe Sequence does not exist: ");
	      break;
	    }
	
	  }
	  if (terminate != (p - 1)) {
	    printf("\nAvailable Resource after Completion: \n");
	    for (i = 0; i < c; i++) {
	      printf("%d\t", available[i]);
	    }
	    printf("\n Safe Sequence are: \n");
	    for (i = 0; i < p; i++) {
	      printf("p%d\t", safe[i]);
	    }
	  }
	
	  return 0;
	}
