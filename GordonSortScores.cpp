// GordonSortScores.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Jaylen Gordon

//Dr.  R. Knowles

//Program Description: Write a program that dynamically allocates an array large enough to hold a 
//user-defined number of test scores.  Once all the scores are entered, the array should be passed to a
//function that sorts them in ascending order.  Another function should be called that calculates the average score.  
//The program should display the sorted list of scores and averages with appropriate headings.  Use pointer notation
//rather than array notation whenever possible.


#include <iostream>
using namespace std;

//function to sort an array
void sortArray(float arrayA[], int array_size)
{
	//outer for loop
	for (int x = 0; x < array_size; x++)
	{
		//inner for loop
		for (int y = 0; y < array_size; y++)
		{
			if (arrayA[x] < arrayA[y])
			{
				//swap x and y values
				int temp = *(arrayA + x);
				*(arrayA + x) = *(arrayA + y);
				*(arrayA + y) = temp;
			}
		}
	}
}

//function to calculate the average score of tests
float averageScore(float arrayA[], int array_size)
{
	float numAvg = 0;
	for (int x = 0; x < array_size; x++)
	{
		numAvg = numAvg + *(arrayA + x);
	}
	numAvg = numAvg / array_size;

	return numAvg;
}

int main()
{
	//variable declaration
	int array_size;
	float sc, numAvg;

	//get user input for test scores
	cout << "Enter the number of test scores: ";
	cin >> array_size;

	float* score = new float[array_size];

	//get user input for each test score
	cout << "Enter the test score: ";
	for (int x = 0; x < array_size; x++)
	{
		cin >> sc;
		if (sc < 0)
		{
			cout << "Test score can only be a  positive number!";
			x--;
		}
		else
		{
			*(score + x) = sc;
		}
	}

	sortArray(score, array_size);
	numAvg = averageScore(score, array_size);

	//display the sorted array
	cout << endl << "The sorted array is (ascending): ";
	for (int x = 0; x < array_size; x++)
	{
		cout << *(score + x) << " ";
	}

	//display results
	cout << endl << endl << "The average score is: " << numAvg << endl;

	delete[] score;

	return 0;
}

