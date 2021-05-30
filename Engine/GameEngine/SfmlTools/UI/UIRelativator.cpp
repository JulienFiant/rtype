/*
** EPITECH PROJECT, 2019
** Test_Lib
** File description:
** UIRelativator
*/

#include "UIRelativator.hpp"

UIRelativator::UIRelativator(Alignement mode, int offset, std::string id)
{
    this->mode = mode;
    this->idRelative = id;
    this->offset = offset;
}

UIRelativator::~UIRelativator()
{
}

std::string UIRelativator::to_string()
{
    return std::string("{") + std::to_string(mode) + "," + std::to_string(offset) + "," + idRelative + "}";
}

UIRelativator *UIRelativator::fromFile(std::string file)
{
    std::ifstream ifs;
    std::string s;

    ifs.open(file);

    if (!ifs.is_open())
        return (nullptr);
    getline(ifs, s);
    if (s.empty())
        return (nullptr);
    ifs.close();
    s = Parser::stringFromLimiter(s, 0, -1, "{", "}");
    Parser parse("relativator", s, ",");
    return (new UIRelativator((Alignement)std::stoi(parse.tab[0]), std::stoi(parse.tab[1]), (parse.tab.size() == 3) ? parse.tab[2] : ""));
}

UIRelativator *UIRelativator::fromString(std::string str)
{
    int b = 0;
    int e = -1;

    if (str.empty())
        return (nullptr);
    std::string tmp = Parser::stringFromLimiter(str, b, e, "{", "}");
    Parser parse("relativator", tmp, ",");
    return (new UIRelativator((Alignement)std::stoi(parse.tab[0]), std::stoi(parse.tab[1]), (parse.tab.size() == 3) ? parse.tab[2] : ""));
}
