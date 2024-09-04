
/*****************************************************************
Marcus Gill
CS111
Template prepared by Kazumi Slott
11-1-16
Lab on 2D arrays
*****************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;


#include <iostream>
#include <iomanip>
using namespace std;

// Declare 2 constants for the sizes of the 2-dimensional array
const int NUM_STU = 5;
const int NUM_TEST = 3;

// Prototype for showTable function
void showTable(int scores[NUM_STU][NUM_TEST]);

int main()
{
  // Declare the 2-dimensional array and initialize it using the initialization list
  int scores[NUM_STU][NUM_TEST] = {
    {45, 67, 78},
    {78, 88, 56},
    {86, 96, 78},
    {78, 77, 67},
    {67, 57, 57}};

  // Call the showTable function
  showTable(scores);

  return 0;
}
void showTable(int scores[NUM_STU][NUM_TEST])
{
  // Set the width for each output
  const int colWidth = 8;
  const int avgWidth = 10;

  // Show the labels for the table
  cout << setw(colWidth) << "Test#";
  for (int stu = 1; stu <= NUM_STU; ++stu)
    {
      cout << setw(colWidth) << "Stu" << stu;
    }
  cout << setw(avgWidth) << "Average" << endl;

  // Show the table using a nested for loop
  for (int test = 0; test < NUM_TEST; ++test)
    {
      cout << setw(colWidth) << test + 1;

      int total = 0;
      for (int stu = 0; stu < NUM_STU; ++stu)
	{
	  cout << setw(colWidth) << scores[stu][test];
	  total += scores[stu][test];
	}


      double average = static_cast<double>(total) / NUM_STU;
      cout << setw(avgWidth) << fixed << setprecision(1) << average << endl;
    }

  // Additional row for student averages aligned at the bottom
  cout << setw(colWidth) << "Average";
  for (int stu = 1; stu <= NUM_STU; ++stu)
    {
      int total = 0;
      for (int test = 0; test < NUM_TEST; ++test)
	{
	  total += scores[stu - 1][test];
	}
      double average = static_cast<double>(total) / NUM_TEST;
      cout << setw(colWidth) << fixed << setprecision(1) << average;
    }
  cout << endl;
}
