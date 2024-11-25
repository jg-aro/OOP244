/* Citation and Sources...
Final Project Milestone 2
Module: Utils
Filename: Utils.h
Version 1.0
Author	Jasmin Aro
Revision History
-----------------------------------------------------------
Date        Reason
2024/11/21
-----------------------------------------------------------
see Menu.h
-----------------------------------------------------------*/

#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
#include <iostream>
#include "constants.h"
namespace seneca {
    class Utils {
    public:
        char* alocpy(const char* src)const;
        char* alocpy(char*& des, const char* src)const;
        char* strcpy(char* des, const char* src)const;
        int strlen(const char* str)const;
        bool isspace(char ch)const;
        bool isspace(const char* cstring)const;
        int getInt();
        int getInt(int min, int max);
    };
    extern Utils ut;   
    // makes the ut object available where Utils.h is included
    // to call a Utils function call it as follows
    // ut.strcpy(des, src);
	
}


#endif // !SENECA_UTILS_H