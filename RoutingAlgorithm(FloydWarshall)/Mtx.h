//
// Created by fortune on 14/11/19.
//

#ifndef ROUTINGALOGRITHM_MATRIX_H
#define ROUTINGALOGRITHM_MATRIX_H

#include <vector>
#include <string>

class Mtx {

public:

    static Mtx clone(Mtx &other);

    static Mtx fromFile(std::string filePath);

    const std::string toString() const;

    std::vector<std::vector<int>> values;


};


#endif //ROUTINGALOGRITHM_MATRIX_H
