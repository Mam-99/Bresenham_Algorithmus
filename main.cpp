#include <iostream>
#include "frame.h"
#include "shape.h"
#include "line.h"
#include <chrono>
using namespace std;

using namespace std::chrono;

int main() try
{
    line_test();

    Frame* frame = new Frame();
    Line l( 0, 0, 5, 5 );
    l.draw( frame );
    frame->show();

    Frame f;

    for(int i=5; i<=15; i++){
        for(int y=10; y<=20; y++){
            f.put_point(i,y);
        }
    }
    f.show();

    f.reset();

    Line linear(10, 30, 3, 3);
    linear.draw(&f);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    f.show();

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 -t1);

    cout << "Duration of Draw_function: " << time_span.count() << "s" << endl << endl;

    t1 = high_resolution_clock::now();

    cout << f << endl;

    t2 = high_resolution_clock::now();

    time_span = duration_cast<duration<double>>(t2-t1);

    cout << "Duration of Zuweisungsoperator_function: " << time_span.count() << endl;

    system("PAUSE");
    return 0;
}
catch(exception& e)
{
    std::cerr << "error: " << e.what();
    return -2;
}
catch(...)
{
    std::cerr << "unknown error";
    return -1;
}
