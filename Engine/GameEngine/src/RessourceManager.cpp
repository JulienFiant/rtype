/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** RessourceManager
*/

#include "../include/RessourceManager.hpp"

RessourceManager::RessourceManager()
{
}

RessourceManager::~RessourceManager()
{
}

void list_dir(const char *path)
{
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL)
    {
        return;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        std::string name = entry->d_name;
        std::string fpath(path);
        if (fpath[fpath.length() - 1] != '/')
            fpath += '/';
        fpath.append(name);
        if (entry->d_type == DT_DIR && entry->d_name[0] != '.')
        {
            list_dir(fpath.c_str());
        }
        else
        {
            name = name.substr(0, name.rfind('.'));
            if (fnmatch("*.gif", fpath.c_str(), FNM_CASEFOLD) == 0 ||
                fnmatch("*.png", fpath.c_str(), FNM_CASEFOLD) == 0 ||
                fnmatch("*.jpg", fpath.c_str(), FNM_CASEFOLD) == 0)
            {
                sf::Texture tex;
                if (tex.loadFromFile(fpath))
                {
                    if (t_R::get()._rTexture.find(name) != t_R::get()._rTexture.end())
                        t_R::get()._rTexture[name].update(tex);
                    else
                        t_R::get()._rTexture[name] = tex;
                }
            }
            if (fnmatch("*.wmv", fpath.c_str(), FNM_CASEFOLD) == 0 ||
                fnmatch("*.ogg", fpath.c_str(), FNM_CASEFOLD) == 0 ||
                fnmatch("*.mp3", fpath.c_str(), FNM_CASEFOLD) == 0)
            {
                t_R::get()._rSound[name] = fpath;
            }
            if (fnmatch("*.so", fpath.c_str(), FNM_CASEFOLD) == 0)
            {
                t_R::get()._rLibs[name] = fpath;
            }
            if (fnmatch("*.ttf", fpath.c_str(), FNM_CASEFOLD) == 0)
            {
                sf::Font font;
                if (font.loadFromFile(fpath))
                {
                    t_R::get()._rFont[name] = font;
                }
            }
        }
    }
    closedir(dir);
}

bool RessourceManager::load(std::list<std::string> resFolders)
{
    for (auto var : resFolders)
    {
        list_dir(var.c_str());
    }
    return (true);
}

void RessourceManager::setTextureLoop(std::string name, bool loop)
{
    auto var = this->_rTexture.find(name);
    if (var != this->_rTexture.end())
        var->second.setRepeated(loop);
}


bool RessourceManager::release()
{
    this->_rLibs.clear();
    this->_rFont.clear();
    this->_rSound.clear();
    this->_rTexture.clear();
    return (true);
}

std::string RessourceManager::getLibs(const std::string &name)
{
    if (_rLibs.find(name) != _rLibs.end())
        return (_rLibs.find(name)->second);
    else
        return ("");
}

sf::Font *RessourceManager::getFont(const std::string &name)
{
    if (_rFont.find(name) != _rFont.end())
        return (&_rFont.find(name)->second);
    else
        return (nullptr);
}

std::string RessourceManager::getSound(const std::string &name)
{
    if (_rSound.find(name) != _rSound.end())
        return (_rSound.find(name)->second);
    else
        return ("");
}

sf::Texture *RessourceManager::getTexture(const std::string &name)
{
    if (_rTexture.find(name) != _rTexture.end())
        return (&_rTexture.find(name)->second);
    else
        return (nullptr);
}

ulong RessourceManager::attributeId()
{
    static ulong id = 10239;
    return (id++);
}

RessourceManager &RessourceManager::get()
{
    static RessourceManager manager;
    return (manager);
}