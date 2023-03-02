#include "seq_class.hpp"
#include "../indiv_func/indiv_func.hpp"

Sequence::Sequence()
{
    clearTerminal();

    std::cout << "Menu" << std::endl
              << std::endl
              << "1). Select an existing file" << std::endl
              << "2). Create a new file" << std::endl;

    int *option = new int(optionInput(2));

    switch (*option)
    {
    case 1:
        std::cout << std::endl
                  << "Enter the path to the file (example: D:/.../.../file_name.txt): ";
        std::cin >> filePath;
        break;

    case 2:
        createFile(filePath);
        break;

    default:
        break;
    }
    delete option;

    std::fstream file(filePath, std::ios::in);
    status = calcOfAverageLenOfSubseq(file, funcResult);
    file.close();
}

Sequence::Sequence(Sequence &updated) : filePath(filePath), funcResult(funcResult), status(status)
{
}

Sequence::~Sequence()
{
}

std::string Sequence::getFilePath()
{
    return filePath;
}

void Sequence::showSeqFromFile()
{
    std::cout << std::endl;

    if (status != -1 and status != -2)
    {
        std::fstream file(filePath, std::ios::in);
        std::string *item = new std::string;
        while (file >> *item)
            std::cout << *item << " ";
        std::cout << std::endl
                  << std::endl;
        delete item;
        file.close();
    }
    else
        std::cerr << "Unable to open file." << std::endl
                  << std::endl;

    pauseTerminal();
}

void Sequence::getFuncResult()
{
    std::cout << std::endl;

    switch (status)
    {
    case 0:
        std::cerr << "Average length of contiguous subsequences of negative numbers: "
                  << funcResult << std::endl;
        break;

    case -1:
        std::cerr << "Unable to open file." << std::endl;
        break;

    case -2:
        std::cerr << "Data collection was interrupted due to an unidentified error." << std::endl;
        break;

    case -3:
        std::cerr << "There are no negative numbers in the file." << std::endl;
        break;

    case -4:
        std::cerr << "Data collection was interrupted due to a type mismatch." << std::endl;
        break;
    }

    std::cout << std::endl;
    pauseTerminal();
}