#pragma once


// Video classes
#include "Base.h"
#include "Movie.h"
#include "Series.h"


#include <vector>
#include <string>


class VideoManager
{
public:
	VideoManager() {};
	~VideoManager() {};

	// Read files and call AddVideo function
	void ReadFiles(std::string baseDirectory);

	Base GetVideo(int index);

	int GetDataBaseSize() { return dataBaseSize; };

private:
	void AddVideo(Base base);

	std::vector<Base> viedos;
	int dataBaseSize;
};