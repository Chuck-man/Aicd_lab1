#include<iostream>
#include<conio.h>
#include<locale.h>

#include "Source.cpp"

int main() {

	setlocale(LC_ALL, "ru");

	bool exit = false;

	while (!exit) {
		Image picture(10, 10);
		int sw;
		std::cout<< "��������, �� ������������� ����:\n1. ���������� �������������\n2. �������� � ����������\n3. �������� � ��������� � ���������\n4. �������� ��������\n5. ������� ��������\n6. �����\n\n";
		std::cin >> sw;
		system("cls");
		switch (sw) {
		case(1):
		{
			int x1, y1, x2, y2;
			std::cout << "������� ���������� ����� ������� � ������ ������ ������ �������������� �� ������ 10\n";
			std::cin >> x1 >> y1 >> x2 >> y2;
			picture.creating_rectangle(x1, y1, x2, y2);
			std::cout << picture;
			system("cls");
			break;
		}
		case(2):
		{
			bool exit2 = false;
			while (!exit2) {
				Image picture1(10, 10);
				Image picture2(10, 10);
				picture1.creating_rectangle(3, 2, 8, 8);
				picture2.creating_rectangle(1, 2, 5, 7);
				int sw2;
				std::cout << "��������, �� ������������� ����:\n1. �������� �������� \n2. ������������ �������� \n3. �����\n\n";
				std::cin >> sw2;
				switch (sw2) {
				case(1):
				{
					std::cout << picture1 + picture2;
					system("cls");
					break;
				}
				case(2):
				{
					std::cout << picture1 * picture2;
					system("cls");
					break;
				}
				case(3):
				{
					exit2 = true;
					break;
				}
				}
			}
			system("cls");
			break;
		}
		case(3):
		{
			bool value;
			std::cout << "�������� ���������� (0 ��� 1): ";
			std::cin >> value;
			bool exit3 = false;
			while (!exit3) {
				if (value == 0) value = false;
				else value = true;
				Image picture3(10, 10);
				picture3.creating_rectangle(3, 2, 7, 5);
				int sw3;
				std::cout << "��������, �� ������������� ����:\n1. �������� �������� � ���������� \n2. ������������ �������� � ���������� \n3. �������� ���������� � �������� \n4. ������������ ���������� � �������� \n5. �����\n\n";
				std::cin >> sw3;
				switch (sw3) {
				case(1):
				{
					std::cout << picture3 + value;
					system("cls");
					break;
				}
				case(2):
				{
					std::cout << picture3 * value;
					system("cls");
					break;
				}
				case(3):
				{
					std::cout << value + picture3;
					system("cls");
					break;
				}
				case(4):
				{
					std::cout << value * picture3;
					system("cls");
					break;
				}
				case(5):
				{
					exit3 = true;
					break;
				}
				}
			}
			break;
		}
		case(4):
		{
			std::cout << !picture;
			system("cls");
			break;
		}
		case(5):
		{
			std::cout << picture;
			system("cls");
			break;
		}
		case(6):
		{
			exit = true;
			break;
		}
		}
	}


	return 0;
}
