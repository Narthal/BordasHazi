#pragma once

// Inheritance
#include "Base.h"

#include <string>

class Series : public Base
{
public:
	Series
	(
		std::string title,
		int releaseYear,
		std::string director,
		std::vector<Category> categories,
		std::vector<std::string> mainActors,

		int numberOfSeasons,
		int numberOfEpisodesPerSeason,
		bool hasEnded
		) :
		Base
		(
			title,
			releaseYear,
			director,
			categories,
			mainActors
		),

		numberOfSeasons(numberOfSeasons),
		numberOfEpisodesPerSeason(numberOfEpisodesPerSeason),
		hasEnded(hasEnded)
	{};
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
