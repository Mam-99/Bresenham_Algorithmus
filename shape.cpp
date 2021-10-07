#include "shape.h"

void Shape::assertFrame( int testnumber, Frame *expected, Frame *actual )
{
    cout << "Test number: " << testnumber << " has ";
    if( expected->test(actual) ) cout << " passed. " << endl;
    else cout << " failed. " << endl;

    for( int i=high-1; i>=0; i-- ){
        for( int y=0; y<wide; y++ ){
            if( expected->on_frame(i, y) != actual->on_frame(i, y) )
                cout << "[" << i << "][" << y << "] is not both in excepted and on actual frame." << endl;
        }
    }
}

void Shape::assertBool( const int &testnumber, const bool &expected, const bool &actual )
{
    cout << "Test number: " << testnumber << " has ";
    if( expected == actual ) cout << "passed." << endl;
    else cout << "failed. " << endl;
}
