#include "Functions.h"
#include "Book.h"
#include "Netflix.h"
#include "Movie.h"
#include "TV.h"


int main() {

	ifstream inBooks;
	ifstream inFlix;
	vector<Book*> bookLog;
	vector<Netflix*> flixLog;
	vector<TV*> TVLog;
	vector<Movie*> movieLog;

	inBooks.open("books.csv"); //establish filestreams for books and movies
	inFlix.open("netflix_titles.csv");


	readBooks(inBooks, bookLog);
	readNetflix(inFlix, flixLog, TVLog, movieLog);

	string inputFlix, inputGenres;

	cout << "Enter the name of a Netflix movie or TV show ==> "; //get user input for movie/show & genre
	getline(cin, inputFlix);

	cout << endl << endl;

	cout << "Enter a capitalized book genre, no spaces ==> ";
	getline(cin, inputGenres);

	cout << endl << endl;

	vector<string> desc;

	for (int i = 0; i < TVLog.size(); i++) { //find appropriate category for their input, output info from the corresponding class object
		if (makeAlpha(inputFlix) == makeAlpha(TVLog.at(i)->getTitle())) {
			cout << "You entered a TV show called: " << TVLog.at(i)->getTitle() << endl;
			cout << "Seasons: " << TVLog.at(i)->getSeasons() << endl;
			desc = TVLog.at(i)->getDescription();
		}
	}

	for (int i = 0; i < movieLog.size(); i++) {
		if (makeAlpha(inputFlix) == makeAlpha(movieLog.at(i)->getTitle())) {
			cout << "You entered a movie called: " << movieLog.at(i)->getTitle() << endl;
			cout << "Length: " << movieLog.at(i)->getLength() << endl;
			desc = movieLog.at(i)->getDescription();
		}
	}

		assignPoints(inputFlix, inputGenres, bookLog, desc);


		inBooks.close();
		inFlix.close();



		return 0;
	}
 