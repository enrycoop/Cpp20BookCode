//============================================================================
// Name        : simple_input.cpp
// Author      : Enrycoop
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
/* non inizializzare le variabili
 * può portare alla terminazione del programma inaspettatamente.
 * è quindi buona pratica inizializzare sempre le variabili
 */

void listnig5_1(){
	std::cout << "Enter a number: ";
	int x;
	std::cin >> x;
	std::cout << "Enter another number: ";
	int y;
	std::cin >> y;
	int z{x + y};
	std::cout << "The sum of " << x << " and " << y << " is " << z << "\n";
}

void listing5_2(){
	std::cout << "What is your name? ";
	std::string name{};
	std::cin >> name;
	std::cout << "Hello, " << name << ", how are you? ";
	std::string response{};
	std::cin >> response;
	std::cout << "Good-bye, " << name << ". I'm glad you feel " << response << "\n";
}

void listing5_3(){
	std::cout << "What is your name? ";
	std::string name{};
	std::cin >> name;
	std::cout << "Hello, " << name << ", how old are you? ";
	int age{};
	std::cin >> age;
	std::cout << "Good-bye, " << name << ". You are " << age << " year";
	if (age > 1)
		std::cout <<"'s";
	std::cout << " old. \n";
}

void listing5_3_1()
{
	std::cout << "How old are you? ";
	int age{};
	std::cin >> age;
	std::cout << "What's your name?  ";
	std::string name{};
	std::cin >> name;
	std::cout << "Good-bye, " << name << ". You are " << age << " year";
	if (age > 1)
		std::cout <<"'s";
	std::cout << " old. \n";
}



int main() {
	listing5_3_1();

	return 0;
}
