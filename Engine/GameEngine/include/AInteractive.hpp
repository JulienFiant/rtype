/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Interractive
*/

#ifndef AINTERACTIVE_HPP_
#define AINTERACTIVE_HPP_

#include <functional>

class AInteractive
{
public:
    ~AInteractive(){};

    void setInteraction(std::function<bool(void)> action = []() { return (false); })
    {
        this->_interact = action;
    };

    bool interact() { return (this->_interact()); };

private:
    std::function<bool(void)> _interact = []() { return (false); };
};

#endif /* !AINTERRACTIVE_HPP_ */
