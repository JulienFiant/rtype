/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IAudio
*/

#ifndef IAUDIO_HPP_
#define IAUDIO_HPP_

#include <SFML/Audio.hpp>
#include "../IEngine.hpp"

class IAudio
{
public:
    enum AudioType
    {
        Sound,
        Music,
    };

    virtual ~IAudio(){};

    virtual void load(const std::string &file) = 0;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual int getStatus() = 0;

protected:
    AudioType _type;
};

#endif /* !IAUDIO_HPP_ */
