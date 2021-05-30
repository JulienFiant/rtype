/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include <string>

class AScene
{
public:
    virtual ~AScene(){};

    virtual std::string getName() { return (this->_name); };

    virtual void draw() = 0;
    virtual bool interact() = 0;

    std::string _name;
};
#endif /* !ASCENE_HPP_ */
