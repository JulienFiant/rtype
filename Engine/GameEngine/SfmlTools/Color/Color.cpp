/*
** EPITECH PROJECT, 2019
** Sfml
** File description:
** Colorf
*/

#include "Color.hpp"

Color::Color()
{
    r = 0;
    g = 0;
    b = 0;
    a = 255;
}

Color::Color(int r, int g, int b, int a)
{
    this->r = r;

    this->g = g;
    this->b = b;
    this->a = a;
}

Color::Color(Colorf colorf)
{
    this->r = colorf.r*255;
    this->g = colorf.g*255;
    this->b = colorf.b*255;
    this->a = colorf.a*255;
}

const Color Color::Black(0, 0, 0, 255);
const Color Color::White(255, 255, 255, 255);
const Color Color::Transparent(0, 0, 0, 0);

const Color Color::Yellow(255, 255, 0, 255);
const Color Color::Red(255, 0, 0, 255);
const Color Color::Magenta(255, 0, 255, 255);
const Color Color::Blue(0, 0, 255, 255);
const Color Color::Cyan(0, 255, 255, 255);
const Color Color::Green(0, 255, 0, 255);

Color::~Color()
{
}

Colorf::Colorf()
{
    r= 0.0;
    g =0.0;
    b = 0.0;
    a = 1.0;
}

Colorf::Colorf(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Colorf::Colorf(Color color)
{
    this->r = color.r/255.0f;
    this->g = color.g/255.0f;
    this->b = color.b/255.0f;
    this->a = color.a/255.0f;
}

Colorf::~Colorf()
{
}
