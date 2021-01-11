#include <iostream>
#include"Cfrac.h"
#include <conio.h>
#define ESC   27

void interface()
{
	Cfrac a;
	Cfrac b;

	char key = ' ';
	while (key != ESC)
	{
		system("cls");
		a.inputPQ();
		b.inputPQ();

		Cfrac rez;

		char _operator = ' ';

		cout << "Enter operator.\n> ";
		cin >> _operator;
		cout << "(" << a.get_p() << '/' << a.get_q() << ")"
			<< _operator << "(" << b.get_p() << '/' << b.get_q() << ")=";
		switch (_operator)
		{
		case '+':
			rez = a + b;
			rez = rez.simplifying();
			((rez.get_q() == 1) || (rez.get_q() == -1)) ? cout << rez.fraction_in_number() << endl :
				cout << rez.get_p() << '/' << rez.get_q() << endl;
			break;
		case '-':
			rez = a - b;
			rez = rez.simplifying();
			((rez.get_q() == 1) || (rez.get_q() == -1)) ? cout << rez.fraction_in_number() << endl :
				cout << rez.get_p() << '/' << rez.get_q() << endl;
			break;
		case '*':
			rez = a * b;
			rez = rez.simplifying();
			((rez.get_q() == 1) || (rez.get_q() == -1)) ? cout << rez.fraction_in_number() << endl :
				cout << rez.get_p() << '/' << rez.get_q() << endl;
			break;
		case '/':
			try
			{
				rez = a / b;
				rez = rez.simplifying();
				((rez.get_q() == 1) || (rez.get_q() == -1)) ? cout << rez.fraction_in_number() << endl :
					cout << rez.get_p() << '/' << rez.get_q() << endl;
			}
			catch (const exception& ex)
			{
				cout << ex.what() << endl;
			}

			break;
		default:
			break;
		}

		cout << "(Press \"Esc\" to exit.)\n";
		key = _getch();

	}
	

	
}