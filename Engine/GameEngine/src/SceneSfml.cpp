/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Scene
*/

#include "../include/Graphics/SceneSfml.h"

SceneSfml::SceneSfml(const std::string &name)
{
    this->_name = name;
}

std::string SceneSfml::getName()
{
    return (this->_name);
}

void SceneSfml::addElement(int layer, AGraphicComponent *element)
{
    this->_items.push_back(displayPair{layer, element});
    this->_items.sort([](const displayPair &pair1, const displayPair &pair2) {
        return (pair1.layer < pair2.layer);
    });
}

displayPair *SceneSfml::getElement(const std::string name)
{
    for (auto var = this->_items.begin(); var != this->_items.end(); var++)
    {
        if (var->component->getName() == name)
            return (&(*var));
    }
    return (nullptr);
}

void SceneSfml::removeElement(const std::string name)
{
    for (auto var = this->_items.begin(); var != this->_items.end(); var++)
    {
        if (var->component->getName() == name)
        {
            this->_items.erase(var);
            break;
        }
    }
}

const std::list<displayPair> &SceneSfml::items()
{
    return (this->_items);
}

void SceneSfml::draw()
{
    for (auto var : this->_items)
    {
        var.component->draw();
    }
}

bool SceneSfml::interact()
{
    for (auto var : this->_items)
    {
        if (GraphicEngine::get().getHudUsage() == 0 || GraphicEngine::get().getHudUsage() == var.component->getId())
        {
            if (var.component->interact())
                return (true);
        }
    }
    return (false);
}