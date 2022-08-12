#include "Article.h"
#include "Workspace.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <list>

int main()
{
    Workspace Workspace("A0", "Testing Workspace", "MAIN_0", "DELETE_0");

    for (int i = 0; i <= 9; i++)
    {
        Workspace.Create_Article(Workspace.Get_ArticleMasterList(), Workspace.Create_ArticleID(10, Workspace.Get_ArticleMasterList()), ("Article " + std::to_string(i + 1)), Workspace.Get_CurrentFolderPath());
    }

    Workspace.Print_DirectoryContents(Workspace.Get_ArticleMasterList(), Workspace.Get_CurrentFolderPath());
}