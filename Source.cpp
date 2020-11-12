#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <ctime>

std::string GenerateSymbols(int N) {
	std::vector<int> vectOfSymbols;
	vectOfSymbols.push_back(43);
	vectOfSymbols.push_back(45);
	vectOfSymbols.push_back(36);
	vectOfSymbols.push_back(95);
	vectOfSymbols.push_back(126);

	for (int i = 48; i <= 57; i++) {
		vectOfSymbols.push_back(i);
	}
	for (int i = 65; i <= 90; i++) {
		if (i != 67 && i != 80 && i != 83 && i != 88)
			vectOfSymbols.push_back(i);
	}
	for (int i = 97; i <= 122; i++) {
		vectOfSymbols.push_back(i);
	}

	std::string str;
	srand(time(0));
	for (int i = 0; i < N; i++) {
		int number = rand() % vectOfSymbols.size() + 0;
		str += (char)vectOfSymbols[number];
	}
	
	return str;
}

void ReplaceSymbols(std::string *strSymb, char symbol, bool flag, int *count) {
	std::string str = *strSymb;
	int number = *count;
	for (int i = 0; i < str.size(); i++) {
		int code = (int)str[i];
		if (flag) {
			if (code >= 65 && code <= 122 && code != 95) {
				str[i] = symbol;
				number++;
			}
		}
		else {
			if (code >= 48 && code <= 57) {
				str[i] = symbol;
				number++;
			}
		}
	}
	*strSymb = str;
	*count = number;
}

int main() {
	int N, countRepeatS1 = 0, countRepeatS2 = 0;
	char symbol1, symbol2;

	std::cout << "Please, input the number of symbols in string:\n";
	std::cin >> N;

	std::string randomSymbols = GenerateSymbols(N);
	std::cout << "Generated string: " << randomSymbols << std::endl;

	std::cout << "Please, input the first symbols for replace:\n";
	std::cin >> symbol1;
	ReplaceSymbols(&randomSymbols, symbol1, true, &countRepeatS1);

	std::cout << "Please, input the first symbols for replace:\n";
	std::cin >> symbol2;
	ReplaceSymbols(&randomSymbols, symbol2, false, &countRepeatS2);

	std::cout << "Result of replaces: " << randomSymbols << std::endl;
	std::cout << "Count of repeat of 1st symb: " << countRepeatS1 << "\nCount of repeat of 2nd symb: "
		<< countRepeatS2 << "\nCount of non replace symb: " << randomSymbols.size() - countRepeatS1 - countRepeatS2 << std::endl;
	return 0;
}
