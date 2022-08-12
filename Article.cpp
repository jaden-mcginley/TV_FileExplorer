#include "Article.h"
#include <iostream>

//constructors
Article::Article()
{
	std::list<std::string> defaultFolderPath = { "MAIN_0" };

	ID = "NULL";
	Name = "NULL";
	FolderPath = defaultFolderPath;
}

Article::Article(std::string id, std::string name, std::list<std::string> folderPath)
{
	ID = id;
	Name = name;
	FolderPath = folderPath;
}

//destructor
Article::~Article()
{

}

//mutators
void Article::Set_ID(std::string id)
{
	ID = id;
}

void Article::Set_Name(std::string name)
{
	Name = name;
}

void Article::Set_FolderPath(std::list<std::string> folderPath)
{
	FolderPath = folderPath;
}

//accessors
std::string Article::Get_ID()
{
	return ID;
}

std::string Article::Get_Name()
{
	return Name;
}

std::list<std::string> Article::Get_FolderPath()
{
	return FolderPath;
}