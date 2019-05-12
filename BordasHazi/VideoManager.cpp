#include "VideoManager.h"



void VideoManager::ReadFile()
{
	try
	{
		// Open file
		std::ifstream databaseFileStream(VideoManager::databasePath);
		if (!databaseFileStream)
		{
			std::exception e(("Could not open file at : " + databasePath).c_str());
			throw(e);
		}

		// Read file
		std::stringstream databaseStream;
		databaseStream << databaseFileStream.rdbuf();

		// Close file handler
		databaseFileStream.close();

		// Get string
		database = databaseStream.str();
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR : " << e.what() << std::endl;
		// TODO: exit program
	}

	return;
}

std::vector<std::string> VideoManager::DelimitStringToVector(const std::string& delimiter, const std::string& str)
{
	// This will be returned by this function
	std::vector<std::string> returnVector;

	// Get lengths
	int strleng = str.length();
	int delleng = delimiter.length();
	
	// Check delimiter
	if (delleng == 0)
	{
		std::cout << "ERROR : " << "Bad delimiter" << std::endl;
	}

	// Substring indexes, these will mark the beginning of the given line and the offset from it (to the end of line)
	int i = 0;
	int k = 0;

	// Add new lines to returnVector while we have not reached the end of file
	while (i < strleng)
	{
		int j = 0;
		while (i + j < strleng && j < delleng && str[i + j] == delimiter[j])
			j++;
		if (j == delleng)//found delimiter
		{
			returnVector.push_back(str.substr(k, i - k));
			i += delleng;
			k = i;
		}
		else
		{
			i++;
		}
	}

	// Put the last line in the returnVector too
	returnVector.push_back(str.substr(k, i - k));

	// Return returnVector
	return returnVector;
}

void VideoManager::RemoveEmptyLines()
{
	VideoManager::databaseLines.erase
	(
		std::find_if
		(
			VideoManager::databaseLines.begin(),
			VideoManager::databaseLines.end() - 1,	// Because of EOF
			[](std::string & currentLine)
			{
				return currentLine == "";
			}
		)
	);
	return;
}

void VideoManager::HandleEntries()
{
	while (databaseLines[0] != "")
	{
		std::vector<std::string> firstLineData = DelimitStringToVector(" ", databaseLines[0]);
		
		if (firstLineData[1] == "movie")
		{
			HandleMovieEntry();
		}
		else if (firstLineData[1] == "series")
		{
			HandleSeriesEntry();
		}
		else
		{
			std::cout << "ERROR : " << "Unknown new entry type : " << firstLineData[1] << std::endl;
		}

	}
	return;

}

void VideoManager::HandleMovieEntry()
{
	// Base
	std::string title;
	int releaseYear;
	std::string director;
	std::vector<Category> categories;
	std::vector<std::string> mainActors;

	// Movie
	int numberOfSequel;
	int openingWeekRevenue;
	std::string studio;

	// Search for these words
	std::vector<std::string> singleEntries =
	{
		"title",
		"releaseYear",
		"director",
		"numberOfSequel",
		"openingWeekRevenue",
		"studio"
	};


	// Get data from lines
	for (std::string searchToken : singleEntries)
	{
		// Find relevant line
		std::vector<std::string>::iterator foundLine = std::find_if
		(
			VideoManager::databaseLines.begin(),
			VideoManager::databaseLines.end() - 1,	// Because of EOF
			[&](std::string & currentLine)
			{
				std::vector<std::string> lineTokens = DelimitStringToVector(" ", currentLine);
				return lineTokens[0] == searchToken;
			}
		);

		// title
		if (searchToken == singleEntries[0])		
		{
			std::vector<std::string> lineTokens = DelimitStringToVector(" ", *foundLine);
			for (size_t i = 2; i < lineTokens.size(); i++)
			{
				title += lineTokens[i] + " ";
			}
			VideoManager::databaseLines.erase(foundLine);
		}
		// rekease year
		else if (searchToken == singleEntries[1])
		{
			std::vector<std::string> lineTokens = DelimitStringToVector(" ", *foundLine);
			releaseYear = std::stoi(lineTokens[2]);
			VideoManager::databaseLines.erase(foundLine);
		}
		// director
		else if (searchToken == singleEntries[2])	
		{
			std::vector<std::string> lineTokens = DelimitStringToVector(" ", *foundLine);
			for (size_t i = 2; i < lineTokens.size(); i++)
			{
				director += lineTokens[i] + " ";
			}
			VideoManager::databaseLines.erase(foundLine);
		}
		// number of sequel
		else if (searchToken == singleEntries[3])	
		{
			std::vector<std::string> lineTokens = DelimitStringToVector(" ", *foundLine);
			numberOfSequel = std::stoi(lineTokens[2]);
			VideoManager::databaseLines.erase(foundLine);
		}
		// opening week revenue
		else if (searchToken == singleEntries[4])	
		{
			std::vector<std::string> lineTokens = DelimitStringToVector(" ", *foundLine);
			openingWeekRevenue = std::stoi(lineTokens[2]);
			VideoManager::databaseLines.erase(foundLine);
		}
		// studio
		else if (searchToken == singleEntries[5])	
		{
			std::vector<std::string> lineTokens = DelimitStringToVector(" ", *foundLine);
			for (size_t i = 2; i < lineTokens.size(); i++)
			{
				studio += lineTokens[i] + " ";
			}
			VideoManager::databaseLines.erase(foundLine);
		}
		// ERROR
		else
		{
			std::cout << "ERROR : " << "Couldnt find data member for : " << searchToken << std::endl;
		}
	}

	//Delete new entry from vector stack
	VideoManager::databaseLines.erase
	(
		std::find_if
		(
			VideoManager::databaseLines.begin(),
			VideoManager::databaseLines.end() - 1,	// Because of EOF
			[&](std::string & currentLine)
			{
				std::vector<std::string> lineTokens = DelimitStringToVector(" ", currentLine);
				return lineTokens[0] == "new";
			}
		)
	);

	// Create movie object
	Movie newMovie
	(
		title,
		releaseYear,
		director,
		categories,
		mainActors,

		numberOfSequel,
		openingWeekRevenue,
		studio
	);

	return;
}

void VideoManager::HandleSeriesEntry()
{
}
