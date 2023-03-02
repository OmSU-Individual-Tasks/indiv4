#include "indiv_func.hpp"

int calcOfAverageLenOfSubseq(std::fstream &file, double &funcResult)
{
    if (!file.is_open()) return -1;
    if (!file.good()) return -2;

    double item;
    int numOfSubseq = 0, totalLen = 0;
    bool negSubseq = false;

    while (file >> item)
    {
        if (item < 0)
        {
            totalLen++;
            if (!negSubseq)
                numOfSubseq++;
            negSubseq = true;
        }
        else
            negSubseq = false;
    }

    if (!file.eof())
        return -4;
    
    if (numOfSubseq == 0)
        return -3;
    else
        funcResult = (double) totalLen / numOfSubseq;

    return 0;
}