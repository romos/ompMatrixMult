// ompmult.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


bool omp_support() {
#ifdef _OPENMP
	return true;
#else
	return false;
#endif
}

int** createMatrix(int rows, int cols) {
	int** matrix = new int*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}
	return matrix;
}
void zeroInitMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = 0;
		}
	}
}
void randFillMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
}
void deleteMatrix(int** matrix, int rows) {
	for (int r = 0; r < rows; ++r) {
		delete[] matrix[r];
	}
	delete[] matrix;
}

void printMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	// check the number of arguments
	if (argc != 5) {
		printf("Program needs 4 integer arguments divided by space: M1.rows M1.columns M2.rows M2.columns\n");
		return 1;
	}
	// check if OpenMP is available
	if (!omp_support()) {
		printf("Unfortunately, OpenMP is not available.\n");
		return 1;
	}

	//Define matrices
	int rows1 = atoi(argv[1]);
	int cols1 = atoi(argv[2]);
	int rows2 = atoi(argv[3]);
	int cols2 = atoi(argv[4]);
	int **matrix1, **matrix2;

	if (cols1 != rows2) {
		printf("Program needs 4 integer arguments divided by space: M1.rows M1.columns M2.rows M2.columns\nUnfortunately, you've entered wrong matrix size:\n\tM1.columns must be equal to M2.rows!\n");
		return 1;
	}

	int rows3 = rows1;
	int cols3 = cols2;
	int** matrix3;

	srand(time(NULL));

	//omp_set_nested(1);

#pragma omp parallel
	{
#pragma omp sections
	{
#pragma omp section
	{
		//create the first matrix
		matrix1 = createMatrix(rows1, cols1);
	}
#pragma omp section
	{
		//create the second matrix
		matrix2 = createMatrix(rows2, cols2);
	}
#pragma omp section
	{
		//create the third/multiplication matrix
		matrix3 = createMatrix(rows3, cols3);
	}
	}

#pragma omp sections
	{
#pragma omp section
	{
		//fill the first matrix
		randFillMatrix(matrix1, rows1, cols1);
	}
#pragma omp section
	{
		//fill the second matrix
		randFillMatrix(matrix2, rows2, cols2);
	}
#pragma omp section
	{
		//fill the second matrix
		zeroInitMatrix(matrix3, rows3, cols3);
	}
	}
	}

	auto start_time = omp_get_wtime();

#pragma omp parallel for
	for (int r = 0; r < rows1; r++) {
		for (int c = 0; c < cols2; c++) {
			for (int i = 0; i < cols1; i++) {
				matrix3[r][c] = matrix3[r][c] + matrix1[r][i] * matrix2[i][c];
			}
		}
	}

	auto run_time = omp_get_wtime() - start_time;
	printf("parallel,%s,%s,%s,%s,%f\n", argv[1], argv[2], argv[3], argv[4], run_time);

	//#pragma omp barrier
#pragma omp parallel
	{

#pragma omp sections
	{
#pragma omp section
	{
		//delete the first matrix
		deleteMatrix(matrix1, rows1);
	}
#pragma omp section
	{
		//delete the second matrix
		deleteMatrix(matrix2, rows2);
	}
#pragma omp section
	{
		//delete the third (multiplication) matrix
		deleteMatrix(matrix3, rows3);
	}
	}
	}

	return 0;
}
