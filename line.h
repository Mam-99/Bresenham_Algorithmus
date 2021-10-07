#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape
{
public:
    Line() = delete; // keine Standardlinie
    Line( int, int, int, int ); // ein Konstruktor
    void set( int, int, int, int );
    void draw( Frame* ) const; // rein virtuelles shape::draw() ueberschreiben
    void move( int h, int v ); // rein virtuelles shape::move() ueberschreiben
    int sgn(int x) const;
private:
    int start_x, start_y, end_x, end_y;
};

void line_test();
#endif // LINE_H
