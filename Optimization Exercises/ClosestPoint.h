#pragma once
#include "cell.h"
#include <iostream>
#include "Util.h"
#include <ctime>
#include <random>

class ClosestPoint
{
public:

	float bruteForce(Cell P[], int n);

	float stripClosest(Cell strip[], int size, float d);

	int compareX(const void * a, const void * b);

	int compareY(const void * a, const void * b);

	float closestUtil(Cell P[], int n);

	float closest(Cell P[], int n);

	bool checkOnTable(Cell point[], int x, int y);
	void runClosestPoint();

	int rng();

	Cell pointA, pointB;

	float minimum = FLT_MAX;

	Util util;
};

