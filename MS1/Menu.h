/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.1
Author	Jasmin Aro
Revision History
-----------------------------------------------------------
Date		Reason
2024/11/12  Correct output reached
2024/11/12  Clean up
-----------------------------------------------------------
I have done most coding by myself, with use of ChatGPT for
debugging inquiries, specifically regarding namespaces. I had trouble
with understanding why the header needed std:: and the .cpp file
did not. I now understand that the header file is not using the namespace
std, so there needed to be manual accessing.
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>

namespace seneca {
   class MenuItem {
	   char* m_content = nullptr;
	   size_t m_indent = 0;
	   size_t m_indentSize = 0;
	   int m_rowNumber = 0;
	   void setEmpty();
	   bool isValid()const;
   public:
	   MenuItem();
	   MenuItem(const char* content, int indent, int indentSize, int rowNumber);
	   ~MenuItem();
	   MenuItem(const MenuItem&) = delete;
	   MenuItem& operator=(MenuItem&) = delete;
	   std::ostream& display() const;
	   std::ostream& display(std::ostream& ostr) const;
	   operator bool() const;
   };
}
#endif // !SENECA_MENU_H


