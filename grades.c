/* This program keeps records and performs statistical analysis on quizzes for a class of students. 
The program prints the student scores and calculates and prints statistics for each quiz. The input 
is read from a text file 

Written By: Afnan Sultan
Date Last Modified: 7/5/17
*/

// There are 40 students and 5 quizzes

#define MAX_STUDENTS 40
#define MAX_QUIZES 5
#include <stdio.h>

// Function declarations

void getData (int ID[], int scores[][MAX_QUIZES], int* num_students); 
int calculate (int scores[][MAX_QUIZES], int high[MAX_QUIZES], int low[MAX_QUIZES], double average[MAX_QUIZES], int 
num_students);
int calcHiScore (int scores[][MAX_QUIZES], int quiz_count, int num_students);
int calcLowScore (int scores[][MAX_QUIZES], int quiz_count, int num_students);
double calcAverageScore (int scores[][MAX_QUIZES], int quiz_count, int num_students);
void printResults (int ID[], int scores[][MAX_QUIZES], int high[MAX_QUIZES], int low[MAX_QUIZES], double average[MAX_QUIZES], int 
num_students);

void getData (int ID[], int scores[][MAX_QUIZES], int* num_students) 
	{	

		int student_count=0;
		int quiz_count;

		// The grades data file is opened to fill the arrays.

		FILE* spIn;
		spIn = fopen ("myfile.dat", "r");
		if (spIn != NULL)
			{
				while (fscanf (spIn, "%d", &ID[student_count]) != EOF) 
					{
						for (quiz_count = 0; quiz_count < MAX_QUIZES; quiz_count++)
						fscanf (spIn, "%d", &scores[student_count][quiz_count]);
						student_count++;
					}//while

		*num_students = student_count;

		//student_count is stored as a pointer for num_students
	
		fclose (spIn);
			}
			else {
			puts("The file is not found.");
		getchar();
			}

		// Program exits if no spIn file found
	
	return;
				
	}//getData

int calcHiScore (int scores[][MAX_QUIZES], int quiz_count, int num_students) 
	{
		int highscore;
		int student_count;

		// highscore is the index 0 of the scores array

   		highscore = scores[0][quiz_count];
   		for (student_count = 1; student_count < num_students; student_count++)
   			{
	   			if (scores[student_count][quiz_count] > highscore)
	   			highscore = scores[student_count][quiz_count];
			}

		return highscore;			
		
	}//calcHiScore

int calcLowScore (int scores[][MAX_QUIZES], int quiz_count, int num_students)
	{
		int LowScore;
		int student_count;

		// LowScore is the index 0 of the scores array

		LowScore = scores[0][quiz_count];
		for (student_count = 1; student_count < num_students; student_count++)
			{
				if (scores[student_count][quiz_count] < LowScore)
				LowScore = scores[student_count][quiz_count];
			}	

	return LowScore;
	
	}//calcLowScore

double calcAverageScore (int scores[][MAX_QUIZES], int quiz_count, int num_students)
	{
		double sum=0;	
		sum = scores[0][quiz_count];
		int student_count;

		// AverageScore (stored as sum) is the index 0 of the scores array

		for (student_count = 1; student_count < num_students; student_count++)
			{

				sum += scores[student_count][quiz_count];		
			}	

		// The average is stored as sum

		sum = sum/num_students;
		return sum;

	}//calcAverageScore

int calculate (int scores[][MAX_QUIZES], int high[MAX_QUIZES], int low[MAX_QUIZES], double Average[MAX_QUIZES],  int num_students)
	{
		int stID;
	
		// One quiz per student	
		// The for loop calls the data and then calls the other scores arrays to fill data.

		for (stID = 0; stID < MAX_QUIZES; stID++)
			{
				high[stID]=calcHiScore(scores, stID, num_students);
				low[stID]=calcLowScore(scores, stID, num_students);
				Average[stID]=calcAverageScore(scores, stID, num_students);
			}//scoreloop
	return;

	}//calculate

void printResults (int ID[], int scores[][MAX_QUIZES], int high[MAX_QUIZES], int low[MAX_QUIZES], double 
average[MAX_QUIZES], int num_students) 
	{
		int row;
		int column;

	// Print Quiz header

	printf("Student\t\tQuiz 1  Quiz 2  Quiz 3  Quiz 4  Quiz 5\n");
	for (row = 0; row < num_students; row++)	
		{
			printf("%d\t\t", ID[row]);
			for (column = 0; column < MAX_QUIZES; column++)
			printf(" %d\t", scores[row][column]);
			printf("\n");
		}

	// Print High Score array

	printf("High Score\t");
		for (column=0; column< MAX_QUIZES; column++)
			printf(" %d\t", high[column]);
			printf("\n");

	// Print Low Score array

	printf("Low Score\t");
		for (column=0; column< MAX_QUIZES; column++)
			printf(" %d\t", low[column]);
			printf("\n");
	
	// Print Average Score array

	printf("Average\t");
		for (column=0; column< MAX_QUIZES; column++)
			printf("\t %.1lf", average[column]);
			printf("\n");

	return; 

	}//printResults

int main (void) 
	{
		int ID[MAX_STUDENTS];
		int scores[MAX_STUDENTS][MAX_QUIZES];
		int high[MAX_QUIZES];
		int low[MAX_QUIZES];
		double average[MAX_QUIZES];
		int num_students;
		int quiz_count;
		int stID;

	getData(ID, scores, &num_students);
	calculate(scores, high, low, average, num_students);
	printResults(ID, scores, high, low, average, num_students);

	return 0;

}//main
