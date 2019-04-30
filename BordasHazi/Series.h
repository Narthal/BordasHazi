#pragma once

// Inheritance
#include "Base.h"

#include <string>

class Series : public Base
{
public:
	Series() {};
	~Series() {};


	// Get / Set
	// NumberOfSeasons
	int GetNumberOfSeasons() { return numberOfSeasons; }
	void SetNumberOfSeasons(int value) { numberOfSeasons = value; }
	// NumberOfEpisodesPerSeason
	int GetNumberOfEpisodesPerSeason() { return numberOfEpisodesPerSeason; }
	void SetNumberOfEpisodesPerSeason(int value) { numberOfEpisodesPerSeason = value; }
	// HasEnded
	bool GetHasEnded() { return hasEnded; }
	void SetHasEnded(bool value) { hasEnded = value; }

private:
	int numberOfSeasons;
	int numberOfEpisodesPerSeason;
	bool hasEnded;
};
