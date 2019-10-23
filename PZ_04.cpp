

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

int askNumber(int high, int low = 1);
float AppTwo(std::string = "Enter your a number : ");
float AppTwo2(std::string);
float AppTwo2();
void AppThree(float, float);
float Salary(float, float);
float Tax(float, float);
int AppFour(int, int);

enum PressKeys
{
	Key_1 = 0x31,
	Key_2 = 0x32,
	Key_3 = 0x33,
	Key_4 = 0x34,
	Key_Q = 0x71
};


int main()
{
	short q = 0;
	bool game = true;

	float allSalary = 0.0f;
	float tax = 0.0f;
	unsigned int n;
	unsigned int k;
	unsigned int n1;
	unsigned int k1;

	std::string a = " ";

	std::cout << "Please choose a application.\n";
	std::cout << "Press: [1] - for you see the error.\n";
	std::cout << "       [2] - for //.\n";
	std::cout << "       [3] - for salary ($) and tax (%).\n";
	std::cout << "       [4] - for k numbers from N number.\n";
	std::cout << "       [Q] - for Quit from application.\n\n";

	do
	{
		q = _getch();
		switch (q)
		{
			case Key_1:
				askNumber(1);

				break;

			case Key_2:
				AppTwo();
				AppTwo("Enter your a number: ");
				AppTwo2();
				AppTwo2("Enter your a number: ");
				AppTwo2();
				std::cout << std::endl;

				break;

			case Key_3:
				std::cout << "\nEnter all salary ($) and tax (%): ";
				std::cin >> allSalary >> tax;
				AppThree(allSalary, tax);

				break;

			case Key_4:
				std::cout << "Enter a number N (1-999999999): ";
				std::cin >> n1;
				std::cout << "Enter k: ";
				std::cin >> k1;
				std::cout << "Your number: " << AppFour(n1, k1) << std::endl << std::endl;

				break;

			case Key_Q:
				game = false;
				exit(0);

				break;
		}
	} while (game);
	

	system("pause");
    return 0;
}

int askNumber(int high, int low)
{
	std::cout << "int askNumber(int low = 1. int high); --> int askNumber(int high, int low = 1);\n" << std::endl;

	return 0;
}

float AppTwo(std::string string1)
{
	float number = 0;
	std::cout << string1;
	std::cin >> number;

	return number;
}

float AppTwo2(std::string string1)
{
	if (string1.empty())
	{
		return AppTwo2();
	}
	else
	{
		float number = 0;
		std::cout << string1 << " ";
		std::cin >> number;

		return number;
	}
}

float AppTwo2()
{
	float number = 0;
	std::cout << "Enter your a number : ";
	std::cin >> number;

	return number;
}

void AppThree(float salary, float tax)
{
	std::cout << "all salary: " << salary << " $" << std::endl;
	std::cout << "tax: " << tax << "% = " << Tax(salary, tax) << " $" << std::endl;
	std::cout << "your salary " << Salary(salary, tax) << std::endl << std::endl;
}

int AppFour(int n, int k)
{
	int N = n;
	int counter = 0;
	int temp = 10;

	while (N)
	{
		N /= 10;
		counter++;
	}

	for (int i = 0; i < (counter - k - 1); i++)
	{
		temp *= 10;
	}

	//std::cout << "Your number: " << (n /= temp) << std::endl << std::endl;

	return (n /= temp);
}

float Salary(float salary, float tax)
{
	return salary - (salary * (tax / 100));
}

float Tax(float salary, float tax)
{
	return salary * (tax / 100);
}
