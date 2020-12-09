/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include <time.h>
#include "tests.h"
#include "production.h"
#include "space.h"


bool tests()
{
	bool answer = false;

    bool ok1 = testInitSpace();
    bool ok2 = testPlaceMarker();
	bool ok3 = testAddMarkerToList();
	bool ok4 = testPrintList();


	answer = ok1 && ok2 && ok3 && ok4;
	return answer;
}

bool testReadFile()
{
	bool ok = false;
	puts("starting testReadFile");fflush(stdout);
	//what are the criteria for success for
	//test case 1:
	//test case 2:

    if(ok)
    {
    	puts("test read file passed.");
    }
    else
    {
    	puts("test read file did not pass.");
    }
	return ok;
}

bool testGotAdjacencyMatrix()
{
	bool ans = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ans;
}

bool testSomethingElse()
{
	bool ans = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ans;
}
bool testRemoveFromList()
{
	bool ok = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ok;
}
bool testInitSpace()
{
    bool ok = false;
    int howManyColumns = 20;
    int* corner = malloc(howManyColumns*howManyColumns*sizeof(int));
    ok = initSpace(corner, howManyColumns);

    //Test to see if space is all zeroes
    for(int row = 0; row< 20; row++)
    {
        for(int col = 0; col < 20; col++)
        {
            if (*(corner+row*howManyColumns + col) != 0)
            {
                ok = false;
            }
        }
    }

    if(ok)
    {
        puts("Test Init Space passed\n");
    }
    else
    {
        puts("Test Init Space did not pass\n");
    }
    return ok;
}
bool testPlaceMarker()
{
    bool ok = false;
    int howManyColumns = 20;
    int* corner = malloc(howManyColumns*howManyColumns*sizeof(int));
    initSpace(corner, howManyColumns);
    Marker* testMarker = placeStartingMarker(corner, howManyColumns);
    moveMarker(corner, howManyColumns, testMarker);
    puts("Testing placement of markers on grid");
    displaySpace(corner, howManyColumns);

    //Test to see if a marker has not been placed
    for(int row = 0; row< 20; row++)
    {
        for(int col = 0; col < 20; col++)
        {
            if (*(corner+row*howManyColumns + col) != 0)
            {
                ok = true;
            }
        }
    }
    if(ok)
    {
        puts("Test Place Marker passed\n");
    }
    else
    {
        puts("Test Place Marker did not pass\n");
    }
    return ok;
}


bool testAddMarkerToList()
{
    bool ok = true;
    LLNode* markerList = makeEmptyLinkedList();
    Marker* testMarker = malloc(sizeof(Marker));
    testMarker->index = 9;
    testMarker->row = 13;
    testMarker->col = 7;
    savePayload(markerList, testMarker);
    printList(markerList);

    if(isEmpty(markerList))
    {
        ok = false;
    }

    if(ok)
    {
        puts("Test Add Marker To List passed\n");
    }
    else
    {
        puts("Test Add Marker To List did not pass\n");
    }
    return ok;
};

//Visual test, user must self-verify
bool testPrintList()
{
    bool ok = true;
    LLNode* markerList = makeEmptyLinkedList();
    for (int i = 0; i<5; i++)
    {
        Marker* testMarker = malloc(sizeof(Marker));
        testMarker->index = i;
        testMarker->row = rand()%20;
        testMarker->col = rand()%20;
        savePayload(markerList, testMarker);

    }
    printf("\nTesting Ability to print the contents of a list\n");
    printList(markerList);
    return ok;
}