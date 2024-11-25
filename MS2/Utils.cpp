/* Citation and Sources...
Final Project Milestone 2
Module: Utils
Filename: Utils.cpp
Version 1.0
Author	Jasmin Aro
Revision History
-----------------------------------------------------------
Date        Reason
2024/11/21
-----------------------------------------------------------
see Menu.h
-----------------------------------------------------------*/

#include <iostream>
#include "Utils.h"
#include "constants.h"

using namespace std;
namespace seneca {

	Utils ut;

	char* Utils::alocpy(const char* src) const {
		char* des{};
		return alocpy(des, src);
	}

	char* Utils::alocpy(char*& des, const char* src)const {
		delete[] des;
		des = nullptr;
		if (src) {
			des = new char[strlen(src) + 1];
			strcpy(des, src);
		}
		return des;
	}
	char* Utils::strcpy(char* des, const char* src)const {
		int i;
		for (i = 0; src[i]; i++) des[i] = src[i];
		des[i] = char(0);
		return des;
	}
	int Utils::strlen(const char* str)const {
		int len;
		for (len = 0; str[len]; len++);
		return len;
	}

	bool Utils::isspace(char ch)const {
		return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
	}

	bool Utils::isspace(const char* cstring) const {
		while (cstring && isspace(*cstring)) {
			cstring++;
		}
		return cstring && *cstring == 0;
	}

	int Utils::getInt() {
		int value;
		while (true) {
			cin >> value;
			if (cin.fail()) {
				cin.clear(); 
				cin.ignore(10000, '\n');
				cout << "Invalid input.\n> ";
			}
			else {
				cin.ignore(10000, '\n');  
				return value; 
			}
		}
	}

	int Utils::getInt(int min, int max) {
		int value;
		while (true) {
			value = getInt(); 
			if (value >= min && value <= max) {
				return value;
			}
			else {
				
				cout << "Invalid value. Min: " << min << " Max: " << max << "\n> ";
			}
		}
	}

}