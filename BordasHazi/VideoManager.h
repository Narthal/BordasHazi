#pragma once


// Video classes
#include "Base.h"
#include "Movie.h"
#include "Series.h"

// Std libs
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>


class VideoManager
{
public:
	VideoManager(std::string databasePath) : dataBaseSize(0), databasePath(databasePath)
	{
		// Read file
		ReadFile();

		// Set databaseLines
		databaseLines = DelimitStringToVector("\n", database);

		// Delete empty lines
		RemoveEmptyLines();

		// TODO: remove dis
		for (std::string line : databaseLines)
		{
			std::cout << line << std::endl;
		}

		// Get entries from databaseLines
		HandleEntries();
	};
	~VideoManager() {};

	// Read files and call AddVideo function
	void ReadFile();

	// String operations
	std::vector<std::string> DelimitStringToVector(const std::string& delimiter, const std::string& str);

	// Get data
	void RemoveEmptyLines();
	void HandleEntries();
	void HandleMovieEntry();
	void HandleSeriesEntry();
	

	// Get
	Base GetVideo(int index);
	int GetDataBaseSize() { return dataBaseSize; };

private:
	void AddVideo(Base base);

	std::string databasePath;
	std::string database;
	std::vector<std::string> databaseLines;



	std::vector<Base> viedos;
	int dataBaseSize;
};