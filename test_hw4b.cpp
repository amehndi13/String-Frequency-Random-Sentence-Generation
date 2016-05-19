//HW4B Test 600.120 Spring 2015
//JHED: amehndi1
//Name: Anuj Mehndiratta
//Date: April 2, 2016

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

bool compare_files(std::string f1, std::string f2)
{
    std::ifstream is1(f1), is2(f2);
    if(!is1.is_open() || !is2.is_open()) {
        std::cerr << "could not open one of the files" << std::endl;
        return false;
    }
    char c1, c2;
    while(is1.get(c1)) {
        is2.get(c2);
        if(c1 != c2) {
            return false;
        }
    }
    return is1.eof() != is2.eof();
}

int main(void)
{
    assert(compare_files("output1b.txt", "desired1b.txt"));
    assert(compare_files("output2b.txt", "desired2b.txt"));
    std::cout << "Success!" << std::endl;
    return 0;
}