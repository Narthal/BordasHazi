#pragma once

// For inheritance
#include "Base.h"


#include <string>

class Movie : public Base
{
public:
	Movie () {};
	~Movie () {};

	// Get / Set
	// NumberOfSequel
	int GetNumberOfSequel() { return numberOfSequel; }
	void SetNumberOfSequel(int value) { numberOfSequel = value; }
	// OpeningWeekRevenue
	int GetOpeningWeekRevenue() { return openingWeekRevenue; }
	void SetOpeningWeekRevenue(int value) { openingWeekRevenue = value; }
	// Studio
	std::string GetStudio() { return studio; }
	void SetStudio(std::string value) { studio = value; }

private:
	int numberOfSequel;
	int openingWeekRevenue;
	std::string studio;
};