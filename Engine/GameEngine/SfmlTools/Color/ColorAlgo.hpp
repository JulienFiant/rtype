/*
** EPITECH PROJECT, 2019
** Sfml
** File description:
** ColorAlgo
*/

#ifndef COLORALGO_HPP_
#define COLORALGO_HPP_

#include <math.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Color.hpp"

namespace ColorAlgo
{
Color colorShift(double progress, Color left, Color right);
Color colorShift(double progress, std::vector<Color> colors, std::vector<double> percentages = {0});
Color complement(Color color);
}; // namespace ColorAlgo

#endif /* COLOR_MANAGER.HPP_*/