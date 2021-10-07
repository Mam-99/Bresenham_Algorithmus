ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
public:
    Square() = delete; // kein Standardquadrat
    Square( int swx, int swy, int len ); // ein Konstruktor
    void draw( Frame* ) const; // rein virtuelles shape::draw() ueberschreiben
    void move( int h, int v ); // rein virtuelles shape::move() ueberschreiben
    int getx() const;
    int gety() const;
    int getlen() const;
private:
    int sw_x, sw_y, len;
};

#endif // SQUARE_H
