//
// Created by Benjamin on 12/3/17.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "IngredientInventory.h"
#include "List.h"
#include "ArrayList.h"

List<std::string>* parseLine(std::string line){
    std::stringstream ss(line);
    List<std::string>* result = new ArrayList<std::string>();

    while( ss.good() )
    {
        std::string substr;
        std::getline( ss, substr, ',' );
        result->insertAtEnd( substr );
    }
    return result;
}

void printToFile(std::string lineToPrint, char delimiter, int& fileNum){
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


void setUpTest(IngredientInventory* inventory){
    std::cout<<"Setting up inventory...\n"<<std::endl;

    std::ifstream testFile;
    testFile.open("test.txt");

    std::string line;

    List<std::string>* data;

    if (testFile.is_open()){

        while (std::getline(testFile, line)){

            data = parseLine(line);
            inventory->addIngredient(data->getValueAt(0), atoi(data->getValueAt(1).c_str()), atoi(data->getValueAt(2).c_str()));
        }
        testFile.close();
    }
    else {
        std::cout<<"Could not open file"<<std::endl;
    }
    delete data;
    data = nullptr;

    std::cout<<inventory->toString()<<std::endl;
}

void mutatorTest(IngredientInventory* inventory){
    std::cout<<"Testing Inventory mutators...\n"<<std::endl;

    std::cout<<"Adding ingredient 'knotgrass'...\n"<<std::endl;
    inventory->addIngredient("knotgrass");

    std::cout<<"Adding 6 to 'lacewing fly' volume...\n"<<std::endl;
    inventory->addVolumeOf("lacewing flies", 6);

    std::cout<<"Subtracting 3 from 'lavender' volume...\n"<<std::endl;
    inventory->subtractVolumeOf("lavender", 3);

    std::cout<<"Setting ideal stock of 'valerian sprigs' to 17\n"<<std::endl;
    inventory->setWantValueOf("valerian sprigs", 17);

    std::cout<<"removing 'flobberworm mucus' from inventory\n\n"<<std::endl;
    inventory->removeIngredient("flobberworm mucus");

    std::cout<<inventory->toString()<<std::endl;
}

int main() {
    int fileNum = 1;
    IngredientInventory inventory = IngredientInventory();

    setUpTest(&inventory);
    printToFile(inventory.toString(),'\n',fileNum);
    mutatorTest(&inventory);
    printToFile(inventory.toString(),'\n',fileNum);

    return 0;
}

