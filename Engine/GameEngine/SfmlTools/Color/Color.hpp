/*
** EPITECH PROJECT, 2019
** Sfml
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

class Colorf;

class Color
{

  public:

    static const Color Black;       ///< Black predefined color
    static const Color White;       ///< White predefined color
    static const Color Red;         ///< Red predefined color
    static const Color Green;       ///< Green predefined color
    static const Color Blue;        ///< Blue predefined color
    static const Color Yellow;      ///< Yellow predefined color
    static const Color Magenta;     ///< Magenta predefined color
    static const Color Cyan;        ///< Cyan predefined color
    static const Color Transparent; ///< Transparent (black) predefined color

    Color(int r, int g, int b, int a = 255);
    Color(Colorf color);
    Color();
    ~Color();

    int r;
    int g;
    int b;
    int a;
};

class Colorf
{
  public:
    Colorf(float r, float g, float b, float a = 1.0f);
    Colorf(Color color);
    Colorf();
    ~Colorf();

    float r;
    float g;
    float b;
    float a;
};

#endif /* !COLOR_HPP_ */
