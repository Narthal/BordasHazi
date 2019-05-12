#pragma once

// For inheritance
#include "Base.h"


#include <string>

class Movie : public Base
{
public:
	Movie
	(
		std::string title,
		int releaseYear,
		std::string director,
		std::vector<Category> categories,
		std::vector<std::string> mainActors,

		int numberOfSequel,
		int openingWeekRevenue,
		std::string studio
	):
		Base
		(
			title,
			releaseYear,
			director,
			categories,
			mainActors
		),

		numberOfSequel(numberOfSequel),
		openingWeekRevenue(openingWeekRevenue),
		studio(studio)
	{};
	~Movie () {};

	// Get / Set
	// NumberOfSequel
	int GetNumberOfSequel() const { return numberOfSequel; }
	void SetNumberOfSequel(int value) { numberOfSequel = value; }
	// OpeningWeekRevenue
	int GetOpeningWeekRevenue()const { return openingWeekRevenue; }
	void SetOpeningWeekRevenue(int value) { openingWeekRevenue = value; }
	// Studio
	std::string GetStudio() const{ return studio; }
	void SetStudio(std::string value) { studio = value; }

private:
	int numberOfSequel;
	int openingWeekRevenue;
	std::string studio;
};