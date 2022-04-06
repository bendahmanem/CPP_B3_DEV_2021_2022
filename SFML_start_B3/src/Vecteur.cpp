#include "Vecteur.h"
#include <cmath>

void Vecteur::operator+=(Vecteur const& other) {
    x += other.x;
    y += other.y;
}

void Vecteur::operator-=(Vecteur const& other) {
    x -= other.x;
    y -= other.y;
}

Vecteur Vecteur::operator*(float coefficient) const {
    return {x*coefficient, y*coefficient};
}

Vecteur Vecteur::speedFromAngle(float size, float angleInDegree) {
    return {size*cos(angleInDegree/180.f*static_cast<float>(3.14)), size*sin(angleInDegree/180.f*3.14)};
}
