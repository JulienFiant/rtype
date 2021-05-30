/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GCTextBox
*/

#include "../include/Graphics/GCTextBox.h"
#define MIN(x, y) (x < y ? x : y)

GCTextBox::GCTextBox(const std::string &name, const std::string &texture, const std::string &font)
{
    this->_name = name;
    this->_texture = texture;
    this->_font = font;
    this->_id = RessourceManager::attributeId();
    this->init();
}

GCTextBox::GCTextBox(GCTextBox &entity)
{
    this->_name = entity._name;
    this->_texture = entity._texture;
    this->_sprite = entity._sprite;
    this->_font = entity._font;
    this->_text = entity._text;
    this->init();
}

bool GCTextBox::init()
{
    this->_maxChar = -1;
    this->_active = false;
    this->_inputLocking = true;
    auto tex = t_R::get().getTexture(this->_texture);
    if (tex)
        this->_sprite.setTexture(*tex);
    auto font = t_R::get().getFont(this->_font);
    if (font)
        this->_text.setFont(*font);
    this->setInteraction([this]() {
        auto evt = GraphicEngine::get().getEvent();
        if (evt.type == sf::Event::MouseButtonPressed && evt.mouseButton.button == sf::Mouse::Left)
        {
            auto rect = this->_sprite.getGlobalBounds();
            if (_active == false &&
                evt.mouseButton.x >= rect.left &&
                evt.mouseButton.x <= rect.left + rect.width &&
                evt.mouseButton.y >= rect.top &&
                evt.mouseButton.y <= rect.top + rect.height)
            {
                this->_active = true;
                GraphicEngine::get().setHudUsage(_id);
                return (true);
            }
            else if (_active == true && !(evt.mouseButton.x >= rect.left &&
                                          evt.mouseButton.x <= rect.left + rect.width &&
                                          evt.mouseButton.y >= rect.top &&
                                          evt.mouseButton.y <= rect.top + rect.height))
            {
                this->_active = false;
                GraphicEngine::get().setHudUsage(0);
            }
        }
        else if (_active == true && (evt.type == sf::Event::TextEntered))
        {
            if (evt.text.unicode < 128)
            {
                if (evt.text.unicode == 8)
                {
                    if (_str.length() > 0)
                        _str.pop_back();
                }
                else if (evt.text.unicode == 13)
                {
                    int size = MIN(_maxChar, _str.length());
                    if (_maxChar < 0)
                        size = _str.length();
                    _text.setString(_str.substr(0, size));
                    this->_active = false;
                    GraphicEngine::get().setHudUsage(0);
                }
                else
                    _str += evt.text.unicode;
            }
            if (_text.getLocalBounds().left + _text.getLocalBounds().width > _sprite.getLocalBounds().left + _sprite.getLocalBounds().width - 2 * _text.getCharacterSize())
            {
                if (_maxChar < 0)
                    _maxChar = _str.length();
                int size = MIN(_maxChar, _str.length());
                _text.setString(_str.substr(_str.length() - size, size));
            }
            else
            {
                _maxChar = -1;
                _text.setString(_str);
            }
            _text.setPosition(_sprite.getPosition().x + ((_sprite.getLocalBounds().width - _text.getLocalBounds().width) / 2.0f),
                              _sprite.getPosition().y + ((_sprite.getLocalBounds().height - _text.getLocalBounds().height - _text.getCharacterSize()) / 2.0f));
            return (true);
        }
        return (false);
    });
    this->_text.setCharacterSize((float)this->_sprite.getTextureRect().height * this->_sprite.getScale().y / 2.0);
    this->_text.setPosition(this->_sprite.getPosition().x + ((_sprite.getLocalBounds().width - _text.getLocalBounds().width) / 2.0f),
                            this->_sprite.getPosition().y + ((_sprite.getLocalBounds().height - _text.getLocalBounds().height ) / 2.0f));
    return (true);
}

bool GCTextBox::release()
{
    return (true);
}

bool GCTextBox::reload()
{
    auto tex = t_R::get().getTexture(this->_name);
    auto font = t_R::get().getFont(this->_font);
    if (tex)
        this->_sprite.setTexture(*tex);
    if (font)
        this->_text.setFont(*font);

    return (false);
}

bool GCTextBox::draw()
{
    //    std::cout << "draw " << _name << std::endl;
    GraphicEngine::get().getRWindow()->draw(_sprite);
    GraphicEngine::get().getRWindow()->draw(_text);
    return (true);
}

sf::Text &GCTextBox::getText()
{
    return (this->_text);
}

const std::string &GCTextBox::getString() const
{
    return (this->_str);
}

void GCTextBox::setPos(float x, float y)
{
    this->_sprite.setPosition(x, y);
    this->_text.setPosition(this->_sprite.getPosition().x, this->_sprite.getPosition().y);
}

void GCTextBox::setPos(sf::Vector2f npos)
{
    this->_sprite.setPosition(npos);
    this->_text.setPosition(this->_sprite.getPosition().x, this->_sprite.getPosition().y);
}

void GCTextBox::setScale(float x, float y)
{
    this->_maxChar = -1;
    this->_sprite.setScale(x, y);
    this->_text.setScale(x, y);
    /*    this->_text.setCharacterSize((float)this->_sprite.getTextureRect().height * this->_sprite.getScale().y / 2.0);
    this->_text.setPosition(this->_sprite.getPosition().x, this->_sprite.getPosition().y); */
}

void GCTextBox::setScale(sf::Vector2f scale)
{
    this->_maxChar = -1;
    this->_sprite.setScale(scale);
    this->_text.setScale(scale);
    /*    this->_text.setCharacterSize((float)this->_sprite.getTextureRect().height * this->_sprite.getScale().y / 2.0);
    this->_text.setPosition(this->_sprite.getPosition().x, this->_sprite.getPosition().y); */
}

void GCTextBox::setRotation(float rotation)
{
    this->_sprite.setRotation(rotation);
    this->_text.setRotation(rotation);
}

void GCTextBox::setRotation(sf::Vector2f rotation)
{
    auto angle = Trigonometry::fullAngle2(rotation.x, rotation.y);
    this->_sprite.setRotation(angle);
    this->_text.setRotation(angle);
}