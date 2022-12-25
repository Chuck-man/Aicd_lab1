#include<iostream>
#include<conio.h>
#include "Source.cpp"

int main() {

	bool exit = false;

	while (!exit) {
		bool mean = 0;
		int length = 0, width = 0;
		int sw;
		std::cout << "\nChoose:\n1. Create the image\n2. Operations with images\n3. Operations with image and value\n4. Image inversion\n5. Calculate the occupancy rate\n6. Draw rectangle\n7. Reading/writing an element\n8. Exit\n";
		std::cin >> sw;
		switch (sw) {
		case(1):
		{
			std::cout << "Create the image\n\n" << "Enter the length and width of the images: ";
			std::cin >> length;
			std::cin >> width;
			std::cout << "Enter the value for the image: ";
			std::cin >> mean;
			try {
				Image picture(length, width, mean);
				std::cout << picture << "\n\n";
			}
			catch (std::logic_error& err) {
				std::cerr << err.what() << std::endl;
			}
			break;
		}
		case(2):
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
			while (!exit2) {
				int sw2;
				std::cout << "Choose:\n1. Adding pictures \n2. Multiplication of images \n3. Exit\n\n";
				std::cin >> sw2;

				switch (sw2) {
				case(1):
				{
					std::cout << picture1 << "\n\n" << picture2 << "\n\n";
					std::cout << picture1 + picture2;
					break;
				}
				case(2):
				{
					std::cout << picture1 << "\n\n" << picture2 << "\n\n";
					std::cout << picture1 * picture2;
					break;
				}
				case(3):
				{
					exit2 = true;
					break;
				}
				}
			}
			break;
		}
		case(3):
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
			Image picture3(length, width, mean3);
			while (!exit3) {
				int sw3;
				std::cout << "Choose:\n1. Adding a picture and a variable \n2. Multiplication a picture and a variable \n3. Adding a variable and a picture \n4. Multiplication a variable and a picture \n5. Exit\n\n";
				std::cin >> sw3;
				switch (sw3) {
				case(1):
				{
					std::cout << "value = " << value <<"\n" << picture3 << "\n\n";
					std::cout << picture3 + value;
					break;
				}
				case(2):
				{
					std::cout << "value = " << value << "\n" << picture3 << "\n\n";
					std::cout << picture3 * value;
					break;
				}
				case(3):
				{
					std::cout << "value = " << value << "\n" << picture3 << "\n\n";
					std::cout << value + picture3;
					break;
				}
				case(4):
				{
					std::cout << "value = " << value << "\n" << picture3 << "\n\n";
					std::cout << value * picture3;
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
			bool mean0;
			std::cout << "Enter the length and width of the image: ";
			std::cin >> length >> width;
			std::cout << "Enter the value for the image: ";
			std::cin >> mean0;
			Image picture0(length, width, mean0);
			std::cout <<"Original\n" << picture0 << "\nInversion\n" << !picture0;
			break;
		}
		case(5):
		{
			bool mean0 = 0;
			std::cout << "Enter the length and width of the image: ";
			std::cin >> length >> width;
			Image picture0(length, width, mean0);
			int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
			std::cout << "Enter the upper left and lower right coordinates of the rectangle: ";
			std::cin >> x1 >> y1 >> x2 >> y2;
			picture0.creating_rectangle(x1, y1, x2, y2);
			double ratio = 0;
			ratio = fullness(picture0);
			std::cout << "Occupancy rate  = " << ratio << "\n" << picture0;
			break;
		}
		case(6):
		{
			bool mean0 = 0;
			std::cout << "Enter the length and width of the image: ";
			std::cin >> length >> width;
			Image picture0(length, width, mean0);
			int x1, y1, x2, y2;
			std::cout << "Enter the coordinates of the upper left and lower right vertices of the rectangle: \n";
			std::cin >> x1 >> y1 >> x2 >> y2;
			try {
				picture0.creating_rectangle(x1, y1, x2, y2);
				std::cout << picture0;
			}
			catch (std::logic_error& err) {
				std::cerr << err.what() << std::endl;
			}
			break;
		}
		case(7):
		{
			bool value, element;
			int x = 0, y = 0;
			std::cout << "Enter the length and width of the images: ";
			std::cin >> length >> width;
			std::cout << "Enter the value for the image: ";
			std::cin >> mean;
			Image picture(length, width, mean);
			std::cout << picture << "\n\n";
			std::cout << "Enter the coordinates of the cell: ";
			std::cin >> x >> y;
			try {
				element = picture(x, y);
				std::cout << element << "\n\n";
				std::cout << "Enter the value to the cell: ";
				std::cin >> value;
				picture(x, y) = value;
				std::cout << picture(x, y) << "\n\n";
				std::cout << picture << "\n\n";
			}
			catch (std::logic_error& err) {
				std::cerr << err.what() << std::endl;
			}
			break;
		}
		case(8):
		{
			exit = true;
			break;
		}
		}
	}


	return 0;
}
