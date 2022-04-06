#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Vecteur.h"

class Spaceship {
    public:
    Spaceship() = default;
    Spaceship(sf::Color const& color);
    void refreshState(sf::Event const& event);
    void update(float time);
    void display(sf::RenderWindow& fenetre) const;

    private:
    sf::Texture texture{};
    sf::Sprite sprite{};
    Vecteur speed{0.f, 0.f};
    bool accelerating{false};
    bool turnLeft{false};
    bool turnRight{false};

    static constexpr float ACCEL{5000.f};
    static constexpr float COEFF{2.f};
    static constexpr float ANGULAR_SPEED{50.f};
};


#endif // SPACESHIP_H_INCLUDED
