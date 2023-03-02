#include "menu_class.hpp"
#include "../seq_class/seq_class.cpp"
#include "../indiv_func/indiv_func.cpp"

Menu::Menu()
{
    bool *exit = new bool(false);
    while (*exit == false)
    {
        clearTerminal();

        std::cout << "Menu" << std::endl
                << std::endl
                << "1). Sequence selection" << std::endl
                << "2). Show the sequence" << std::endl
                << "3). Perform the function" << std::endl
                << "4). Exit" << std::endl
                << std::endl
                << "Selected function: Calculate the average length of the connected subsequences of negative numbers" << std::endl
                << std::endl
                << "Sequence taken from the file: ";
        std::cout << seq.getFilePath() << std::endl;

        int *option = new int(optionInput(4));
        switch (*option)
        {
        case 1:
        {
            Sequence updated;
            seq = updated;
            break;
        }

        case 2:
        {
            seq.showSeqFromFile();
            break;
        }

        case 3:
        {
            seq.getFuncResult();
            break;
        }

        case 4:
        {
            *exit = true;
            break;
        }
        
        default:
            break;
        }
        delete option;
    }
    delete exit;
}

Menu::~Menu()
{
}

std::string Menu::getFilePath()
{
    return seq.getFilePath();
}
