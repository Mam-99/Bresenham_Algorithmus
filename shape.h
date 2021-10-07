#ifndef SHAPE_H
#define SHAPE_H
#include <frame.h>

class Shape
{
public:
    Shape(){
        prev = NULL;
    } // Skizze Standardkonstruktor
    virtual void draw( Frame* ptarget ) const = 0; // rein virtuelle Methode
    virtual void move( int hor, int ver ) = 0; // rein virtuelle Methode

    // Testen
    void assertFrame( int testnumber, Frame* expected, Frame* actual ); //ADDED METHOD TESTING PURPOSES
    void assertBool( const int& testnumber, const bool& expected, const bool& actual );
private:
    //static Shape* last; // Zeiger auf die zuletzt erzeugte Figur (d.h. Listenanfang)
    Shape* prev; // Zeiger auf die zuvor erzeugte Figur
};

//Shape* Shape::last = nullptr; // initialisiert den static Member mit dem Nullzeiger
//void show_all_shapes( Frame* ); // gibt alle Shape Objekte auf Frame* aus

#endif // SHAPE_H
