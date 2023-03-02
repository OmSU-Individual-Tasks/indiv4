#pragma once

#include "../seq_class/seq_class.hpp"

class Menu
{
private:
public:
    Sequence seq;

    Menu();
    ~Menu();

    std::string getFilePath();
};