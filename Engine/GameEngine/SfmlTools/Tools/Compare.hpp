/*
** EPITECH PROJECT, 2019
** Sfml
** File description:
** Compare
*/

#ifndef COMPARE_HPP_
#define COMPARE_HPP_

#include <SFML/Graphics.hpp>
#include <math.h>

namespace Comparator
{
template <typename T>
bool betwin(T value, T min, T max, bool inclusive);
bool betwinAngle(float value, float min, float max, bool inclusive);
bool within(sf::Vector2f, sf::FloatRect rect);
bool within(sf::Vector2f, sf::IntRect rect);
sf::FloatRect overlapRect(const sf::FloatRect&, const sf::FloatRect&);
// bool within(sf::Vector2f, sf::CircleShape);
};     // namespace Comparator
#endif /* !COMPARE_HPP_ */
