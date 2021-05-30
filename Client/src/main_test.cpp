/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main
*/

#include <GameEngine/include/Graphics.h>
#include <GameEngine/Network/ClientUdp.hpp>
#include <GameEngine/include/Physics.h>

void init()
{
    Settings::get().load();
    t_R::get().load({"./res"});
    GraphicEngine::get().init();
}

int main()
{
    init();
    auto item = new CPhysicAnimated("test", "r-typesheet1");
    auto tb = new GCTextBox("testtb", "textbox", "epitech");
        tb->setPos(218.0f, 344.0f);

    auto background = new GCAnimated("background", "background");
    RessourceManager::get().setTextureLoop("background", true);
    background->setScale(2.5f,2.5f);
    background->_kit.set(AnimationKit::Anim::IDLE, new AnimationScroller(sf::FloatRect(0,0, Settings::get().size().x, Settings::get().size().y), AnimationScroller::RIGHT, 30.0f, true));
    item->_kit.set(AnimationKit::Anim::IDLE, new AnimationBasic(sf::FloatRect(2, 51, 32, 32), AnimationBasic::RIGHT, 8, 0.4, true), true);
    float ms = 40;

    item->setInteraction([item, ms]() {
        auto evt = GraphicEngine::get().getEvent();
        bool ret = false;
        if (evt.type == sf::Event::KeyPressed)
        {
            if (evt.key.code == sf::Keyboard::Space)
            {
                if (item->_kit.inUse()->getStatus() == AAnimation::Status::PAUSE)
                {
                    item->_kit.inUse()->play();
                }
                else if (item->_kit.inUse()->getStatus() == AAnimation::Status::PLAY)
                {
                    item->_kit.inUse()->pause();
                }
                ret = true;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Q) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            item->clearTrans();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                item->addVector(Physics::PhysicComponent::PhysScales::POS, sf::Vector2f(0, -ms));
                ret = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                item->addVector(Physics::PhysicComponent::PhysScales::POS, sf::Vector2f(-ms, 0));
                ret = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                item->addVector(Physics::PhysicComponent::PhysScales::POS, sf::Vector2f(0, ms));
                ret = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                item->addVector(Physics::PhysicComponent::PhysScales::POS, sf::Vector2f(ms, 0));
                ret = true;
            }
        }
        return (ret);
    });

    sf::Vector2f center{Settings::get().size().x / 2.0f, Settings::get().size().y / 2.0f};
    item->setPos(center);

    GraphicEngine::get().getActiveScene().get()->addElement(0, tb);
    GraphicEngine::get().getActiveScene().get()->addElement(0, background);
    GraphicEngine::get().getActiveScene().get()->addElement(1, item);
    std::string cmd = "";
    while (GraphicEngine::get().getRWindow()->isOpen())
    {
        GraphicEngine::get().recordEvent();
        GraphicEngine::get().draw();
    }
    return 0;
}
