#include <stdio.h>
#include <stdbool.h>

#define  R 3 // R: Number of resources

#define  P 3 // P: Number of processes

// Function to calculate the need of each process
void Need(int need[P][R], int max[P][R], int allocation[P][R]){

    for (int i = 0 ; i < P ; i++)
        for (int j = 0 ; j < R ; j++)
            need[i][j] = max[i][j] - allocation[i][j];

}

bool isSafe(){
    // work to be done
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
 
    return 0;
}
