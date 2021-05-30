/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IEngine
*/

#ifndef IENGINE_HPP_
#define IENGINE_HPP_

#include <iostream>

class IEngine
{
public:
    virtual ~IEngine(){};

    virtual bool init() = 0;
    virtual bool release() = 0;
    virtual bool reload() = 0;

protected:
private:
};

#endif /* !IENGINE_HPP_ */
