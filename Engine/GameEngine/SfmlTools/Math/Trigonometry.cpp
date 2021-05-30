/*
** EPITECH PROJECT, 2019
** Test_Lib
** File description:
** Trigonometry
*/

#include "Trigonometry.hpp"

float Trigonometry::fullAngle2(float x, float y)
{
    float len = VectorCalc::length_v2<float>(x, y);
    float theta = acos(x / len);
    return (y > 0.0 ? theta : 2 * M_PI - theta);
}
