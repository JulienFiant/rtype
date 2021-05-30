/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AudioEngine
*/

#include "../include/Audio/AudioEngine.h"

AudioEngine::AudioEngine()
{
}

AudioEngine::~AudioEngine()
{
}

bool AudioEngine::init()
{
    for (int i = 0; i < 2; i++)
        this->_sfMusics.push_back(new MyMusic());
    for (int i = 0; i < 2; i++)
        this->_sfSounds.push_back(new MySound());
    return (true);
}

bool AudioEngine::release()
{
    return (false);
}

bool AudioEngine::reload()
{
    return (false);
}

void AudioEngine::load(const std::string &name, const std::string &file, IAudio::AudioType audioType)
{
    if (audioType == IAudio::AudioType::Music)
    {
        auto i = this->_sfMusics.begin();
        while (i != this->_sfMusics.end())
        {
            if ((*i)->getStatus() == sf::SoundSource::Status::Stopped)
            {
                (*i)->load(file);
                this->_sounds[name] = *i;
                return;
            }
            i++;
        }

    }
    else if (audioType == IAudio::AudioType::Sound)
    {
        auto i = this->_sfSounds.begin();
        while (i != this->_sfSounds.end())
        {
            if ((*i)->getStatus() == sf::SoundSource::Status::Stopped)
            {
                (*i)->load(file);
                this->_sounds[name] = *i;
                return;
            }
            i++;
        }
    }
}

void AudioEngine::play(const std::string &name)
{
    auto tmp = this->_sounds.find(name);
    if (tmp != this->_sounds.end())
    {
        tmp->second->play();
    }
}

void AudioEngine::pause(const std::string &name)
{
    auto tmp = this->_sounds.find(name);
    if (tmp != this->_sounds.end())
    {
        tmp->second->pause();
    }
}

void AudioEngine::stop(const std::string &name)
{
    auto tmp = this->_sounds.find(name);
    if (tmp != this->_sounds.end())
    {
        tmp->second->stop();
    }
}

AudioEngine &AudioEngine::get()
{
    static AudioEngine engine;
    return (engine);
}
