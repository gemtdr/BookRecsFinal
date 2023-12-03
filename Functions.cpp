#include "Functions.h"
#include "Movie.h"
#include "TV.h"
#include "LinkedList.h"

string removeQuotes(string inputString) {
//PRE: Take string input
//POST: Return string with quotes removed
	inputString = inputString.substr(1, inputString.size() - 2);
	return inputString;
}

void readBooks(ifstream& inBooks, vector<Book*>& bookLog) {

//PRE: Take filestream to books file and vector for bookLog
//POST: Iterate through each line of the file, creating book objects & adding to vector
	
	vector<string> row;
	string inRec, tempString;

	getline(inBooks, inRec);

	while (inBooks.good()) {

		stringstream inSS(inRec);
		row.clear();

		while (getline(inSS, tempString, '"')) {
			row.push_back(tempString);
		}

		try {

			Book* inputBook = new Book();

			inputBook->setTitle(row.at(3));
			inputBook->setAuthor(row.at(7));
			inputBook->setRating(stod(row.at(9)));
			inputBook->setPreDesc(row.at(11));

			vector<string> keyWords = vectorizeDesc(row.at(11));
			inputBook->setDescription(keyWords);

			vector<string> genres = vectorizeBookGenres(row.at(17));
			inputBook->setGenres(genres);

			inputBook->setPages(stoi(row.at(25)));
			

			bookLog.push_back(inputBook);
			getline(inBooks, inRec);
			}		
			


		catch (...) {
			getline(inBooks, inRec);
			
		}
		
		
	}
}

void readNetflix(ifstream& inFlix, vector<Netflix*>& flixLog, vector<TV*>& TVlog, vector<Movie*>& movieLog) {

	//PRE: Take Netflix filestream, vectors for general media, TV and movies
	//POST: Push everything onto flixLog, and TV or movie depending on type of media
	vector<string> row;
	string inRec, tempString;

	getline(inFlix, inRec);

	while (inFlix.good()) {

		stringstream inSS(inRec);
		row.clear();

		while (getline(inSS, tempString, ',')) {
			row.push_back(tempString);
		}

		try {
			
			if (row.at(2) == "MOVIE") {

				Movie* inputMovie = new Movie();

				inputMovie->setTitle(makeAlpha(row.at(1)));
				inputMovie->setDescription(vectorizeDesc(row.at(3) + row.at(4) + row.at(5) + row.at(6)));
				inputMovie->setLength(row.at(8));

				movieLog.push_back(inputMovie);
				flixLog.push_back(inputMovie);

				getline(inFlix, inRec);

			}

			else {

				TV* inputTV = new TV();

				inputTV->setTitle(row.at(1));
				inputTV->setDescription(vectorizeDesc(row.at(3) + row.at(4) + row.at(5) + row.at(6)));
				inputTV->setSeasons(row.at(6));

				TVlog.push_back(inputTV);
				flixLog.push_back(inputTV);

				getline(inFlix, inRec);
			}
			

		}

		catch (...) {
			getline(inFlix, inRec);

		}


	}
} 

vector<string> vectorizeDesc(string preDesc) {

	string tempString;
	stringstream inSS(preDesc);
	vector<string> desc;

	while (getline(inSS,tempString, ' ')) {
		tempString = makeAlpha(tempString);
		tempString = makeLower(tempString);
		if (tempString.length() > 3) {
			desc.push_back(tempString);
		}
	}

	return desc;
}

vector<string> vectorizeBookGenres(string preGenres) {

	//PRE: Take a list of genres
	//POST: Split them by comma, adding to vector

	string tempString;
	stringstream inSS(preGenres);
	vector<string> genres;

	while (getline(inSS, tempString, ',')) {
		tempString = makeAlpha(tempString);
		genres.push_back(tempString);
	}

	return genres;
	
}

string makeLower(string inputString) {

	//PRE: Take string
	//POST: return string lowercased
	
	for (int i = 0; i < inputString.length(); i++) {
		inputString[i] = tolower(inputString[i]);
	}

	return inputString;
}





string makeAlpha(string tempString) {

	//PRE: Take string with letters, numbers, etc.
	//POST: return an alphabetic, no space version of string

	for (int i = 0; i < tempString.size(); i++) {

		if (tempString[i] < 'A' || tempString[i] > 'Z' && tempString[i] < 'a' || tempString[i] > 'z') {
			
			tempString.erase(i, 1);
			i--;
			
		}

	}

	return tempString;
	
}

void assignPoints(string userFlix, string userGenres, vector<Book*>& bookLog, vector<string>& flixDesc) {

	//PRE: Take a media object corresponding to user input
	//POST: Go through books and sort by appropriate genre & keywords

	vector<Book> genredBooks;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < bookLog.at(i)->getGenres().size(); j++) {
			if (bookLog.at(i)->getGenres().at(j) == userGenres) {
				genredBooks.push_back(*(bookLog.at(i)));
			}
		}
	}

	for (int i = 0; i < genredBooks.size(); i++) {
		for (int j = 0; j < genredBooks.at(i).getDescription().size(); j++) {
			for (int g = 0; g < flixDesc.size(); g++) {
				if (genredBooks.at(i).getDescription().at(j) == flixDesc.at(g)) {
					genredBooks.at(i).incrementPts(1);
				}
			}
		}
	}

	Linked list;

	for (int i = 0; i < genredBooks.size(); i++) { //print top values from linked list
		list.addNode(genredBooks.at(i));
	}

	list.printList();
		
}

