/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <vector>
#include <iostream>

class Parser
{
public:
    /** Constructor
     * name     :   name of the section
     * str      :   string to be parsed
     * parser   :   string used as separator
     * */
    Parser(std::string name, std::string str, std::string parser);
    ~Parser();
    /** create a child parser for a mermber of the parsed string
     * name     :   name of the section
     * parser   :   string used as separator
     * index    :   index of the string to be parsed in tab
     * */
    void addSubParser(std::string name, std::string parser, int index = (-1));
    /** give a pointer to a parser or sub-parser according to its name,
     * the first section with that name is returned
     * name     :   name of the section
     * */
    Parser *fetchSubParser(std::string name);

    static std::string stringFromLimiter(const std::string str, int begin, int end, const std::string b_lim, const std::string e_lim);
    /** return a string containing all the parser content
     * recursive    :   if 'true' all the child parsers are included, default: 'false'
     * */
    std::string toString(bool recursive = false);
    /** vector containing the parsed string */
    std::vector<std::string> tab;

protected:
private:
    std::string toString(size_t i);
    std::vector<Parser *> sub_parser;
    std::string name;
    std::string parser_str;
};

#endif /* !PARSER_HPP_ */
