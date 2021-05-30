/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AudioEngine
*/

#ifndef AUDIOENGINE_HPP_
#define AUDIOENGINE_HPP_

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <list>
#include <memory>
#include <algorithm>
#include "../Settings.hpp"
#include "../RessourceManager.hpp"
#include "../IEngine.hpp"
#include "./IAudio.h"
#include "./Sound.h"
#include "./Music.h"

class AudioEngine : public virtual IEngine
{
public:
    AudioEngine(const AudioEngine &) = delete;
    AudioEngine &operator=(const AudioEngine &) = delete;

    virtual bool init();
    virtual bool release();
    virtual bool reload();

    void load(const std::string &name, const std::string &file, IAudio::AudioType audioType);
    void play(const std::string &name);
    void pause(const std::string &name);
    void stop(const std::string &name);

    static AudioEngine &get();

protected:
private:
    AudioEngine();
    ~AudioEngine();

    std::list<MyMusic *> _sfMusics;
    std::list<MySound *> _sfSounds;

    std::unordered_map<std::string, IAudio *> _sounds;
};

#endif /* !AUDIOENGINE_HPP_ */
