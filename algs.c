/*
########################################
# algs.c
# CS480 Summer 2026, Assignment #3
# Ronessa Mose / Nicolas Mendoza
# cssc3138 / cssc3135
########################################
*/

#include <stdlib.h>
#include "algs.h"

// Comparator for qsort, ascending order
static int cmp_int(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

// -- First Come First Served --
int fcfs_total(const int requests[], int n)
{
    int total = 0;
    // Starts at cylinder 0
    int current = 0;

    // Looks at each request in order
    for (int i = 0; i < n; i++)
    {
        total += abs(requests[i] - current);
        current = requests[i];
    }

    return total;
}

// -- Shortest Seek Time First --
int sstf_total(const int requests[], int n)
{
    // Start at cylinder 0 again but this time we check which we have visited
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int total = 0;
    int current = 0;

    // Loop until all are serviced
    for (int serviced = 0; serviced < n; serviced++)
    {
        int best_index = -1;
        int best_distance = -1;

        // Scan for closest unvisited req
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            int distance = abs(requests[i] - current);
            if (best_index == -1 || distance < best_distance)
            {
                best_index = i;
                best_distance = distance;
            }
        }

        // After finding closest then service it
        total += best_distance;
        current = requests[best_index];
        visited[best_index] = 1;
    }

    return total;
}

// -- SCAN (elevator) --
int scan_total(const int requests[], int n)
{
    // Sort all requests in ascending order using cmp_int from above
    int sorted[n];
    for (int i = 0; i < n; i++)
        sorted[i] = requests[i];
    qsort(sorted, n, sizeof(int), cmp_int);

    int total = 0;
    int current = 0;

    // Go through each in order
    for (int i = 0; i < n; i++)
    {
        total += sorted[i] - current;
        current = sorted[i];
    }

    return total;
}