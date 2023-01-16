#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>

class passwordGenerator
{
public:
	passwordGenerator();
	~passwordGenerator();
	void displayMessage();
	void passGenerator(int passlenght);
	void numOfChars(int passlenght);
	
private:
	int numOfUpperChars=0;
	int numOfLowerChars=0;
	int numOfNumbers=0;
	char* password;
};

passwordGenerator::passwordGenerator()
{
}

passwordGenerator::~passwordGenerator()
{
	std::cout << "\ndestr";
}

void passwordGenerator::displayMessage()
{
	int passLenght;
	int numOfPasswords;
	//char* filename = new char;
	std::cout << "enter length of password: ";
	std::cin >> passLenght;
	std::cout << "enter number of passwords: ";
	std::cin >> numOfPasswords;
	//std::cout << "Введите имя файла для записи: ";
	//std::cin >> filename;
	std::ofstream outfile("C:\\passwords.txt");
	if (!outfile) exit(1);
	
	for (int k = 0; k < numOfPasswords; k++)
	{
		for (int i = 0; i < passLenght; ++i)
		{
			numOfChars(passLenght);
			passGenerator(passLenght);
			outfile << password[i];
		}
		outfile << std::endl;
	}
	outfile.close();
	std::cout << "done";
}

void passwordGenerator::passGenerator(int passlenght)
{
	password = new char[passlenght];
	for (int i = 0; i < numOfNumbers; ++i)
		password[i] = char(rand() % 10 + 48);
	for (int i = numOfNumbers; i < numOfNumbers + numOfUpperChars; ++i)
		password[i] = char(rand() % 26 + 65);
	for (int i = numOfNumbers + numOfUpperChars; i < passlenght; ++i)
		password[i] = char(rand() % 26 + 97);
	std::random_shuffle(password, password + passlenght);

}

void passwordGenerator::numOfChars(int passlenght)
{
	numOfLowerChars = rand() % passlenght;
	int charRandEnd = passlenght - numOfLowerChars;
	numOfUpperChars = rand() % charRandEnd;
	numOfNumbers = passlenght - numOfLowerChars - numOfUpperChars;
}

int main()
{   

	srand(time(NULL));
	passwordGenerator* genMe=new passwordGenerator;
	genMe->displayMessage();
	
    std::cout << std::endl;
	return 0;
}
