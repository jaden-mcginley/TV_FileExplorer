/*
	File Name: Article.h
	Summary: A header file for an Article class.
	Author: Jaden McGinley
	Created: May 5, 2022
	Summary of Modifications:
		May 5, 2022 - JM - created the program
	Summary of Functions:
		Constructors:
			Article():
				Summary
			Article(params):
				Summary
		Destructors:
			~Article():
				Summary
		Mutators:
			void set_Parameter(param):
				Summary
		Accessors:
			paramType get_Parameter():
				Summary
		Others:
			FUNCTION:
				Summary
*/
#ifndef ARTICLE_H
#define ARTICLE_H
#pragma once

#include <iostream>
#include <list>

class Article
{
public:
	//constructors
	Article();
	Article(std::string id, std::string name, std::list<std::string> folderPath);

	//destructor
	~Article();

	//mutators
	void Set_ID(std::string id);
	void Set_Name(std::string name);
	void Set_FolderPath(std::list<std::string> folderPath);

	//accessors
	std::string Get_ID();
	std::string Get_Name();
	std::list<std::string> Get_FolderPath();

private:
	std::string ID;
	std::string Name;
	std::list<std::string> FolderPath; // 0:[ARTICLE_X.GetID()] 1:[ARTICLE_XX.GetID()] 2:[ARTICLE_XXX.GetID()] ETC...
									   // ↳ Represents depth		   ↳ Represents file
};

#endif // !ARTICLE_H