//
// EPITECH PROJECT, 2018
// Vector_calc_H
// File description:
// process SFML vectorsheader
//

#ifndef VECTORCALC_HPP_
#define VECTORCALC_HPP_

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <math.h>

namespace VectorCalc
{
/** ! 2D ! Return the length of a vector or distance between 2 points
    x: component 1 of the vector
    y: component 2 of the vector
     */
template <typename T>
double length_v2(T &x, T &y)
{
    return sqrt((x * x) + (y * y));
};
/** ! 2D ! Return the length of a vector or distance between 2 points
    v: vector
     */
double length_v2(sf::Vector2u v);
/** ! 2D ! Return the length of a vector or distance between 2 points
    v1: point 1
    v2: point 2
     */
double length_v2(sf::Vector2u p1, sf::Vector2u p2);
/** ! 2D ! Return the length of a vector or distance between 2 points
    v1: point 1
    v2: point 2
     */
double length_v2(sf::Vector2f p1, sf::Vector2f p2);

template <typename T>
double *base_v2(T v1[], T v2[])
{
    double tmp[2] = {(float)v2[0] - (float)v1[0], (float)v2[1] - (float)v1[1]};
    double len = length_v2(v1, v2);
    double *ret = tmp;
    ret[0] = ((double)ret[0]) / len;
    ret[1] = ((double)ret[1]) / len;
    return ret;
};
sf::Vector2f base_v2(sf::Vector2u v);
sf::Vector2f base_v2(sf::Vector2u v1, sf::Vector2u v2);
}; // namespace VectorCalc

#endif /* VECTOR_CALC_HPP_ */
