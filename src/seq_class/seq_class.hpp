#pragma once

#include <iostream>
#include <fstream>
#include "../supp_func/supp_func.hpp"

class Sequence
{
private:
    std::string filePath;
    double funcResult;
    int status;

public:
    Sequence();
    Sequence(Sequence &);
    ~Sequence();

    std::string getFilePath();
    void showSeqFromFile();
    void getFuncResult();
};