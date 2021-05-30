/*
** EPITECH PROJECT, 2019
** Test_Lib
** File description:
** UIManager
*/

#include "UIManager.hpp"

void addToList(std::list<std::string> &list, std::string str)
{
    std::list<std::string>::iterator it = list.begin();

    while (it != list.end())
    {
        if (str.compare(*it) == 0)
            break;
        it++;
    }
    if (it == list.end())
        list.push_back(str);
}

void removeFromList(std::list<std::string> &list, std::string str)
{
    std::list<std::string>::iterator it = list.begin();

    while (it != list.end())
    {
        if (str.compare(*it) == 0)
        {
            list.erase(it);
            break;
        }
        it++;
    }
}

int findInList(std::list<std::string> &list, std::string str)
{
    int idx = 0;

    for (std::list<std::string>::iterator it = list.begin(); it != list.end(); it++)
    {
        if (str.compare(*it) == 0)
        {
            return (idx);
        }
        ++idx;
    }
    return (-1);
}

UIManager::UIManager(int screenX, int screenY)
{
    this->screenX = screenX;
    this->screenY = screenY;
}

UIManager::~UIManager()
{
}

void UIManager::add(std::string id, UIBox item)
{
    if (id.empty())
    {
        std::cerr << "Id cannot be empty" << std::endl;
    }
    else if (id.compare(item.getParentId()) == 0)
    {
        std::cerr << "Element with key '" << id << "' not inserted because self-parenting is not alowed" << std::endl;
    }
    else if (!_elements.insert(std::make_pair(id, item)).second)
    {
        std::cerr << "Element with key '" << id << "' not inserted because already existing" << std::endl;
    }
    //    std::cout << _elements.size() << std::endl;
}

void UIManager::remove(std::string id)
{
    _elements.erase(_elements.find(id));
}

UIBox *UIManager::edit(std::string id)
{
    return (&((_elements.find(id))->second));
}

void UIManager::hide(std::string id)
{
    _elements.find(id)->second.show(false);
}

void UIManager::show(std::string id)
{
    _elements.find(id)->second.show(true);
}

bool UIManager::displayParent(sf::RenderWindow &window, std::string id)
{
    if (id.compare("") != 0)
    {

        if (displayParent(window, _elements.find(id)->second.getParentId()) && _elements.find(id)->second.getShowStatus() == true && findInList(_disp, id) == -1)
        {
            //            std::cout << id << " " << displayParent(window, _elements.find(id)->second.getParentId()) << " " << _elements.find(id)->second.getShowStatus() << " " << findInList(_disp, id) << std::endl;
            _elements.find(id)->second.display(window);
            addToList(_disp, id);
            return (true);
        }
        if (findInList(_disp, id) == -1)
            return (false);
    }
    return (true);
}

void UIManager::display(sf::RenderWindow &window)
{
    for (std::map<std::string, UIBox>::iterator it = _elements.begin(); it != _elements.end(); it++)
        organise(it->first);
    for (std::map<std::string, UIBox>::iterator it = _elements.begin(); it != _elements.end(); it++)
        displayParent(window, it->first);
    _disp.clear();
    _isOrg.clear();
    _getOrg.clear();
}

sf::Vector2i UIManager::calcReal(const sf::FloatRect target, const sf::FloatRect comp, const UIRelativator rel)
{
    sf::Vector2i npos(0, 0);

    switch (rel.mode)
    {
    case Alignement::OVER:
    {
        npos.y = comp.top - target.height;
        break;
    }
    case Alignement::TOP_TO_TOP:
    {
        npos.y = comp.top;
        break;
    }
    case Alignement::MID_H:
    {
        npos.y = comp.top + comp.height / 2 - target.height / 2;
        break;
    }
    case Alignement::BOT_TO_BOT:
    {
        npos.y = comp.top + comp.height - target.height;
        break;
    }
    case Alignement::UNDER:
    {
        npos.y = comp.top + comp.height;
        break;
    }
    case Alignement::BEFORE:
    {
        npos.x = comp.left - target.width;
        break;
    }
    case Alignement::LEFT_TO_LEFT:
    {
        npos.x = comp.left;
        break;
    }
    case Alignement::MID_W:
    {
        npos.x = comp.left + comp.width / 2 - target.width / 2;
        break;
    }
    case Alignement::RIGHT_TO_RIGHT:
    {
        npos.x = comp.left + comp.width - target.width;
        break;
    }
    case Alignement::AFTER:
    {
        npos.x = comp.left + comp.width;
        break;
    }
    default:
        break;
    }
    if (rel.mode < Alignement::BEFORE)
        npos.y += rel.offset;
    else
        npos.x += rel.offset;
    return (npos);
}

void UIManager::calcNewPos(UIBox *box)
{
    auto rect = box->shape->getGlobalBounds();
    int npos[] = {0, 0};
    sf::Vector2i tmp;
    int count[] = {0, 0};
    auto rels = box->getRelativator();
    sf::FloatRect tRect(0, 0, 0, 0);

    if (rels.size() > 0)
    {
        for (auto rel : rels)
        {
            std::map<std::string, UIBox>::iterator it = _elements.find(rel.idRelative);

            if (rel.mode < Alignement::BEFORE)
                ++count[1];
            else
                ++count[0];
            if (it != _elements.end())
                tRect = it->second.shape->getGlobalBounds();
            else if ((it = _elements.find(box->getParentId())) != _elements.end())
                tRect = it->second.shape->getGlobalBounds();
            else
                tRect = sf::FloatRect(0, 0, screenX, screenY);
            tmp = calcReal(rect, tRect, rel);
            npos[0] += tmp.x;
            npos[1] += tmp.y;
        }
        if (count[0] > 0)
            npos[0] = npos[0] / count[0];
        else
            npos[0] = rect.left;
        if (count[1] > 0)
            npos[1] = npos[1] / count[1];
        else
            npos[1] = rect.top;
        box->shape->setPosition(npos[0], npos[1]);
    }
}

void UIManager::organise(std::string id)
{
    std::map<std::string, UIBox>::iterator box = _elements.find(id);
    if (box != _elements.end() && findInList(_isOrg, id) == -1)
    {
        if (!box->second.getParentId().empty())
            organise(box->second.getParentId());
        calcNewPos(&box->second);
        addToList(_isOrg, id);
    }
}

std::string UIManager::to_string()
{
    std::string s = "{";

    s += std::to_string(this->screenX) + ",";
    s += std::to_string(this->screenY) + ",[";
    for (auto b = _elements.begin(); b != _elements.end(); b++)
    {
        auto tmp = b;
        tmp++;
        s += "{" + b->first + "," + b->second.to_string();
        if (tmp != _elements.end())
            s += "},";
        else
            s += "}]}";
    }
    return (s);
}

UIManager *UIManager::fromFile(std::string file)
{
    std::ifstream ifs;
    std::string s;

    ifs.open(file);

    if (!ifs.is_open())
        return (nullptr);
    getline(ifs, s);
    if (s.empty())
        return (nullptr);
    ifs.close();
    return (fromString(s));
}

UIManager *UIManager::fromString(std::string str)
{
    std::string s_tmp;
    UIManager *manager;
    int b = 0;
    int e = -1;

    str = Parser::stringFromLimiter(str, b, e, "{", "}");
    Parser parse("Manager", str, ",");
    manager = new UIManager(std::stol(parse.tab[0]), std::stol(parse.tab[1]));
    b += parse.tab[0].length() + parse.tab[1].length() + 2;
    str = Parser::stringFromLimiter(str, b, e, "[", "]");
    b = 0;
    std::cout << std::endl;
    while (b < str.length())
    {
        s_tmp = Parser::stringFromLimiter(str, b, e, "{", "}");
        Parser box("box", s_tmp, ",");
        manager->add(box.tab[0], *UIBox::fromString(Parser::stringFromLimiter(s_tmp, box.tab[0].length(), e, "{", "}")));
        b += s_tmp.length() + 3;
    }
    return (manager);
}