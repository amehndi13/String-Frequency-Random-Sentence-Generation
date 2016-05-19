//HW4A 600.120 Spring 2015
//JHED: amehndi1
//Name: Anuj Mehndiratta
//Date: April 2, 2016

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

using namespace std;

int getMaxFrequency(map< tuple< string, string >, int > p);

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "This program requires command line arguments." << endl;
	}
    map< tuple< string, string >, int > counters; // store each word and an associated counter
    string first;
    string second;
    cin >> first;
    tuple<string, string> start ("<START>", first);
    ++counters[start];
    while (cin >> second)
    {	
    	tuple<string, string> pairs (first, second);
    	++counters[pairs];
    	first = second;
    }
    tuple<string, string> end (second, "<END>");
    ++counters[end];
    int maxFrequency = getMaxFrequency(counters);
    int counter = 0;
    //forward order
    if (*argv[1] == 'a') {
    	map<tuple<string, string>, int> :: iterator it;
    	for(it = counters.begin(); it != counters.end(); ++it) {
    		cout << get<0>(it->first) << " " << get<1>(it->first) << " " << it->second << endl;
    	}
    }
    //Backward order
    else if (*argv[1] == 'r') {
    	map<tuple<string, string>, int>:: reverse_iterator rit;
  		for (rit = counters.rbegin(); rit != counters.rend(); ++rit) {
    		cout << get<0>(rit->first) << " " << get<1>(rit->first) << " " << rit->second << endl;
    	}
    }
    //Ascending order of frequency
    else if (*argv[1] == 'c') {
    	while (counter <= maxFrequency) {
    		map<tuple<string, string>, int> :: iterator it;
    		for(it = counters.begin(); it != counters.end(); ++it) {
    			if (counter == it->second) {
    				cout << get<0>(it->first) << " " << get<1>(it->first) << " " << it->second << endl;
    			}
    		}
    		counter++;
    	}
    }
}

int getMaxFrequency(map< tuple< string, string >, int > p) {
 	int max = 0;
 	for(map<tuple<string, string>, int> :: iterator it = p.begin(); it != p.end(); ++it) {
    	if (it->second > max) {
    		max = it->second;
    	}
    }
    return max;
}


