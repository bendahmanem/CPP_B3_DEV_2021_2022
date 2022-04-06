#ifndef VECTEUR_H
#define VECTEUR_H


struct Vecteur
{
    public:
        void operator+=(Vecteur const& other);
        void operator-=(Vecteur const& other);
        Vecteur operator*(float coefficient) const;
        static Vecteur speedFromAngle(float size, float angleInDegree);
        float x{0.f};
        float y{0.f};
};

#endif // VECTEUR_H
