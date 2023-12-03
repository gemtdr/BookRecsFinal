#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Netflix {
protected:
	string title;
	vector<string> description;
	vector<string> genres;

public:
	Netflix() {
		this->title = "";
		this->description = description;
		
	
	}


	string getTitle() { return title; }
	vector<string> getDescription() { return description; }
	
	

	void setTitle(string titleInput) { title = titleInput; }
	void setDescription(vector<string> descriptionInput) { description = descriptionInput; }
	
	

};
