#include <stdio.h>
#include <stdbool.h>

#define  R 3 // R: Number of resources

#define  P 3 // P: Number of processes

int newAvailable[R];

// Function to calculate the need of each process
void Need(int need[P][R], int max[P][R], int allocation[P][R]){

    for (int i = 0 ; i < P ; i++)
        for (int j = 0 ; j < R ; j++)
            need[i][j] = max[i][j] - allocation[i][j];

}

bool isSafe(int processes[], int available[], int max[][R], int allocation[][R]){

    int need[P][R];
 
    // Function to calculate need matrix
    Need(need, max, allocation);
 
    // Initailly Mark all processes as infinish (false)
    bool finish[P] = {0};
 
    // To store safe sequence
    int safeSeq[P];
 
    // Make a copy of availableable resources into newAvailable
    for (int i = 0; i < R ; i++)
        newAvailable[i] = available[i];
 
    // While all processes are not finished or system is not in safe state.
    int count = 0;
    while (count < P)
    {
        bool found = false;
        /* Find a process which is not finish and whose needs can be satisfied with 
           current newAvailable[] resources. */
        for (int p = 0; p < P; p++)
        {
            /* First check if a process is finished, if not, then go for 
            next condition */
            if (finish[p] == 0)
            {
                int j;
                /* Check if for all resources of current P need is less
                than newAvailable */
                for (j = 0; j < R; j++)
                    if (need[p][j] > newAvailable[j])
                        break;
 
                // If all needs of p were satisfied.
                if (j == R)
                {
                    for (int k = 0 ; k < R ; k++)
                        newAvailable[k] += allocation[p][k];
 
                    // Add this process to safe sequence.
                    safeSeq[count++] = p;
 
                    // Mark this p as finished
                    finish[p] = 1;
 
                    found = true;
                }
            }
        }
 
        // If we could not find a next process in safe sequence.
        if (found == false)
        {
            printf("System is not in safe state\n");
            return false;
        }
    }
 
    // If system is in safe state then safe sequence will be as below
    printf("System is in safe state.\nSafe sequence is: < ");
    for (int i = 0; i < P ; i++)
        printf("%d ",safeSeq[i]);
    printf(">\n");
    return true;
}

void displayDefaultValues(int available[], int max[][R], int allocation[][R]){


    // Print No. of Process
    printf("No. of Processes: %d\n", P);

    // Print No. of Resources
    printf("No. of Resources: %d\n", R);

    // Print Available Resources
    printf("Available Resources: < ");
    for(int i = 0; i < P; i++){
        printf("%d ",available[i]);
    }
    printf(">\n");

    // Print Maximum Resource allocated to processes
    printf("Maximum Resources Allocated:\n");
    for (int i = 0 ; i < P ; i++){
        for (int j = 0 ; j < R ; j++)
            printf("%d ",max[i][j]);
        printf("\n");
    }
        
    // Print Resources which are currently allocated to processes
    printf("Resources Currently Allocated:\n");
    for (int i = 0 ; i < P ; i++){
        for (int j = 0 ; j < R ; j++)
            printf("%d ",allocation[i][j]);
        printf("\n");
    }
        
}
 
int main()
{
    int processes[] = {0, 1, 2};

    int available[] = {3, 2, 2};
    
   // Maximum Resource that can be allocated to processes
    int max[P][R] = {
                     {8, 4, 3},
                     {6, 2, 0},
                     {3, 3, 3}
                    };
 
    // Resources which are currently allocated to processes
    int allocation[P][R] = {
                            {0, 0, 1},
                            {3, 2, 0},
                            {2, 1, 1},
                           };
    printf("----------------------------------------------------------------------\n");
    displayDefaultValues(available, max, allocation);
    printf("Status of the System: ");
    
    /* To check system is in safe state or not.If the System is in 
       safe state return the safe sequence */
    isSafe(processes, available, max, allocation);
    printf("----------------------------------------------------------------------\n");


    int pNo,n[R];
    xyz:
    printf("\nEnter the process no. which demands for resources(0, 1, 2): ");
    scanf("%d",&pNo);

    if(pNo < 3 && pNo >= 0){

        printf("Enter the no. of resources required: ");
        for(int i = 0; i < R ; i++){
            scanf("%d",&n[i]);
        }

        for(int i = 0; i < R; i++){
                available[i] = available[i] - n[i];
        }

    }

    switch(pNo){
        case 0: for(int j = 0; j < R; j++){
                    allocation[0][j] = allocation[0][j] + n[j];
                }
                isSafe(processes, available, max, allocation);
                break;

        case 1: for(int j = 0; j < R; j++){
                    allocation[1][j] = allocation[1][j] + n[j];
                }
                isSafe(processes, available, max, allocation);
                break;

        case 2: for(int j = 0; j < R; j++){
                    allocation[2][j] = allocation[2][j] + n[j];
                }
                isSafe(processes, available, max, allocation);
                break;

        default : printf("Please choose the right Process(0, 1, 2):");goto xyz;
    }
 
    return 0;
}
