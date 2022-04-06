#include <SFML/Graphics.hpp>
#include "Spaceship.h"

int main()
{
    sf::RenderWindow fenetre{sf::VideoMode{800, 600}, "Mon super jeu"};
    auto chrono = sf::Clock{};
    auto spaceShip = Spaceship{sf::Color::Green};
    while(fenetre.isOpen()) {
         auto evenement = sf::Event();

        while(fenetre.pollEvent(evenement)){

            if(evenement.type == sf::Event::Closed) {
                fenetre.close();
            }
        }
        spaceShip.refreshState(evenement);
        spaceShip.update(chrono.restart().asSeconds());

        fenetre.clear(sf::Color::White);
        spaceShip.display(fenetre);
        fenetre.display();
    }
    return 0;
}
