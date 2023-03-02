#include "supp_func.hpp"

#include <limits>
#include <fstream>

const double MIN_VAL_RAND = -100., MAX_VAL_RAND = 100.;

void clearTerminal()
{
    system("cls");
}

void pauseTerminal()
{
    system("pause");
}

int optionInput(int max)
{
    int *option = new int(0);
    while (*option == 0 or *option > max)
    {
        std::cout << std::endl
                  << "Enter a value: ";
        std::cin >> *option;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (*option == 0 or *option > max)
            std::cerr << "The entered value is invalid." << std::endl;
    }
    return *option;
    delete option;
}

int numInput()
{
    int *num = new int;
    while (true)
    {
        std::cin >> *num;
        if (std::cin.good())
            break;
        else if (std::cin.fail())
        {
            std::cerr << std::endl
                      << "The entered value is invalid." << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
            continue;
        }
    }
    return *num;
    delete num;
}

void createFile(std::string &filePath)
{
    std::cout << std::endl
              << "Enter a file name (file will be created in the 'test_files' directory): ";

    std::string *fileName = new std::string;
    std::cin >> *fileName;
    filePath = "../../test_files/" + *fileName + ".txt";
    delete fileName;

    clearTerminal();

    std::cout << "Menu" << std::endl
              << std::endl
              << "1). Fill out the file manually" << std::endl
              << "2). Fill the file with random values" << std::endl;

    int option = optionInput(2);

    std::fstream file(filePath, std::ios::out);

    switch (option)
    {
    case 1:
    {
        std::string *item = new std::string;

        std::cout << std::endl
                  << "Fill out the file (use the space bar to separate items):" << std::endl
                  << std::endl;
        do
        {
            std::cin >> *item;
            file << *item << " ";
        } while (std::cin.get() != '\n');

        delete item;
        break;
    }

    case 2:
    {
        std::cout << std::endl
                  << "Enter the number of items: ";
        int *numOfItems = new int(numInput());

        srand(time(NULL));
        for (int i = 0; i < *numOfItems; i++)
            file << MIN_VAL_RAND + rand() / (MAX_VAL_RAND - MIN_VAL_RAND + 1) << " ";

        delete numOfItems;
        break;
    }

    default:
        break;
    }

    file.close();
}