/*
 * space.h
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */

#ifndef SPACE_H_
#define SPACE_H_

#include <stdbool.h>
#include "marker.h"
bool initSpace(int*, int);
bool displaySpace(int*, int);
Marker* placeStartingMarker(int* corner, int howManyRows);
Marker* moveMarker(int* corner, int howManyRows, Marker* previousMarkerP);
void printHistoryList();

#endif /* SPACE_H_ */
