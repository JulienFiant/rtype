/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Settings
*/

#include "../include/Settings.hpp"

Settings::Settings()
{
    this->_file = "Settings.ini";
    this->_screenSizes = std::list<sf::Vector2u>{
        sf::Vector2u(4096, 2160),
        sf::Vector2u(1920, 1080),
        sf::Vector2u(1280, 720),
        sf::Vector2u(720, 480)};
}

Settings::~Settings()
{
}

const std::list<sf::Vector2u> Settings::getSizes() const
{
    return (this->_screenSizes);
}

const sf::Vector2u Settings::size() const
{
    return (*this->_currentSize);
}

sf::ContextSettings &Settings::context()
{
    return (this->_sfmlSettings);
}

sf::Uint32 &Settings::style()
{
    return (this->_sfmlStyle);
}

uint Settings::fps() const
{
    return (this->_fps);
}

bool Settings::fpsLimit() const
{
    return (this->_fpsLimit);
}

void Settings::selectSize(const int idx)
{
    this->_currentSize = this->_screenSizes.begin();
    std::advance(this->_currentSize, idx);
}

void Settings::selectSize(const std::list<sf::Vector2u>::iterator it)
{
    this->_currentSize = it;
}

bool Settings::load()
{
    this->_currentSize = ++(++(this->_screenSizes.begin()));
    this->_sfmlSettings.antialiasingLevel = 4;
    this->_sfmlStyle = sf::Style::Default;
    this->_fpsLimit = true;
    this->_fps = 60;

    std::ifstream ifs(this->_file);
    if (ifs.is_open())
    {
        std::string s;
        while (std::getline(ifs, s))
        {
            // TODO get settings from file
            if (s.find("size:") == 0)
            {
            }
            else if (s.find("antialiasing:") == 0)
            {
            }
            else if (s.find("style:") == 0)
            {
            }
            else if (s.find("res:") == 0)
            {
            }
            else if (s.find("fps:") == 0)
            {
            }
            else if (s.find("limit:") == 0)
            {
            }
        }
        return (true);
    }
    return (false);
}

bool Settings::save()
{
    std::ofstream ofs(this->_file);
    if (ofs.is_open())
    {
        ofs << "size:" << std::to_string(this->_currentSize->x) << "," << std::to_string(this->_currentSize->y) << std::endl;
        ofs << "antialiasing:" << std::to_string(this->_sfmlSettings.antialiasingLevel) << std::endl;
        ofs << "style:" << std::to_string(this->_sfmlStyle) << std::endl;
        ofs << "fps:" << std::to_string(this->_fps) << std::endl;
        ofs << "limit:" << std::to_string(this->_fpsLimit) << std::endl;
        ofs << "res:";
        std::list<std::string>::iterator var = this->_resFolders.begin();
        while (var != this->_resFolders.end())
        {
            ofs << *var;
            var++;
            if (var != this->_resFolders.end())
                ofs << ';';
        }
        return (true);
    }
    return (false);
}

Settings &Settings::get()
{
    static Settings settings;
    return (settings);
}
