#ifndef FRAME_H
#define FRAME_H
#include <iostream>
#include <array>
using namespace std;

const int wide {55}; // Zeichen pro Frame-Zeile
const int high {34}; // Zeilen pro Frame

class Frame
{
public:
    enum color { black = ' ', white = '*' };
    Frame( );
    void put_point( int, int ); // Punkt im Frame speichern
    void reset( ); // Frame leeren
    void show( ) const; // Frame auf die Konsole ausgeben
    bool on_frame( int, int ) const; // "Clipping"
    friend ostream& operator<<(ostream& out, const Frame& f);

    bool test( Frame* actual );
private:
    array< std::array<char,wide>, high > frame;
};

#endif // FRAME_H
