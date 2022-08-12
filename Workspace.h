/*
	File Name: Workspace.h
	Summary: A header file for a Workspace class.
	Author: Jaden McGinley
	Created: May 5, 2022
	Summary of Modifications:
		May 5, 2022 - JM - created the program
	Summary of Functions:
		Constructors:
			Workspace():
				Summary
			Workspace(params):
				Summary
		Destructors:
			~Workspace():
				Summary
		Mutators:
			void set_Parameter(param):
				Summary
		Accessors:
			paramType get_Parameter():
				Summary
*/
#ifndef WORKSPACE_H
#define WORKSPACE_H
#pragma once

#include "Article.h"
#include <iostream>
#include <list>

class Workspace
{
public:
	//constructors
	Workspace();
	Workspace(std::string id, std::string name, std::string mainFolder, std::string deleteFolder);

	//destructor
	~Workspace();

	//mutators
	void Set_ID(std::string id);
	void Set_Name(std::string name);
	void Set_ArticleMasterList(std::list<Article> articleMasterList);
	void Set_ArticleDeletionList(std::list<Article> articleDeletionList);
	void Set_CurrentFolderPath(std::list<std::string> currentFolderPath);

	//accessors
	std::string Get_ID();
	std::string Get_Name();
	std::list<Article> Get_ArticleMasterList();
	std::list<Article> Get_ArticleDeletionList();
	std::list<std::string> Get_CurrentFolderPath();

	//others
	Article Identify_Article(std::list<Article> articleMasterList, std::list<std::string> folderPath, std::string id);
	std::string Create_ArticleID(size_t length, std::list<Article> articleMasterList);
	void Create_Article(std::list<Article> articleMasterList, std::string id, std::string name, std::list<std::string> folderPath);
	void Delete_Article(std::list<Article> articleMasterList, std::list<Article> articleDeletionList, std::list<std::string> folderPath, std::string id);
	void Print_DirectoryContents(std::list<Article> articleMasterList, std::list<std::string> folderPath);

private:
	std::string ID;
	std::string Name;

	std::string MainFolder;
	std::string DeleteFolder;

	std::list<Article> ArticleMasterList;
	std::list<Article> ArticleDeletionList;
	std::list<std::string> CurrentFolderPath;
};

#endif // !WORKSPACE_H