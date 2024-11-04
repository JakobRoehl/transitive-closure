#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#define E 0

int GRID[9][9] = { 
    {5, 3, E, E, 7, E, E, E, E}, 
    {6, E, E, 1, 9, 5, E, E, E}, 
    {E, 9, 8, E, E, E, E, 6, E}, 
    {8, E, E, E, 6, E, E, E, 3}, 
    {4, E, E, 8, E, 3, E, E, 1}, 
    {7, E, E, E, 2, E, E, E, 6}, 
    {E, 6, E, E, E, E, 2, 8, E}, 
    {E, E, E, 4, 1, 9, E, E, 5}, 
    {E, E, E, E, 8, E, E, 7, 9} 
  }; 

void print(void)
{
    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (*(*(GRID + i)+ j) == E)
            {
                printf("x ");
            } else
            {
                printf("%d ", *(*(GRID + i)+ j));
            }
            if ((j + 1) % 3 == 0)
            {
                printf(" ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
        {
                printf("\n");
        }
    } 
}
int isLegal(void)
{
    int emptyCount = 0;

    for (int i = 0; i < 9; i++)
    {
        int valids[10] = {0,0,0,0,0,0,0,0,0,0};
        for (int j = 0; j < 9; j++)
        {
            if (GRID[i][j] == E)
            {
                emptyCount++;
                continue;
            }
            valids[GRID[i][j]]++;

            if (valids[GRID[i][j]] > 1)
            {
                return false;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        int valids[10] = {0,0,0,0,0,0,0,0,0,0};
        for (int j = 0; j < 9; j++)
        {
            if (GRID[j][i] == E)
            {
                continue;
            }
            valids[GRID[j][i]]++;

            if (valids[GRID[j][i]] > 1)
            {
                return false;
            }
        }
    }
    for (int bigRow = 0; bigRow < 3; bigRow++)
    {
        for (int bigColumn = 0; bigColumn < 3; bigColumn++)
        {
            int valids[10] = {0,0,0,0,0,0,0,0,0,0};
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int current = GRID[bigRow * 3 + i][bigColumn * 3 + j];
                    if (current == E)
                    {
                        continue;
                    }
                    valids[current]++;
                    if (valids[current] > 1)
                    {
                        return false;
                    }
                }
            }
        }
    }
    //Full solution has been found (multiple solutions could exist)
    if (emptyCount == 0)
    {
        print();
    }

    return true;

}

void bruteForce()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (GRID[i][j] == E)
            {
                for (int value = 1; value < 10; value++)
                {
                    GRID[i][j] = value;
                    if (isLegal())
                    {  
                        bruteForce();
                    }
                }
                GRID[i][j] = E;
                return;
            }
        }
    }
}

int main(void)
{
    print();
    bruteForce();
    return EXIT_SUCCESS;
}
