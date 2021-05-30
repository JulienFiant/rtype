//
// EPITECH PROJECT, 2018
// DrawPixelBuffer
// File description:
// drawing on pixel buffer fct
//

#include "DrawPixelBuffer.hpp"
#include <iostream>
#include <assert.h>

void DrawPixelBuffer::drawRect(PixelBuffer &buffer, sf::FloatRect rect, Color color, sf::FloatRect mask)
{
    sf::FloatRect draw = Comparator::overlapRect(sf::FloatRect(0, 0, buffer.getWidth(), buffer.getHeight()), rect);
    mask = Comparator::overlapRect(draw, mask);
    int dX = (draw.width < 0) ? -1 : 1;
    int dY = (draw.height < 0) ? -1 : 1;
    for (int i = draw.top; i * dY < draw.top + draw.height * dY; i += dY)
    {
        for (int j = draw.left; j * dX < draw.left + draw.width * dX; j += dX)
        {
            if (Comparator::within(sf::Vector2f(j, i), mask))
                j += mask.width;
            buffer.setPixelAt(color, j, i);
        }
    }
}

void DrawPixelBuffer::drawLines(PixelBuffer &buffer, std::vector<sf::Vector2i> points, Color color, int width)
{
    sf::Vector2f tmp;
    sf::Vector2f base_v;
    double length = 0.0;
    int size = points.size();

    assert(size > 1);

    for (int i = 0; i < size - 1; ++i)
    {
        tmp.x = (float)points[i].x;
        tmp.y = (float)points[i].y;
        length = VectorCalc::length_v2((sf::Vector2u)points[i], (sf::Vector2u)points[i + 1]);
        base_v = VectorCalc::base_v2((sf::Vector2u)points[i], (sf::Vector2u)points[i + 1]);
        for (int l = 0; l < length; l++)
        {
            if (width > 1)
            {
                drawRect(buffer, sf::FloatRect(tmp.x - width / 2, tmp.y - width / 2, width, width), color);
            }
            else
            {
                buffer.setPixelAt(color, tmp.x, tmp.y);
            }
            tmp.x += base_v.x;
            tmp.y += base_v.y;
        }
    }
}

void DrawPixelBuffer::drawCircle(PixelBuffer &buffer, sf::Vector2f center, float out_rad, Color col, float in_rad, float precision)
{
    if (out_rad < in_rad)
    {
        float tmp = abs(out_rad);
        out_rad = abs(in_rad);
        in_rad = tmp;
    }
    for (float r = in_rad; r < out_rad; r += 0.5f)
    {
        for (float a = 0.0f; a < M_PI_2; a += M_PI_2/(precision*out_rad))
        {
            float x = r * cos(a);
            float y = r * sin(a);
            buffer.setPixelAt(col, center.x + x, center.y + y);
            buffer.setPixelAt(col, center.x - x, center.y + y);
            buffer.setPixelAt(col, center.x - x, center.y - y);
            buffer.setPixelAt(col, center.x + x, center.y - y);
        }
    }
}

void DrawPixelBuffer::drawShape(PixelBuffer &buffer, sf::FloatRect area, std::function<bool(float, float)> f, Color color)
{
    sf::Vector2f center(area.left + area.width / 2.0f - 0.5, area.top + area.height / 2.0f - 0.5);

    for (int y = area.top; y < area.top + area.height; y += 2)
    {
        for (int x = area.left; x < area.left + area.width; x += 2)
        {
            float x1 = float(x - center.x) / float(area.width/2.0f - 0.5);
            float y1 = float(y - center.y) / float(area.height/2.0f - 0.5);
            if (f(x1, y1)) {
                buffer.setPixelAt(color, x, y);
                buffer.setPixelAt(color, x+1, y);
                buffer.setPixelAt(color, x, y+1);
                buffer.setPixelAt(color, x+1, y+1);
            }
        }
    }
}
