/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>
#include "./IAudio.h"

class MyMusic : public virtual IAudio
{
public:
    MyMusic();
    ~MyMusic();

    virtual void load(const std::string &file);
    virtual void play();
    virtual void pause();
    virtual void stop();
    virtual int getStatus();

protected:
private:
    sf::Music _music;
};

#endif /* !MUSIC_HPP_ */
