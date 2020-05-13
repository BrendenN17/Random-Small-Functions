
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>


using std::endl;
using std::cout;
using std::cin;
#include "Functions.hpp"
#include "Functions.cpp"


int main(int argc, const char * argv[])
{
    long number;//data item to be inserted in list
    Node *pHead1, *pHead2;//pointer to start of list
    std::string line = "";
    int which = 0;
    

    which = whichFile();    //user chooses which file to look at
    if (which == 1)
    {
        std::ifstream file1;
        file1.open("input.txt");
        if (!file1.is_open())
        {
            std::cout << "file input.txt not opened correctly";
            return 0;
        }
        while(!file1.eof())
        {
            //not at end of file
            file1 >> line;//read in # as string
        
            number = stol(line);//change string to long #
            insert(&pHead1, number);//inserts data in order
        }
        display_list(&pHead1);
    //will have fully filled in a list with all values from the file
        std::cout << "min is " << findMin(pHead1) << endl;
        std::cout << "max is " << findMax(pHead1) << endl;
        std::cout << "median is " << findMedian(pHead1) << endl;
        file1.close();
    }
    else //which is 2
    {
        std::ifstream file2;
        file2.open("input2.txt");
        if (!file2.is_open())
        {
            std::cout << "file input2.txt not opened correctly";
            return 0;
        }
        while(!file2.eof())
        {
            //not at end of file
            file2 >> line;//read in # as string
            
            number = stol(line);//change string to long #
            insert(&pHead2, number);//inserts data in order
        }
        std::cout << "min is " << findMin(pHead2) << endl;
        std::cout << "max is " << findMax(pHead2) << endl;
        std::cout << "median is " << findMedian(pHead2) << endl;
        display_list(&pHead2);
        file2.close();
    }
    
    
    
    return 0;
}
