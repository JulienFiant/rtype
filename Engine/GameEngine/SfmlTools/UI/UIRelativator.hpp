/*
** EPITECH PROJECT, 2019
** Test_Lib
** File description:
** UIRelativator
*/

#ifndef UIRELATIVATOR_HPP_
#define UIRELATIVATOR_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include "../Tools/Parser.hpp"

enum Alignement
{
    OVER = 0,
    TOP_TO_TOP = 1,
    MID_H = 2,
    BOT_TO_BOT = 3,
    UNDER = 4,
    BEFORE = 5,
    LEFT_TO_LEFT = 6,
    MID_W = 7,
    RIGHT_TO_RIGHT = 8,
    AFTER = 9
};

class UIRelativator
{
  public:
    UIRelativator(Alignement mode, int offset = 0, std::string idRelative = "");
    ~UIRelativator();

    std::string to_string();
    static UIRelativator *fromFile(std::string file);
    static UIRelativator *fromString(std::string str);

    int offset;
    Alignement mode;
    std::string idRelative;
};

#endif /* !UIRELATIVATOR_HPP_ */
