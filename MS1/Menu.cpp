/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Jasmin Aro
Revision History
-----------------------------------------------------------
Date		Reason
2024/11/12  Correct output reached
-----------------------------------------------------------
I have done most coding by myself, with use of ChatGPT for
debugging inquiries, specifically regarding namespaces. I had trouble
with understanding why the header needed std:: and the .cpp file
did not. I now understand that the header file is not using the namespace
std, so there needed to be manual accessing. File constants.h also
used ChatGPT to see why size_t was not initializing properly (included
cstddef).
-----------------------------------------------------------*/

#include <iostream>
#include "Menu.h"
#include "constants.h"
#include "Utils.h"

using namespace std;
namespace seneca {
	MenuItem::MenuItem() {
		m_content = nullptr;
		setEmpty();
	}
	
	void MenuItem::setEmpty() {
		if (!(m_content == nullptr)) {
			ut.strcpy(m_content, "");
		}
		m_indent = 0u;
		m_indentSize = 0u;
		m_rowNumber = 0;
	}

	MenuItem::MenuItem(const char* content, int indent, int indentSize, int rowNumber) {
		if (rowNumber < 0) {
			if (!(content == nullptr || indent > 4 || indentSize > 4))
			{
				m_content = new char[ut.strlen(content) + 1];
				ut.alocpy(m_content, content);
				m_indent = indent;
				m_indentSize = indentSize;
				m_rowNumber = rowNumber;
			}
		}
		else if (!(content == nullptr || indent > 4 || indentSize > 4))
		{
			m_content = new char[ut.strlen(content) + 1];
			ut.alocpy(m_content, content);
			m_indent = indent;
			m_indentSize = indentSize;
			m_rowNumber = rowNumber;
		}
		else if (rowNumber < 0)
		{

		}
		else
		{
			setEmpty();
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_content;
	}

	//ostream& returns a reference to the output stream.
	//its the datatype.
	ostream& MenuItem::display(ostream& ostr) const //appending const to the function enables the function itself to be constant - NOTHING gets changed
	{	
		if (m_content!= nullptr) {
			int indent = m_indent;
			int indentSize = m_indentSize;
			if (m_rowNumber >= 0 && m_rowNumber < 10)
			{
				for (int i = 0; i < indent * indentSize+1;i++)
				{
					ostr << " ";
				}
				ostr << m_rowNumber << "- ";
			}
			else if (m_rowNumber >= 0 && m_rowNumber >= 10) {
				for (int i = 0; i < indent * indentSize;i++)
				{
					ostr << " ";
				}
				ostr << m_rowNumber << "- ";
			}
			const char* content = m_content;
			while (isspace(*content)) {
				content++;  
			}
			ostr << content;
		}
		else {
			ostr << "??????????";
		}

		return ostr;
	}
	ostream& MenuItem::display() const {
		return display(cout);
	}

	//checks validity of the MenuItem object. returns true if valid
	bool MenuItem::isValid() const
	{
		return !(m_content == nullptr || isspace(*m_content) || m_indent > 4 || m_indentSize > 4);
	}

	MenuItem::operator bool() const
	{
		return isValid();
	}

}