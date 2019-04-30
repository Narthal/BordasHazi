#pragma once

#include <string>
#include <vector>

enum Category
{
	Action,
	Fantasy,
	Drama,
	Thriller,
	Comedy
};

class Base
{
public:
	Base() {};
	~Base() {};

	// Get / Set
	// Title
	std::string GetTitle() { return title; }
	void SetTitle(std::string value) { title = value; }
	// ReleaseYear
	int GetReleaseYear() { return releaseYear; }
	void SetReleaseYear(int value) { releaseYear = value; }
	// Director
	std::string GetDirector() { return director; }
	void SetDirector(std::string value) { director = value; }
	// Categories
	std::vector<Category> GetCategories() { return categories; }
	void SetCategories(std::vector<Category> value) { categories = value; }
	// MainActors
	std::vector<std::string> GetMainActors() { return mainActors; }
	void SetMainActors(std::vector<std::string> value) { mainActors = value; }



private:
	std::string title;
	int releaseYear;
	std::string director;
	std::vector<Category> categories;
	std::vector<std::string> mainActors;
};