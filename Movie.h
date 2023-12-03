#pragma once
#include "Netflix.h"

class Movie : public Netflix {
private:
	string length;
public:

	Movie() {
		this->title = "";
		this->genres = genres;
		this->length = "";
	}



	string getLength() { return length; }
	void setLength(string lengthInput) { length = lengthInput; }
};
