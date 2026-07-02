/* 
########################################
# main.c
# CS480 Summer 2026, Assignment #3
# Ronessa Mose / Nicolas Mendoza
# cssc3138 / cssc3135
######################################## 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algs.h"

#define MAX_CYLINDER 1000

int main(int argc, char *argv[])
{
    //Check if the number of arguments doesn't equal 2
    if (argc != 2)
    {
        printf("Usage: ./simarm <sequence length>\n");
        return 1;
    }

    //Convert the sequence length into an integer
    int length = atoi(argv[1]);

    //Checks if the sequence length isn't greater than 0
    if (length <= 0)
    {
        printf("Sequence length must be greater than 0.\n");
        return 1;
    }

    //Creates an array for the cylinder requests
    int requests[length];

    //Generates different random numbers each time
    srand(time(NULL));

    printf("Generated sequence:\n");

    //Fills the array with random cylinder requests
    for (int i = 0; i < length; i++)
    {
        requests[i] = rand() % MAX_CYLINDER;
        printf("%d ", requests[i]);
    }

    printf("\n");

    // Run all three algorithms against the same sequence
    int fcfs_distance = fcfs_total(requests, length);
    int sstf_distance = sstf_total(requests, length);
    int scan_distance = scan_total(requests, length);

    printf("\nTotal head movement (starting at cylinder 0):\n");
    printf("FCFS: %d cylinders\n", fcfs_distance);
    printf("SSTF: %d cylinders\n", sstf_distance);
    printf("SCAN: %d cylinders\n", scan_distance);

    return 0;
}