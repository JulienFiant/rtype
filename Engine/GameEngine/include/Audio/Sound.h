/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <SFML/Audio.hpp>
#include "./IAudio.h"

class MySound : public virtual IAudio
{
public:
    MySound();
    ~MySound();

    virtual void load(const std::string &file);
    virtual void play();
    virtual void pause();
    virtual void stop();
    virtual int getStatus();

protected:
private:
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
};

#endif /* !SOUND_HPP_ */
