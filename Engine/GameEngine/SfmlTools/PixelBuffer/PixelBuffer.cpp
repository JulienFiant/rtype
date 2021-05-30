//
// EPITECH PROJECT, 2018
// PixelBuffer
// File description:
// pixel buffer for sfml
//

#include "PixelBuffer.hpp"

PixelBuffer::PixelBuffer(unsigned int width, unsigned int height)
{
    _W = width;
    _H = height;

    _buffer = new sf::Uint8[_H * _W * 4];
    reset();
}

PixelBuffer::~PixelBuffer()
{
    delete[] _buffer;
}

void PixelBuffer::reset(Color color)
{
    unsigned int size = _H * _W * 4;

    for (unsigned int i = 0; i < size; i += 4)
    {
        _buffer[i] = color.r;
        _buffer[i + 1] = color.g;
        _buffer[i + 2] = color.b;
        _buffer[i + 3] = color.a;
    }
}

void PixelBuffer::setBuffer(sf::Uint8 value)
{
    unsigned int i = 0;
    unsigned int size = _W * _H * 4;
    while (i < size)
    {
        _buffer[i] = value;
        ++i;
    }
}

#include <iostream>

void PixelBuffer::setPixelAt(Color color, unsigned int pos)
{
    if ((pos < _W * _H * 4) && (pos % 4 == 0))
    {
        _buffer[pos] = color.r;
        _buffer[pos + 1] = color.g;
        _buffer[pos + 2] = color.b;
        _buffer[pos + 3] = color.a;
    }
}

void PixelBuffer::setPixelAt(Color color, int x, int y)
{
    if (x < 0 || x >= (int)_W || y < 0 || y >= (int)_H)
        return;
    unsigned int i = (y * _W + x) * 4;
    setPixelAt(color, i);
}

template <typename T>
void PixelBuffer::setPixelAt(Color color, sf::Vector2<T> coordinates)
{
    unsigned int i = (coordinates.y * _W + coordinates.x) * 4;
    setPixelAt(color, i);
}

unsigned int PixelBuffer::getWidth(void)
{
    return _W;
}

unsigned int PixelBuffer::getHeight(void)
{
    return _H;
}

sf::Vector2u PixelBuffer::getSize(void)
{
    return sf::Vector2u(_W, _H);
}

sf::Uint8 *PixelBuffer::getBuffer(void)
{
    return _buffer;
}

Color PixelBuffer::getPixelAt(unsigned int pos)
{
    if ((pos < _W * _H * 4) && (pos % 4 == 0))
        return Color(_buffer[pos], _buffer[pos + 1], _buffer[pos + 2], _buffer[pos + 3]);
    return Color(0, 0, 0, 0);
}

Color PixelBuffer::getPixelAt(unsigned int x, unsigned int y)
{
    unsigned int i = (y * _W + x) * 4;
    return getPixelAt(i);
}

template <typename T>
Color PixelBuffer::getPixelAt(sf::Vector2<T> coordinates)
{
    unsigned int i = (coordinates.y * _W + coordinates.x) * 4;
    return getPixelAt(i);
}
