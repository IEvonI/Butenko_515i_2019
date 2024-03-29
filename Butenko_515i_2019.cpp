#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

int menu()
{
	int command;
marker1:;
	printf(	"1 -  The line passes through the origin\n"
			"2 - The line does not pass through the origin\n");
	printf("Command:");
	scanf("%i", &command);
	if (command > 2)
	{
		system("cls");
		printf("Retype command!!");
		system("pause");
		goto marker1;
	}
	if (command < 1)
	{
		system("cls");
		printf("Retype command!!");
		system("pause");
		goto marker1;
	}
	return command;
}

double Ugl_koef(float A, float B)
{
	double k;
	k = -A / B;
	return k;
}

float Per_S_Os(float A, float B, float C)
{
	float X;
	X = (-C / A);
	return X;
}
int main()
{

	float X_cord,Y_cord,A_koef, B_koef, C_koef;
	float X_per, Y_per = 0;
	double Koef_Pov;
	double turn_matr_base[2][2], turn_matr_back[2][2], result_matr[2][2],start_point[2],result_point[2];
	int command;
	command = menu();
	printf("Enter the coordinates of the original point:\n");
	printf("X = ");
	scanf("%f", &X_cord);
	printf("Y = ");
	scanf("%f", &Y_cord);
	start_point[0] = X_cord;
	start_point[1] = Y_cord;
	if (command == 2)
	{
		printf("Enter coefficients to form a straight line equation. Ax + By + C = 0\n");
		printf("A = ");
		scanf("%f", &A_koef);
		printf("B = ");
		scanf("%f", &B_koef);
		printf("C = ");
		scanf("%f", &C_koef);
		if (A_koef*X_cord + B_koef * Y_cord + C_koef == 0)
		{
			printf("Reflection is impossible because that the point lies on line");
			exit(1);
		}
		Koef_Pov = Ugl_koef(A_koef, B_koef);
		X_per = Per_S_Os(A_koef, B_koef, C_koef);

		turn_matr_base[0][0] = cos(Koef_Pov);
		turn_matr_base[0][1] = sin(Koef_Pov);
		turn_matr_base[1][0] = sin(Koef_Pov);
		turn_matr_base[1][1] = -cos(Koef_Pov);

		turn_matr_back[0][0] = cos(Koef_Pov);
		turn_matr_back[0][1] = sin(Koef_Pov);
		turn_matr_back[1][0] = -sin(Koef_Pov);
		turn_matr_back[1][1] = cos(Koef_Pov);

		start_point[0] = start_point[0] - X_per;

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				result_matr[i][j] = 0;
				for (int k = 0; k < 2; k++)
					result_matr[i][j] += turn_matr_base[i][k] * turn_matr_back[k][j];
			}

		result_point[0] = (start_point[0] * result_matr[0][0]) + start_point[1] * result_matr[0][1];
		result_point[1] = (start_point[0] * result_matr[1][0]) + start_point[1] * result_matr[1][1];

		result_point[0] = result_point[0] + X_per;
	}
	if (command == 1)
	{
		printf("Enter coefficients to form a straight line equation. Ax + By = 0\n");
		printf("A = ");
		scanf("%f", &A_koef);
		printf("B = ");
		scanf("%f", &B_koef);
		if (A_koef*X_cord + B_koef * Y_cord == 0)
		{
			printf("Reflection is impossible because that the point lies on line");
			exit(1);
		}
		if (A_koef == 0)
		{
			result_point[0] = X_cord;
			result_point[1] = -Y_cord;
			printf("Coordinates of the new point:\n");
			printf("(%f,%f)", result_point[0], result_point[1]);
			system("pause");
			return 0;
		}
		if (B_koef == 0)
		{
			result_point[0] = -X_cord;
			result_point[1] = Y_cord;
			printf("Coordinates of the new point:\n");
			printf("(%f,%f)", result_point[0], result_point[1]);
			system("pause");
			return 0;
		}
		Koef_Pov = Ugl_koef(A_koef, B_koef);

		turn_matr_base[0][0] = cos(Koef_Pov);
		turn_matr_base[0][1] = sin(Koef_Pov);
		turn_matr_base[1][0] = sin(Koef_Pov);
		turn_matr_base[1][1] = -cos(Koef_Pov);

		turn_matr_back[0][0] = cos(Koef_Pov);
		turn_matr_back[0][1] = sin(Koef_Pov);
		turn_matr_back[1][0] = -sin(Koef_Pov);
		turn_matr_back[1][1] = cos(Koef_Pov);

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				result_matr[i][j] = 0;
				for (int k = 0; k < 2; k++)
					result_matr[i][j] += turn_matr_base[i][k] * turn_matr_back[k][j];
			}

		result_point[0] = (start_point[0] * result_matr[0][0]) + start_point[1] * result_matr[0][1];
		result_point[1] = (start_point[0] * result_matr[1][0]) + start_point[1] * result_matr[1][1];
	}
	printf("Coordinates of the new point:\n");
	printf("(%f,%f)", result_point[0],result_point[1]);
	system("pause");
	return 0;
}