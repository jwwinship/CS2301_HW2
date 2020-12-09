/*
 * space.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */
#include <stdio.h>
#include "space.h"
#include "marker.h"
#include <time.h>

//A list of markers in the space
LLNode* markerList;

bool initSpace(int* corner, int howManyRows)
{
	bool ok = true;
	for(int row = 0; row< 20; row++)
	{
		for(int col = 0; col < 20; col++)
		{
		    //wrong value for test
			*(corner+row*howManyRows + col) = 0;
		}
	}

	//Also initializing the Linked List
	markerList = makeEmptyLinkedList();
	return ok;
}

bool displaySpace(int* corner, int howManyRows)
{
    bool ok = true;
    for(int row = 0; row< 20; row++)
    {
        for(int col = 0; col < 20; col++)
        {
             int x = *(corner+row*howManyRows + col);
             printf("|%d",x%10);
        }
        printf("|\n");
    }

    return ok;
}

Marker* placeStartingMarker(int* corner, int howManyRows)
{
    int startingRow = rand()%20;
    int startingColumn = rand()%20;
    //Reach into marker.c/h to make a new marker. Starting index is one

    Marker* initialMarker = placeMarker(startingRow, startingColumn, 1);
    //Hopefully, this will fill a 1 in somewhere.
    *(corner+startingRow*howManyRows + startingColumn) = initialMarker->index;
    savePayload(markerList, initialMarker);
    return initialMarker;
}

//TODO: Update so that random direction is more random.
Marker* moveMarker(int* corner, int howManyRows, Marker* previousMarkerP)
{
    int prevRow = previousMarkerP->row;
    int prevColumn = previousMarkerP->col;
    int prevIndex = previousMarkerP->index;

    int direction;
    //These lines will choose a number between 0-7, which will correspond to a direction as follows
    //-----7 0 1-------
    //-----6 M 2-------
    //-----5 4 3-------
    //The marker will then move to the cell indicated by the m
    //srand(time(0));
    //These next lines will determine if the previous marker is on the edge, and move it accordingly.
    //srand(time(0));
    if (prevRow ==0)
    {
        if (prevColumn == 0)
        {
            //Top left corner, only directions available are 2,3,4
            direction = rand()%3 + 2;
        }
        else if (prevColumn == 19)
        {
            //Top right corner, only directions 4,5,6
            direction = rand()%3 + 4;
        }
        else
        {
            //Just somewhere on the top row, so directions are 2-6
            direction = rand()%5 + 2;
        }
    }
    else if (prevRow == 19)
    {
        if (prevColumn == 0)
        {
            //bottom left corner, so directions are 0,1,2
            direction = rand()%3;
        }
        else if (prevColumn == 19)
        {
            //bottom right corner, so directions are 6,7,8. Need 2 modulo operators to make the rollover work.
            direction = (rand()%3 + 6)%8;

        }
        else
        {
            //somewhere on bottom row, so options are 6,7,0,1,2. Also need to handle the rollover
            direction = (rand()%5 + 6) % 8;
        }
    }
    else if (prevColumn == 0)
    {
        //Handles leftmost edge, but corners are already covered above.
        //Directions are 0-4
        direction = rand()%5;
    }
    else if (prevColumn == 19)
    {
        //Handles rightmost edge, corners already covered above
        //Directions are 4,5,6,7,0
        direction = (rand()%5 + 4) % 8;
    }
    else
    {
        //Somewhere in the middle
        direction = rand()%8;
    }

    //direction = rand()%8;





    int row,column, index;
    switch(direction)
    {
        case 0:
        {
            column = prevColumn;
            row = prevRow - 1;
            break;
        }
        case 1:
        {
            column = prevColumn + 1;
            row = prevRow - 1;
            break;
        }
        case 2:
        {
            column = prevColumn + 1;
            row = prevRow;
            break;
        }
        case 3:
        {
            column = prevColumn + 1;
            row = prevRow + 1;
            break;
        }
        case 4:
        {
            column = prevColumn;
            row = prevRow + 1;
            break;
        }
        case 5:
        {
            column = prevColumn - 1;
            row = prevRow + 1;
            break;
        }
        case 6:
        {
            column = prevColumn - 1;
            row = prevRow;
            break;
        }
        case 7:
        {
            column = prevColumn - 1;
            row = prevRow - 1;
            break;
        }
        default:
            printf("Well, something went horribly wrong here.");
            break;
    }
    index = prevIndex + 1;
    //Reach into marker.c/h to make a new marker. Index is passed into function.
    Marker* marker = placeMarker(row, column, index);
    *(corner+row*howManyRows + column) = index;
    savePayload(markerList,marker);
    return marker;
}

void printHistoryList()
{
    //prints out the entirety of the marker history list
    printList(markerList);
}

