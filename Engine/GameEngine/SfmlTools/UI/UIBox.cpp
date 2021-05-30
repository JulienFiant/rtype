/*
** EPITECH PROJECT, 2019
** Test_Lib
** File description:
** UIBox
*/

#include "UIBox.hpp"

UIBox::UIBox(sf::Shape *shape, std::string parent)
{
    this->shape = shape;
    _idParent = parent;
    _show = true;
    this->texture = new sf::Texture;
}

UIBox::~UIBox()
{
}

void UIBox::show(bool _show)
{
    this->_show = _show;
}

void UIBox::addRelative(UIRelativator relative)
{
    std::vector<UIRelativator>::iterator it = _alignment.begin();

    while (it != _alignment.end() && it->mode != relative.mode)
        ++it;
    if (it != _alignment.end())
        _alignment.erase(it);
    _alignment.push_back(relative);
}

void UIBox::ereaseRelative(Alignement alignement)
{
    std::vector<UIRelativator>::iterator it = _alignment.begin();

    while (it != _alignment.end() && it->mode != alignement)
        ++it;
    if (it != _alignment.end())
        _alignment.erase(it);
}

void UIBox::clearRelative()
{
    _alignment.clear();
}

void UIBox::setParent(const std::string parent)
{
    this->_idParent = parent;
}

bool UIBox::setTextureFile(const std::string str)
{
    if (texture->loadFromFile(str))
    {
        shape->setTexture(texture);
        tex_file = str;
    }
    else
        return (false);
    return (true);
}

const std::string &UIBox::getParentId()
{
    return (_idParent);
}

const bool &UIBox::getShowStatus()
{
    return (_show);
}

const std::vector<UIRelativator> &UIBox::getRelativator()
{
    return (_alignment);
}

sf::Texture *UIBox::getTexture()
{
    return (texture);
}

void UIBox::display(sf::RenderWindow &window)
{
    window.draw(*shape);
}

std::string UIBox::to_string()
{
    int count = shape->getPointCount();
    std::string s("{Shape,");

    s += std::to_string(count) + ",[";
    for (int i = 0; i < count; ++i)
        s += "{" + std::to_string(shape->getPoint(i).x) + "," + std::to_string(shape->getPoint(i).y) + ((i < count - 1) ? "}," : "}],");
    s += std::to_string(shape->getFillColor().toInteger()) + ",";
    s += "{Texture," + tex_file + "},";
    s += "{Alignement,[";
    for (std::vector<UIRelativator>::iterator rel = _alignment.begin(); rel != _alignment.end(); rel++)
        s += rel->to_string() + ((rel != _alignment.end() - 1) ? "," : "]},");
    s += "{Parent," + _idParent + "}" + "}";
    return (s);
}

UIBox *UIBox::fromFile(std::string file)
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

UIBox *UIBox::fromString(std::string str)
{
    std::string s_tmp;
    UIBox *box;
    int b = 0;
    int e = -1;

    if (str[0] == '{')
        str = Parser::stringFromLimiter(str, b, e, "{", "}");
    Parser parse("Box", str, ",");
    if (parse.tab[0].compare("Shape") == 0)
    {
        sf::ConvexShape tmpShape(std::stoi(parse.tab[1]));
        b = str.find_first_of("]") + 2;
        std::string s_tmp = Parser::stringFromLimiter(str, 5, -1, "[", "]");
        Parser parse_pt("Points", s_tmp, "},{");
        int i = 0;
        for (std::string &pt : parse_pt.tab)
        {
            pt = Parser::stringFromLimiter(pt, 0, -1, "{", "}");
            parse_pt.addSubParser(std::to_string(i), ",", i);
            Parser *tmp = parse_pt.fetchSubParser(std::to_string(i));
            tmpShape.setPoint(i, sf::Vector2f(std::stof(tmp->tab[0]), std::stof(tmp->tab[1])));
            ++i;
        }
        box = new UIBox(new sf::ConvexShape(tmpShape));
        s_tmp = Parser::stringFromLimiter(str, b, e, " ", ",{");
        b += s_tmp.length() + 1;
        box->shape->setFillColor(sf::Color(std::stoul(s_tmp)));
    }
    s_tmp = Parser::stringFromLimiter(str, b, e, "{", "}");
    Parser parse_coin("coin", s_tmp, ",");
    if (parse_coin.tab[0].compare("Texture") == 0)
    {
        if (parse_coin.tab.size() == 2)
            box->setTextureFile(parse_coin.tab[1]);
    }
    b += s_tmp.length() + 2;
    b = str.find_first_of("{", b);
    s_tmp = Parser::stringFromLimiter(str, b, e, "{", "}");
    parse_coin = Parser("coin", s_tmp, ",[");
    if (parse_coin.tab[0].compare("Alignement") == 0)
    {
        if (parse_coin.tab.size() == 2)
        {
            Parser parse_pt("align", parse_coin.tab[1], "},{");
            for (std::string &pt : parse_pt.tab)
                box->addRelative(*UIRelativator::fromString(pt));
        }
    }
    b += s_tmp.length() + 2;
    b = str.find_first_of("{", b);
    s_tmp = Parser::stringFromLimiter(str, b, e, "{", "}");
    parse_coin = Parser("coin", s_tmp, ",");
    if (parse_coin.tab[0].compare("Parent") == 0)
    {
        if (parse_coin.tab.size() == 2)
        {
            box->setParent(parse_coin.tab[1]);
        }
    }
    return (box);
}