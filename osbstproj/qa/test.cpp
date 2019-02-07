/**
 *
 * @file: test.cpp
 * @author: Daniel Angelov <tautochrone4@gmail.com>
 *
 * @brief: Simple osbst lib tests.
 */
#include "osbst.h"

int main()
{	
	int testResult = 0;

	// Test Case 1
	// 5 15 35 45 51 --> Median: 35
	OSBST bs, bs1, bs2;
	bs.Insert(5);
	bs.Insert(15);
	bs.Insert(51);
	bs.Insert(45);
	bs.Insert(35);

	if (bs.MedianValue() != 35.0f)
	{
		testResult++;
	}

	//Test Case 2
	// 8 11 13 14 22 24 --> Median: (13 + 14) / 2 = 13.5
	bs1.Insert(8);
	bs1.Insert(11);
	bs1.Insert(14);
	bs1.Insert(13);
	bs1.Insert(22);
	bs1.Insert(24);
	
	if (bs1.MedianValue() != 13.5f)
	{
		testResult++;
	}

	//Test Case 3
	// 8 11 14 22 24 --> Median: 14
	bs2.Insert(8);
	bs2.Insert(11);
	bs2.Insert(14);
	bs2.Insert(22);
	bs2.Insert(24);
	
	if (bs2.MedianValue() != 14.0f)
	{
		testResult++;
	}

	return testResult;
}