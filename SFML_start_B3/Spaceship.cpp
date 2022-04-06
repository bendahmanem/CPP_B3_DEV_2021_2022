#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(sf::Color const& color) {
    if(!texture.loadFromFile("ressources/vaisseau.png")) {
        std::cerr << "Image not found" << std::endl;
    }
    texture.loadFromFile("ressources/vaisseau.png");
    sprite.setTexture(texture);
    sprite.setColor(color);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(50, 50);
}

void Spaceship::refreshState(sf::Event const& event) {
    accelerating = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
     turnLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    turnRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Spaceship::update(float time) {
    if(accelerating) {
        speed += Vecteur::speedFromAngle(ACCEL * time, sprite.getRotation());
    }
    speed -= speed * COEFF * time;
    auto deplacement = speed * time;
    sprite.move(deplacement.x, deplacement.y);
    if(turnLeft) {
        sprite.rotate(- ANGULAR_SPEED * time);
    }
    if(turnRight) {
        sprite.rotate( ANGULAR_SPEED * time);
    }
}

void Spaceship::display(sf::RenderWindow& fenetre)const {
    fenetre.draw(sprite);
}
