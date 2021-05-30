/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** RessourceManager
*/

#ifndef RESSOURCEMANAGER_HPP_
#define RESSOURCEMANAGER_HPP_

#include <map>
#include <memory>
#include <list>
#include <functional>
#include <iostream>
#include <fnmatch.h>
#include <dirent.h>
#include <sys/types.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

typedef class RessourceManager
{
public:
    RessourceManager(const RessourceManager&) = delete;
    RessourceManager& operator=(const RessourceManager&) = delete;

    bool load(std::list<std::string> resFolders);
    bool release();

    std::string getLibs(const std::string &name);
    sf::Font *getFont(const std::string &name);
    std::string getSound(const std::string &name);
    sf::Texture *getTexture(const std::string &name);

    static RessourceManager &get();

    static ulong attributeId();
    void setTextureLoop(std::string name, bool loop);
    std::map<std::string, std::string> _rLibs;
    std::map<std::string, sf::Font> _rFont;
    std::map<std::string, std::string> _rSound;
    std::map<std::string, sf::Texture> _rTexture;

private:
    RessourceManager();
    ~RessourceManager();
} t_R;

#endif /* !RESSOURCEMANAGER_HPP_ */
