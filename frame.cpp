#include "frame.h"

Frame::Frame()
{
    for(int i=0; i<high; i++){
        for(int y=0; y<wide; y++){
            frame.at(i).at(y) = black;
        }
    }
}

void Frame::put_point(int x, int y)
{
    if(x >= wide || x<0) throw runtime_error("fail...");
    if(y >= high || y<0) throw runtime_error("fail...");

    frame.at(x).at(y) = white;
}

void Frame::reset()
{
    for(int i=0; i<high; i++){
        for(int y=0; y<wide; y++){
            frame.at(i).at(y) = black;
        }
    }
}

void Frame::show() const
{
    cout << "Draw_function: " << endl;
    cout << "    ";
    for (int col = 0; col < 55; col++) {
        cout << col / 10;
    }
    cout << endl;
    cout << "    ";
    for (int col = 0; col < 55; col++) {
        cout << col % 10;
    }
    cout << endl;

    for (int row = 33; row >= 0; row--) {
        if (row < 10) {
            cout << ' ';
        }
        cout << row << ": ";
        for (int col = 0; col < 55; col++) {
            cout.put( frame.at(row).at(col) );
        }
        cout << endl;
    }
}

ostream& operator<<(ostream& out, const Frame& f)
{
    out << "Zuweisungsoperator_function: " << endl;
    out << "    ";
    for (int col = 0; col < 55; col++) {
        out << col / 10;
    }
    out << endl;
    out << "    ";
    for (int col = 0; col < 55; col++) {
        out << col % 10;
    }
    out << endl;

    for (int row = 33; row >= 0; row--) {
        if (row < 10) {
            out << ' ';
        }
        out << row << ": ";
        for (int col = 0; col < 55; col++) {
            out << f.frame.at(row).at(col);
        }
        out << endl;
    }

    return out;
}

bool Frame::on_frame( int x, int y ) const
{
    if( x<0 || x>high ) return false;
    if( y<0 || y>wide ) return false;
    if( frame.at(x).at(y) == white ) return true;
    return false;
}

bool Frame::test( Frame *actual )
{
    for( int i=high-1; i>=0; i-- ){
        for( int y=0; y<wide; y++ ){
            if( this->on_frame(i, y) != actual->on_frame(i, y) ) return false;
        }
    }
    return true;
}

















