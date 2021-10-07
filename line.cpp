#include "line.h"

Line::Line( int sx, int sy, int ex, int ey ) // Skizze Konstuktordefinition
    : start_x{sx}, start_y{sy}, end_x{ex}, end_y{ey}
{
    //    if(start_x > end_x){
    //        start_x = ex;
    //        start_y = ey;
    //        end_x = sx;
    //        end_y = sy;
    //    }
    //    if(end_y < start_y){

    //    }
    //    if((end_x - start_x) < (end_y -  start_y)){

    //    }
}


void Line::move( int h, int v )     // Def. der line::move() Methode
{
    start_x += h; start_y += v; end_x += h; end_y += v;
}

int Line::sgn(int x) const
{
    if(x > 0) return 1;
    else if(x < 0) return -1;
    else return 0;
}

void Line::draw(Frame *ptarget) const
{
    int x, y, t, dx, dy, incx, incy, pdx, pdy, ddx, ddy, deltaslowdirection, deltafastdirection, err;

    /* Entfernung in beiden Dimensionen berechnen */
    dx = end_x - start_x;
    dy = end_y - start_y;

    /* Vorzeichen des Inkrements bestimmen */
    incx = sgn(dx);
    incy = sgn(dy);
    if(dx<0) dx = -dx;
    if(dy<0) dy = -dy;

    /* feststellen, welche Entfernung größer ist */
    if (dx>dy)
    {
        /* x ist schnelle Richtung */
        pdx=incx; pdy=0;    /* pd. ist Parallelschritt */
        ddx=incx; ddy=incy; /* dd. ist Diagonalschritt */
        deltaslowdirection =dy;   deltafastdirection =dx;   /* Delta in langsamer Richtung, Delta in schneller Richtung */
    } else
    {
        /* y ist schnelle Richtung */
        pdx=0;    pdy=incy; /* pd. ist Parallelschritt */
        ddx=incx; ddy=incy; /* dd. ist Diagonalschritt */
        deltaslowdirection =dx;   deltafastdirection =dy;   /* Delta in langsamer Richtung, Delta in schneller Richtung */
    }

    /* Initialisierungen vor Schleifenbeginn */
    x = start_x;
    y = start_y;
    err = deltafastdirection/2;
    ptarget->put_point(y, x);

    /* Pixel berechnen */
    for(t=0; t<deltafastdirection; ++t) /* t zaehlt die Pixel, deltafastdirection ist Anzahl der Schritte */
    {
        /* Aktualisierung Fehlerterm */
        err -= deltaslowdirection;
        if(err<0)
        {
            /* Fehlerterm wieder positiv (>=0) machen */
            err += deltafastdirection;
            /* Schritt in langsame Richtung, Diagonalschritt */
            x += ddx;
            y += ddy;
        } else
        {
            /* Schritt in schnelle Richtung, Parallelschritt */
            x += pdx;
            y += pdy;
        }
        ptarget->put_point(y, x);
    }
}

void line_test()
{
    //test #1
    Frame frameActual{};
    Frame* frameActualPointer{ &frameActual };
    Line line{ 0,0,5,5 };
    line.draw(frameActualPointer);
    cout << frameActual << endl;

    Frame frameExpected{};
    Frame* frameExpectedPointer{ &frameExpected };
    frameExpected.put_point(0, 0);
    frameExpected.put_point(1, 1);
    frameExpected.put_point(2, 2);
    frameExpected.put_point(3, 3);
    frameExpected.put_point(4, 4);
    frameExpected.put_point(5, 5);

    line.assertFrame(1, frameActualPointer, frameExpectedPointer);

    //test #2
    Frame frameActual2{};
    Frame* frameActualPointer2{ &frameActual2 };
    Line line2{ 0,0,13,10 };
    line2.draw(frameActualPointer2);
    cout << frameActual2 << endl;

    Frame frameExpected2{};
    Frame* frameExpectedPointer2{ &frameExpected2 };
    frameExpected2.put_point(0, 0);
    frameExpected2.put_point(1, 1);
    frameExpected2.put_point(2, 2);
    frameExpected2.put_point(2, 3);
    frameExpected2.put_point(3, 4);
    frameExpected2.put_point(4, 5);
    frameExpected2.put_point(5, 6);
    frameExpected2.put_point(5, 7);
    frameExpected2.put_point(6, 8);
    frameExpected2.put_point(7, 9);
    frameExpected2.put_point(8, 10);
    frameExpected2.put_point(8, 11);
    frameExpected2.put_point(9, 12);
    frameExpected2.put_point(10, 13);

    line2.assertFrame(2, frameActualPointer2, frameExpectedPointer2);


    //test #3
    Frame frameActual3{};
    Frame* frameActualPointer3{ &frameActual3 };
    Line line3{ 0,0,0,0 };
    line3.draw(frameActualPointer3);
    cout << frameActual3 << endl;

    Frame frameExpected3{};
    Frame* frameExpectedPointer3{ &frameExpected3 };
    frameExpected3.put_point(0, 0);

    line3.assertFrame(3, frameActualPointer3, frameExpectedPointer3);

}
