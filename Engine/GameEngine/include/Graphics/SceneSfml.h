/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SceneSfml
*/

#ifndef SCENESFML_HPP_
#define SCENESFML_HPP_

#include <SFML/Graphics/Drawable.hpp>
#include <iostream>
#include <list>
#include "./AScene.hpp"
#include "./AGraphicComponent.hpp"
#include "./GraphicEngine.h"

typedef struct s_display_pair
{
    int layer;
    AGraphicComponent *component;
} displayPair;

class SceneSfml : public virtual AScene
{
public:
    SceneSfml(const std::string &name);
    ~SceneSfml(){};

    virtual std::string getName();

    void addElement(int layer, AGraphicComponent *element);
    displayPair *getElement(const std::string name);
    void removeElement(const std::string name);

    const std::list<displayPair> &items();

    virtual void draw();
    virtual bool interact();

protected:
private:
    std::list<displayPair> _items;
};

#endif /* !SCENESFML_HPP_ */
