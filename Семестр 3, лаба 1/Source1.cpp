#include<iostream>
#include<conio.h>
#include<locale.h>

#include "Source.cpp"

int main() {

	bool exit = false;

	while (!exit) {
		bool mean = 0;
		int length = 0, width = 0;
		try {
			std::cout << "Create the image\n\n" << "Enter the length and width of the images: ";
			std::cin >> length;
			std::cin >> width;
			std::cout << "Enter the value for the image: ";
			std::cin >> mean;
			Image picture(length, width, mean);
			std::cout << picture << "\n\n";
		}
		catch (const char* err) {
			std::cout << err << "\nДля продолжения нажмите любую кнопку.";
			system("pause");
		}
		system("cls");
		int sw;
		std::cout << "Choose:\n1. Operations with images\n2. Operations with image and value\n3. Image inversion\n4. Calculate the occupancy rate\n5. Draw rectangle\n6. Reading/writing an element\n7. Exit\n";
		std::cin >> sw;
		system("cls");
		switch (sw) {
		/*case(1):
		{
			std::cout << "Enter the length and width of the images: ";
			std::cin >> length >> width;
			std::cout << "Enter the value for the image: ";
			std::cin >> mean;
			Image picture(length, width, mean);
			double ratio = 0;
			ratio = fullness(picture);
			std::cout << "Occupancy rate  = " << ratio << "\n";
			std::cout << picture << "\n";
			system("cls");
			break;
		}*/
		case(1):
		{
			bool exit2 = false;
			bool mean2, mean1;
			std::cout << "Enter the length and width of the images: ";
			std::cin >> length >> width;
			std::cout << "Enter the value for the first image: ";
			std::cin >> mean1;
			std::cout << "Enter the value for the second image: ";
			std::cin >> mean2;
			Image picture1(length, width, mean1);
			Image picture2(length, width, mean2);
			system("cls");

			while (!exit2) {
				int sw2;
				std::cout << "Choose:\n1. Adding pictures \n2. Multiplication of images \n3. Exit\n\n";
				std::cin >> sw2;
				Image picture3 = picture1;
				Image picture4 = picture2;
				switch (sw2) {
				case(1):
				{
					std::cout << picture1 << "\n\n" << picture2 << "\n\n";
					std::cout << picture3 + picture4;
					system("cls");
					break;
				}
				case(2):
				{
					std::cout << picture1 << "\n\n" << picture2 << "\n\n";
					std::cout << picture3 * picture4;
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
		case(2):
		{
			bool value;
			std::cout << "The meaning of the variable (0 or 1): ";
			std::cin >> value;
			bool exit3 = false;
			if (value == 0) value = false;
			else value = true;
			bool mean3;
			std::cout << "Enter the length and width of the image: ";
			std::cin >> length >> width;
			std::cout << "Enter the value for the image: ";
			std::cin >> mean3;
			system("cls");
			Image picture3(length, width, mean3);
			while (!exit3) {
				int sw3;
				std::cout << "Choose:\n1. Adding a picture and a variable \n2. Multiplication a picture and a variable \n3. Adding a variable and a picture \n4. Multiplication a variable and a picture \n5. Exit\n\n";
				std::cin >> sw3;
				Image picture4 = picture3;
				switch (sw3) {
				case(1):
				{
					std::cout << "value = " << value <<"\n" << picture3 << "\n\n";
					std::cout << picture4 + value;
					system("cls");
					break;
				}
				case(2):
				{
					std::cout << "value = " << value << "\n" << picture3 << "\n\n";
					std::cout << picture4 * value;
					system("cls");
					break;
				}
				case(3):
				{
					std::cout << "value = " << value << "\n" << picture3 << "\n\n";
					std::cout << value + picture4;
					system("cls");
					break;
				}
				case(4):
				{
					std::cout << "value = " << value << "\n" << picture3 << "\n\n";
					std::cout << value * picture4;
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
		case(3):
		{
			bool mean0;
			std::cout << "Enter the length and width of the image: ";
			std::cin >> length >> width;
			std::cout << "Enter the value for the image: ";
			std::cin >> mean0;
			system("cls");
			Image picture0(length, width, mean0);
			std::cout <<"Original\n" << picture0 << "\nInversion\n" << !picture0;
			system("cls");
			break;
		}
		case(4):
		{
			bool mean0;
			std::cout << "Enter the length and width of the image: ";
			std::cin >> length >> width;
			std::cout << "Enter the value for the image: ";
			std::cin >> mean0;
			system("cls");
			Image picture0(length, width, mean0);
			int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
			std::cout << "Enter the upper left and lower right coordinates of the rectangle: ";
			std::cin >> x1 >> y1 >> x2 >> y2;
			picture0.creating_rectangle(x1, y1, x2, y2);
			double ratio = 0;
			ratio = fullness(picture0);
			std::cout << "Occupancy rate  = " << ratio << "\n" << picture0;
			system("cls");
			break;
		}
		case(5):
		{
			bool mean0;
			std::cout << "Enter the length and width of the image: ";
			std::cin >> length >> width;
			std::cout << "Enter the value for the image: ";
			std::cin >> mean0;
			system("cls");
			Image picture0(length, width, mean0);
			int x1, y1, x2, y2;
			std::cout << "Enter the coordinates of the upper left and lower right vertices of the rectangle: \n";
			std::cin >> x1 >> y1 >> x2 >> y2;
			picture0.creating_rectangle(x1, y1, x2, y2);
			std::cout << picture0;
			system("cls");
			break;
		}
		case(6):
		{
			bool value;
			int x = 0, y = 0;
			std::cout << "Enter the length and width of the images: ";
			std::cin >> length >> width;
			std::cout << "Enter the value for the image: ";
			std::cin >> mean;
			Image picture(length, width, mean);
			std::cout << picture << "\n\n";
			std::cout << "Enter the coordinates of the cell: ";
			std::cin >> x >> y;
			bool element = picture(x, y);
			std::cout << element << "\n\n";
			std::cout << "Enter the value to the cell: ";
			std::cin >> value;
			picture(x, y) = value;
			std::cout << picture(x, y) << "\n\n";
			std::cout << picture << "\n\n";
			system("cls");
			break;
		}
		case(7):
		{
			exit = true;
			break;
		}
		}
	}


	return 0;
}
