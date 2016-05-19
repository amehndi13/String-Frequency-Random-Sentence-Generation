//HW4B 600.120 Spring 2015
//JHED: amehndi1
//Name: Anuj Mehndiratta
//Date: April 2, 2016

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <cstdlib>
#include <map>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "This program requires command line arguments." << endl;
	}
	int numSentences = stoi(argv[1]);
	map < string, vector< string > > pairs;
    string first;
    string second;
    int frequency;
    //putting the input into the structure
    while (cin >> first >> second >> frequency)
    {	
    	for (int i = 0; i < frequency; i++) {
    	   pairs[first].push_back(second);
        }	
    }
    //seeding the random number generator
    srand(1);
    for (int i = 0; i < numSentences; i++) {
    	cout << "<START>";
    	vector<string> next = pairs["<START>"];
    	int index = 0;
  		string random = next.at(0);
  		while (random != "<END>") {
    		cout << " " << random;
    		next = pairs[random];
    		index = rand() % next.size();
    		random = next.at(index);
    	}
    	cout << "<END>" << endl;
    }
}
