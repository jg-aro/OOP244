/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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
#include "Menu.h"
#include "Utils.h"
#include "constants.h"
using namespace std;
namespace seneca {
	//Sets all member variables of MenuItem to safe empty state
	void MenuItem::setEmpty()
	{
		if (!(m_content == nullptr)) {
			ut.strcpy(m_content, "");
		}
		m_indent = 0u;
		m_indentSize = 0u;
		m_rowNumber = 0;
	}

	//Checks validity of the MenuItem object. Returns true if valid.
	bool MenuItem::isValid() const
	{
		return !(m_content == nullptr || isspace(*m_content) || m_indent > 4 || m_indentSize > 4);
	}

	//Constructor for MenuItem class
	//Sets all member variables to safe empty state
	MenuItem::MenuItem()
	{
		
	}

	//Rewrites the MenuItem class to the arguments of const char cstring, int indent, int indentSize, int rowNumber
	//Must meet the condition: content != nullptr, indent > 4, indentSize > 4, rowNumber <= MaxItemNumber
	MenuItem::MenuItem(const char* content, int indent, int indentSize, int rowNumber)
	{
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
			;
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

	//Recieve no arguments
	//Return an output stream from overloaded function
	ostream& MenuItem::display() const
	{
		return display(cout, true);
	}

	//Takes the output stream as an argument and writes into it
	//Returns the output stream. isNotItem determines whether it will display a title/selprompt
	ostream& MenuItem::display(std::ostream& ostr, bool isNotItem) const {
		if (m_content != nullptr) {
			ostr << std::string(m_indent * m_indentSize, ' ');
			if (!isNotItem && m_rowNumber >= 0) {
				if (m_rowNumber < 10) {
					ostr <<" " << m_rowNumber << "- ";
				}
				else {
					ostr << m_rowNumber << "- ";
				}
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

	MenuItem::operator bool() const
	{
		return isValid();
	}

	///MILESTONE 2 START

	//init Menu. handles nullptr title
	Menu::Menu(const char* title, const char* exitContent, unsigned int indent, unsigned int indentSize)
		: m_title(title ? title : "", indent, indentSize, 0),
		m_exitOption(exitContent, indent, indentSize, 0),
		m_selPrompt("> ", indent, indentSize, 0),
		m_indentNum(indent),
		m_indentSize(indentSize),
		m_itemNum(0) {
		for (auto& item : m_items) {
			item = nullptr;
		}
	}


	Menu& Menu::operator<<(const char* menuItemContent) {
		if (m_itemNum < MaximumNumberOfMenuItems) {
			m_items[m_itemNum] = new MenuItem(menuItemContent, static_cast<int>(m_indentNum), static_cast<int>(m_indentSize), static_cast<int>(m_itemNum +1));
			++m_itemNum;
		}
		return *this;
	}

	Menu::~Menu() {
		for (auto& item : m_items) {
			delete item;
			item = nullptr;
		}
	}

	size_t operator<<(std::ostream& ostr, const Menu& menu) {
		if (&ostr == &std::cout) {
			return menu.select();
		}
		return 0;
	}

	size_t Menu::select() const {
		//title
		if (ut.strlen(m_title.m_content) > 0) {
			m_title.display(std::cout, true) << std::endl;
		}
		//item
		for (size_t i = 0; i < m_itemNum; ++i) {
			if (m_items[i]) {
				m_items[i]->display(std::cout, false) << std::endl;
			}
		}
		//exit
		if (m_exitOption) {
			m_exitOption.display(std::cout, false) << std::endl; 
		}
		//sel
		m_selPrompt.display(std::cout, true);

		return ut.getInt(0, static_cast<int>(m_itemNum));
	}


}