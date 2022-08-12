#include "Workspace.h"
#include <iostream>
#include <ctime>
#include <algorithm>

//constructors
Workspace::Workspace()
{
	ID = 1;
	Name = "NULL";

	MainFolder = "MAIN_0";
	DeleteFolder = "DELETE_0";

	std::list<Article> articleMasterList;
	std::list<Article> articleDeletionList;
	std::list<std::string> currentFolderPath = { MainFolder };

	ArticleMasterList = articleMasterList;
	ArticleDeletionList = articleDeletionList;
	CurrentFolderPath = currentFolderPath;
}

Workspace::Workspace(std::string id, std::string name, std::string mainFolder, std::string deleteFolder)
{
	ID = id;
	Name = name;

	MainFolder = mainFolder;
	DeleteFolder = deleteFolder;

	std::list<Article> articleMasterList;
	std::list<Article> articleDeletionList;
	std::list<std::string> currentFolderPath = { MainFolder };

	ArticleMasterList = articleMasterList;
	ArticleDeletionList = articleDeletionList;
	CurrentFolderPath = currentFolderPath;
}

//destructor
Workspace::~Workspace()
{

}

//mutators
void Workspace::Set_ID(std::string id)
{
	ID = id;
}

void Workspace::Set_Name(std::string name)
{
	Name = name;
}

void Workspace::Set_ArticleMasterList(std::list<Article> articleMasterList)
{
	ArticleMasterList = articleMasterList;
}

void Workspace::Set_ArticleDeletionList(std::list<Article> articleDeletionList)
{
	ArticleDeletionList = articleDeletionList;
}

void Workspace::Set_CurrentFolderPath(std::list<std::string> currentFolderPath)
{
	CurrentFolderPath = currentFolderPath;
}

//accessors
std::string Workspace::Get_ID()
{
	return ID;
}

std::string Workspace::Get_Name()
{
	return Name;
}

std::list<Article> Workspace::Get_ArticleMasterList()
{
	return ArticleMasterList;
}

std::list<Article> Workspace::Get_ArticleDeletionList()
{
	return ArticleDeletionList;
}

std::list<std::string> Workspace::Get_CurrentFolderPath()
{
	return CurrentFolderPath;
}

//others
Article Workspace::Identify_Article(std::list<Article> articleMasterList, std::list<std::string> folderPath, std::string id) //ADD DELETION LIST INTEGRATION
{
	for (Article article : articleMasterList)
	{
		if (article.Get_ID() == id && article.Get_FolderPath() == folderPath)
		{
			return article;
		}
	}
}

std::string Workspace::Create_ArticleID(size_t length, std::list<Article> articleMasterList)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};

	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);

	for (Article article : articleMasterList)
	{
		if (str == article.Get_ID())
		{
			Create_ArticleID(length, articleMasterList);
		}
	}

	return str;
}

void Workspace::Create_Article(std::list<Article> articleMasterList, std::string id, std::string name, std::list<std::string> folderPath)
{
	Article *article = new Article(id, name, folderPath);
	articleMasterList.push_back(*article);
	Set_ArticleMasterList(articleMasterList);
	delete article;
}

void Workspace::Delete_Article(std::list<Article> articleMasterList, std::list<Article> articleDeletionList, std::list<std::string> folderPath, std::string id)
{
	std::list<std::string> temporaryArticlePath;
	std::list<std::string> deleteFolderPath = { DeleteFolder };

	std::list<std::string> originalArticlePath = folderPath;
	originalArticlePath.push_back(id);

	for (Article article : articleMasterList)
	{
		temporaryArticlePath = article.Get_FolderPath();

		if (temporaryArticlePath.size() >= originalArticlePath.size())
		{
			std::list<std::string>::iterator it = temporaryArticlePath.begin(); //creates the iterator of the temporary list at 0.
			std::advance(it, originalArticlePath.size()); //moves the iterator of the temporary list to the "deleted" list's ending index.
			temporaryArticlePath.erase(it, temporaryArticlePath.end()); //erases all values after the iterator.

			if (temporaryArticlePath == originalArticlePath)
			{
				temporaryArticlePath.pop_front(); //erases the first value in the temporary list.
				it = temporaryArticlePath.begin(); //sets the iterator back to the beginning of the temporary list.
				for (int i = 0; i < temporaryArticlePath.size(); i++)
				{
					std::advance(it, i);
					deleteFolderPath.push_back(temporaryArticlePath.front());
				}
				article.Set_FolderPath(deleteFolderPath);
			}
		}
	}

}

void Workspace::Print_DirectoryContents(std::list<Article> articleMasterList, std::list<std::string> folderPath)
{
	for (Article article : articleMasterList)
	{
		if (article.Get_FolderPath() == folderPath)
		{
			std::cout << article.Get_Name() << " : " << article.Get_ID() << "\n";
		}
	}
}