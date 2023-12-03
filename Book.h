#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Book {

private:
	string title = "";
	string author = "";
	double rating = 0;
	string preDesc = "";
	vector<string> description;
	vector<string> genres;
	int pages = 0;
	
	int Pts = 0;


public:

	Book() {
		this->title = "";
		this->author = "";
		this->rating = 0;
		this->preDesc = "";
		this->description = description;
		this->genres = genres;
		this->pages = 0;
		
		this->Pts = 0;
	}


	string getTitle() { return title; }
	string getAuthor() { return author; }
	double getRating() { return rating; }
	string getPreDesc() { return preDesc; }
	vector<string> getDescription() { return description; }
	vector<string> getGenres() { return genres; }
	int getPages() { return pages; }

	int getPts() { return Pts; }
	


	void setTitle(string titleInput) { title = titleInput; }
	void setAuthor(string authorInput) { author = authorInput; }
	void setRating(double ratingInput) { rating = ratingInput; }
	void setPreDesc(string preDescInput) { preDesc = preDescInput; }
	void setDescription(vector<string>& descriptionInput) { description = descriptionInput; }
	void setGenres(vector<string>& genresInput) { genres = genresInput; }
	void setPages(int pagesInput) { pages = pagesInput; }
	
	void incrementPts(int inputPts) { Pts += inputPts; }
};
