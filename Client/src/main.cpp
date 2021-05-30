/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main
*/

#include <GameEngine/include/Graphics.h>
#include <GameEngine/Network/ClientUdp.hpp>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void init()
{
    Settings::get().load();
    t_R::get().load({"./res/BaseRes"});
    GraphicEngine::get().init();
}

std::string getAddr()
{
    auto tb = new GCTextBox("testtb", "textbox", "epitech");
    auto btn = new GCBasic("menubtn", "btn");
    auto menu = new GCBasic("menuimg", "menu");

    tb->getText().setFillColor(sf::Color::White);
    GraphicEngine::get().getActiveScene().get()->addElement(-2, menu);
    GraphicEngine::get().getActiveScene().get()->addElement(-1, btn);
    GraphicEngine::get().getActiveScene().get()->addElement(-1, tb);
    menu->setPos(0.0f, 0.0f);
    tb->setPos(250.0f, 344.0f);
    btn->setPos(420.0f, 420.0f);
    while (GraphicEngine::get().getRWindow()->isOpen())
    {
        GraphicEngine::get().recordEvent();
        GraphicEngine::get().draw();
        auto evt = GraphicEngine::get().getEvent();
        if (evt.type == sf::Event::MouseButtonPressed && evt.mouseButton.button == sf::Mouse::Left && tb->getString() != "")
        {
            auto rect = btn->getRect();
            if (evt.mouseButton.x >= rect.left &&
                evt.mouseButton.x <= rect.left + rect.width &&
                evt.mouseButton.y >= rect.top &&
                evt.mouseButton.y <= rect.top + rect.height)
            {
                break;
            }
        }
    }
    std::string ret = tb->getString();

    return (ret);
}

std::vector<GCAnimated *> CreatePlayer(int id, ClientUdp *p)
{
    std::vector<GCAnimated *> item;

    for (int i = 0; i < 4; i++)
    {
        auto tmp = new GCAnimated("test", "r-typesheet42");
        tmp->setScale(2, 2);
        tmp->_kit.set(AnimationKit::Anim::IDLE, new AnimationBasic(sf::FloatRect(67, i * 17, 32, 18), AnimationBasic::RIGHT, 0, 0.4, false, 1), false);
        tmp->_kit.set(AnimationKit::Anim::MOVE_DW, new AnimationBasic(sf::FloatRect(67, i * 17, 32, 18), AnimationBasic::LEFT, 3, 0.4, false, 1), false);
        tmp->_kit.set(AnimationKit::Anim::MOVE_UW, new AnimationBasic(sf::FloatRect(67, i * 17, 32, 18), AnimationBasic::RIGHT, 3, 0.4, false, 1), false);
        tmp->_kit.use(AnimationKit::Anim::IDLE);
        sf::Vector2f center{Settings::get().size().x / 2.0f, Settings::get().size().y / 2.0f};
        tmp->setPos(0, 0);
        if (i == id)
            tmp->setInteraction([id, p]() {
                float ms = 5;
                bool ret = false;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                {
                    p->set_pos(id, p->get_all_pos()[id][0], (p->get_all_pos()[id][1] - ms) <= 0 ? 0 : (p->get_all_pos()[id][1] - ms));
                    ret = true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    p->set_pos(id, (p->get_all_pos()[id][0] - ms) <= 0 ? 0 : (p->get_all_pos()[id][0] - ms), p->get_all_pos()[id][1]);
                    ret = true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    p->set_pos(id, p->get_all_pos()[id][0], p->get_all_pos()[id][1] + ms);
                    ret = true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    p->set_pos(id, p->get_all_pos()[id][0] + ms, p->get_all_pos()[id][1]);
                    ret = true;
                }
                return (ret);
            });
        item.push_back(tmp);
        GraphicEngine::get().getActiveScene().get()->addElement(i, tmp);
    }
    return (item);
}

GCAnimated *CreateBackground()
{
    auto background = new GCAnimated("background", "background");
    background->setScale(3.5f, 3.5f);
    RessourceManager::get().setTextureLoop("background", true);
    background->_kit.set(AnimationKit::Anim::IDLE, new AnimationScroller(sf::FloatRect(0, 0, Settings::get().size().x, Settings::get().size().y), AnimationScroller::RIGHT, 30.0f, true));
    background->_kit.use(AnimationKit::Anim::IDLE);
    GraphicEngine::get().getActiveScene().get()->addElement(0, background);
    return (background);
}

int main(int ac, char **av)
{
    init();
    std::string ret = getAddr();
    ClientUdp *p = new ClientUdp(ret);
    p->create_cli();
    p->send_msg("salut");
    int id = atoi(p->recv_msg().c_str());
    p->recv_msg();
    GCAnimated * background = CreateBackground();
    std::vector<GCAnimated *> item = CreatePlayer(id, p);

    while (GraphicEngine::get().getRWindow()->isOpen())
    {
        GraphicEngine::get().recordEvent();
        GraphicEngine::get().draw();
        p->start_game();
        for (int i = 0; i < p->get_all_pos().size(); i++)
        {
            auto pos = p->get_all_pos()[i];
            item[i]->setPos(pos[0], pos[1]);
        }
    }
    return 0;
}
