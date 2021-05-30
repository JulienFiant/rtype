/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <iostream>
#include <fstream>
#include <list>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/WindowStyle.hpp>

class Settings
{
public:
    Settings(const Settings &) = delete;
    Settings &operator=(const Settings &) = delete;
    const std::list<sf::Vector2u> getSizes() const;
    const sf::Vector2u size() const;
    sf::ContextSettings &context();
    sf::Uint32 &style();
    uint fps() const;
    bool fpsLimit() const;
    void selectSize(const int idx);
    void selectSize(const std::list<sf::Vector2u>::iterator it);

    bool load();
    bool save();
    static Settings &get();

private:
    Settings();
    ~Settings();

    std::string _file;
    std::list<sf::Vector2u> _screenSizes;
    std::list<sf::Vector2u>::iterator _currentSize;
    sf::ContextSettings _sfmlSettings;
    uint _fps;
    bool _fpsLimit;
    sf::Uint32 _sfmlStyle;
    std::list<std::string> _resFolders;
};

#endif /* !SETTINGS_HPP_ */
