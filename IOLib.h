//
// Created by Benjamin on 12/14/17.
//

#ifndef INC_220FINALPROJECT_IOLIB_H
#define INC_220FINALPROJECT_IOLIB_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "List.h"
#include "ArrayList.h"

void printLineToFile(std::string lineToPrint, char delimiter, int& fileNum){
    std::ofstream fout ("records/outFile"+std::to_string(fileNum)+".txt");
    if (fout) {
        std::stringstream parts(lineToPrint);
        while (parts){
            std::string part;
            getline(parts,part, delimiter);
            fout << part << std::endl;
        }
        fout.close();
    }
    else {
        std::cout << "Error in opening file";
    }
    fileNum++;
}

List<std::string>* parseLine(std::string line, char delimiter){
    std::stringstream ss(line);
    List<std::string>* result = new ArrayList<std::string>();

    while(ss.good()) {
        std::string substr;
        std::getline(ss, substr, delimiter);
        result->insertAtEnd(substr) ;
    }
    return result;
}
#endif //INC_220FINALPROJECT_IOLIB_H
