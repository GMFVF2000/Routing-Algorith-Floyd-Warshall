//
// Created by fortune on 14/11/19.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Mtx.h"
#include "Algorithm.h"
#include <stdio.h>
#include<queue>
#include<vector>
#include <string>

using namespace std;

Mtx Mtx::fromFile(std::string filePath) {

    ifstream inFile;

    inFile.open(filePath);

    if (!inFile) {

        cout << "Unable to open file" << endl;

        exit(1);

    }

    string line;

    std::vector<std::vector<int>> values  = std::vector<std::vector<int>>();

    std::vector<int> lineValues;

    while (getline(inFile, line)) {

        lineValues = std::vector<int>();

        for (char number : line) {

            if (isdigit(number)) {

                lineValues.push_back(number - '0');

            }
        }

        values.push_back(lineValues);
    }

    inFile.close();

    Mtx matrix = Mtx();

    matrix.values = values;

    return matrix;
}

const std::string Mtx::toString() const {

    stringstream out = stringstream();

    out << "[" << std::endl;

    for (std::vector<int> const &line : values) {

        out << "[";

        for (int i : line) {

            out << " " + std::to_string(i);

        }

        out << "]" << std::endl;
    }

    out << "]";

    return out.str();
}

Mtx Mtx::clone(Mtx &other) {

    Mtx matrix = Mtx();

    matrix.values = std::vector<std::vector<int>>(other.values);

    return Mtx();

}


