#pragma once
#include "Netflix.h"
/*class Song : public Media {
private:
	bool top40;

public:
	Song(char type, string title, string keyName, int rating, string genre, int length, int yearReleased, bool top40);
	bool getTop40() { return top40; }
	void setTop40(bool top40) { this->top40 = top40; }
};*/

class TV : public Netflix {
private:
	string seasons;

public:

	TV() {
		this->title = "";
		this->description = description;
	
		this->seasons = "";
	}

	string getSeasons() { return seasons; }
	void setSeasons(string seasonsInput) { seasons = seasonsInput; }

};

