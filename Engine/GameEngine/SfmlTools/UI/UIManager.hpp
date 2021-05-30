/*
** EPITECH PROJECT, 2019
** Test_Lib
** File description:
** UIManager
*/

#ifndef UIMANAGER_HPP_
#define UIMANAGER_HPP_

#include "./UIBox.hpp"
#include <map>
#include <list>

class UIManager
{
  public:
    UIManager(int screenX, int screenY);
    ~UIManager();

    /** Adds a UIBox to the manager
     * id   :   name of the element. Cannot be empty nor already defined
     * item :   element to be added
     * */
    void add(std::string id, UIBox item);
    /** Remove an element by its id
     * id   :   name of the element to be removed
     * */
    void remove(std::string id);

    /** Returns a pointer to the element corresponding to the id
     * id   :   name of the element to be retrieved
     * */
    UIBox *edit(std::string id);
    /** Hide an element and its children
     * id   :   name of the elemnt to hide
     * */
    void hide(std::string id);
    /** Show an element and its children if they are not hidden
     * id   :   name of the elemnt to show
     * */
    void show(std::string id);

    /** Draw the elements not hidden on a SFML RenderWindow
     * window   :   window on which you want to draw
     *              the children are displayed on top of their parent
     * */
    void display(sf::RenderWindow &window);

    std::string to_string();
    static UIManager *fromFile(std::string file);
    static UIManager *fromString(std::string str);

    int screenX;
    int screenY;
  protected:
  private:
    bool displayParent(sf::RenderWindow &window, std::string id);
    sf::Vector2i calcReal(const sf::FloatRect target, const sf::FloatRect comp, const UIRelativator mode);
    void calcNewPos(UIBox *box);
    void organise(std::string id);
    std::list<std::string> _isOrg;
    std::list<std::string> _getOrg;
    std::list<std::string> _disp;
    std::map<std::string, UIBox> _elements;
};

#endif /* !UIMANAGER_HPP_ */
