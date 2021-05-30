/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(std::string name, std::string str, std::string parser)
{
    int end = 0;
    int start = 0;

    this->name = name;
    this->parser_str = parser;
    while (end != -1)
    {
        end = str.find(parser, start);
        tab.push_back(str.substr(start, (end == -1) ? end : end - start));
        start = end + parser.length();
    }
    if (tab.back().empty())
        tab.pop_back();
}

Parser::~Parser()
{
}

void Parser::addSubParser(std::string _name, std::string parser, int index)
{
    size_t str_idx = (index == -1) ? sub_parser.size() : index;
    if (str_idx < tab.size())
        sub_parser.push_back(new Parser(_name, tab[str_idx], parser));
}

Parser *Parser::fetchSubParser(std::string name)
{
    uint i = 0;
    Parser *tmp = 0;

    if (this->name == name)
        return (this);
    while (i < sub_parser.size() && !(tmp = sub_parser[i]->fetchSubParser(name)))
        i += 1;
    return ((i == sub_parser.size()) ? 0 : tmp);
}

std::string Parser::stringFromLimiter(std::string str, int begin, int end, std::string b_lim, std::string e_lim)
{
    int count = 0;
    int i = str.find(b_lim, begin);
    int finish = end == -1 ? str.length() : end;

//    std::cout << "coin " << str << std::endl;
    end = finish;
    if (i != -1)
    {
        begin = i + b_lim.length();
        ++count;
    }
    i = begin;
    finish = str.find(e_lim, i) - i;
    while (i < end && !(finish == 0 && count <= 0))
    {
        if (str.find(b_lim, i) - i == 0)
            count += 1;
        ++i;
        finish = str.find(e_lim, i) - i;
        if (finish == 0)
            count -= 1;
    }
//    std::cout << "test " << finish << " " << count << std::endl;
//    std::cout << "part " << begin << " " << i - begin - ((finish == 0 && count <= 0) ? 0 : 0) << std::endl;
    return (str.substr(begin, i - begin));
}

std::string Parser::toString(bool recursive)
{
    std::string str = "[" + name + "](\'" + parser_str + "\'):";

    for (auto i : tab)
        str += " \'" + i + "\'";
    str += "\n";
    if (recursive)
    {
        for (Parser *i : sub_parser)
            str += i->toString(size_t(1));
    }
    return str;
}

std::string Parser::toString(size_t count)
{
    std::string str = "";

    for (size_t i = 0; i < count; i++)
        str += "\t";
    str += "[" + name + "](\'" + parser_str + "\'):";
    for (auto i : tab)
        str += " \'" + i + "\'";
    str += "\n";
    for (Parser *i : sub_parser)
        i->toString(count + 1);
    return str;
}
