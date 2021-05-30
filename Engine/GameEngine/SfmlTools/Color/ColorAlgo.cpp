//
// EPITECH PROJECT, 2018
// ColorAlgo
// File description:
// color management
//

#include "ColorAlgo.hpp"
#include <iostream>

Color ColorAlgo::colorShift(double progress, Color left, Color right)
{
    int rgba[4] = {0, 0, 0, 0};
    int delta[4] = {right.r - left.r, right.g - left.g, right.b - left.b, right.a - left.a};

    rgba[0] = left.r + delta[0] * progress / 100.0;
    rgba[1] = left.g + delta[1] * progress / 100.0;
    rgba[2] = left.b + delta[2] * progress / 100.0;
    rgba[3] = left.a + delta[3] * progress / 100.0;
    return Color(rgba[0], rgba[1], rgba[2], (char)rgba[3]);
}

Color ColorAlgo::colorShift(double progress, std::vector<Color> colors, std::vector<double> percentages)
{
    int nb_steps = colors.size() - 1;
    double next_progress = 0.0;
    int left_idx = 0, right_idx = 0;
    progress = (progress >= 100) ? progress - (100 * (int)(progress / 100)) : (progress < 0) ? progress + (100 * ((int)(progress / -100) + 1)) : progress;
    if (nb_steps == -1)
        return Color(0, 0, 0, (char)0);
    else if (nb_steps == 0)
        return colors.at(0);
    if (colors.size() == percentages.size())
    {
        percentages[0] = 0;
        percentages[nb_steps] = 100;
        for (int i = 0; i < nb_steps; ++i)
        {
            if (percentages[i] <= progress && progress <= percentages[i + 1])
            {
                left_idx = i;
                right_idx = i + 1;
                break;
            }
        }
        next_progress = (progress - percentages[left_idx]) * 100.0 / (percentages[right_idx] - percentages[left_idx]);
    }
    else
    {
        left_idx = (int)(progress * nb_steps / 100.0);
        right_idx = (int)(progress * nb_steps / 100.0 + 1);
        next_progress = (progress - (100.0 / (double)nb_steps) * left_idx) / (1 / (double)nb_steps);
    }
    return ColorAlgo::colorShift(next_progress, colors.at(left_idx), colors.at(right_idx));
}

Color ColorAlgo::complement(Color color)
{
    return Color(255 - color.r, 255 - color.g, 255 - color.b);
}