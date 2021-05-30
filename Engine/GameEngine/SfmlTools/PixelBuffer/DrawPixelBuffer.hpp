//
// EPITECH PROJECT, 2018
// Draw_pixel_buffer_H
// File description:
// drawing on pixel buffer fct for SFML header
//

#ifndef DRAWPIXELBUFFER_HPP_
#define DRAWPIXELBUFFER_HPP_

#include "./PixelBuffer.hpp"
#include "../Math/VectorCalc.hpp"
#include "../Tools/Compare.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <functional>

namespace DrawPixelBuffer
{
void drawRect(PixelBuffer &buffer, sf::FloatRect rect, Color, sf::FloatRect mask = sf::FloatRect(0, 0, 0, 0));
// void drawRect(PixelBuffer &buffer, sf::IntRect rect, Color (*compute)(PixelBuffer, uint x, uint y));
void drawCircle(PixelBuffer &buffer, sf::Vector2f center, float outer_radius, Color color, float inner_radius = 0.0f, float precision = 4.0f);
void drawLines(PixelBuffer &buffer, std::vector<sf::Vector2i> points, Color, int width = 1);
void drawShape(PixelBuffer &buffer, sf::FloatRect area, std::function<bool(float, float)> f, Color color);
}; // namespace DrawPixelBuffer


#endif /* DRAW_PIXEL_BUFFER_HPP_ */
