/*
** EPITECH PROJECT, 2019
** Test_Lib
** File description:
** UIBox
*/

#ifndef UIBOX_HPP_
#define UIBOX_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "../Color/Color.hpp"
#include "UIRelativator.hpp"

class UIRelativator;

class UIBox
{
  public:
    UIBox(sf::Shape *shape, std::string idParent = "");
    ~UIBox();

    void show(bool show);
    void addRelative(UIRelativator relative);
    void ereaseRelative(Alignement alignement);
    void clearRelative();
    void setParent(const std::string parentId);
    bool setTextureFile(const std::string str);

    const std::string &getParentId();
    const bool &getShowStatus();
    const std::vector<UIRelativator> &getRelativator();
    sf::Texture *getTexture();

    void display(sf::RenderWindow &window);

    std::string to_string();
    static UIBox *fromFile(std::string file);
    static UIBox *fromString(std::string str);

    sf::Shape *shape;

  protected:
    sf::Texture *texture;
    std::vector<UIRelativator> _alignment;
    std::string _idParent;
    bool _show;
    std::string tex_file;
};

#endif /* !UIBOX_HPP_ */
