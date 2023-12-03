#pragma once
#include "Book.h"
#include "Netflix.h"
#include "Movie.h"
#include "TV.h"

string removeQuotes(string inputString);

void readBooks(ifstream& inBooks, vector<Book*>& bookLog);

void readNetflix(ifstream& inFlix, vector<Netflix*>& flixLog, vector<TV*>& TVlog, vector<Movie*>& movieLog);

vector<string> vectorizeDesc(string preDesc);

vector<string> vectorizeBookGenres(string preGenres);

string makeLower(string inputString);

string makeAlpha(string tempString);

void assignPoints(string userFlix, string userGenres, vector<Book*>& bookLog, vector<string>& flixDesc);
