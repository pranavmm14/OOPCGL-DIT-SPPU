#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

class algo
{
public:
    void DDA_line(float x1, float y1, float x2, float y2);
    void Bresenhams_circle(int radius);
};

void algo::DDA_line(float x1, float y1, float x2, float y2)
{
    float xnew, ynew, dx, dy, step, xold, yold;
    int i = 1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    cout << "dx=" << dx << "\tdy=" << dy << endl;
    if (dx >= dy)
        step = dx;
    else
        step = dy;
    cout << "step=" << step << endl;
    float x_increment = float((x2 - x1) / step);
    float y_increment = float((y2 - y1) / step);

    xnew = x1;
    ynew = y1;

    outtextxy(350, 250, "(0,0)");

    while (i <= step)
    {
        putpixel(350 + xnew, 250 + ynew, WHITE);
        xold = xnew;
        yold = ynew;
        cout << "i=" << i << endl
             << "(x,y)="
             << "(" << xold << "," << yold << ")" << endl;
        xnew = xold + x_increment;
        ynew = yold + y_increment;
        i++;
        delay(10);
    }
}

void algo::Bresenhams_circle(int radius)
{
    cout << "CIRCLE CO-ORDINATES:" << endl;
    float x, y, p;
    int r = radius;
    x = 0;
    y = radius;
    p = 3 - (2 * r);

    while (x <= y)
    {
        putpixel(350 + x, 250 + y, 1);
        putpixel(350 - x, 250 + y, 2);
        putpixel(350 + x, 250 - y, 3);
        putpixel(350 - x, 250 - y, 4);
        putpixel(350 + y, 250 + x, 4);
        putpixel(350 + y, 250 - x, 2);
        putpixel(350 - y, 250 + x, 3);
        putpixel(350 - y, 250 - x, 1);
        cout << "(x,y)="
             << "(" << x << "," << y << ")" << endl;

        if (p < 0)
        {
            p = p + (4 * x) + 6;
            x++;
        }
        else
        {
            p = p + 4 * (x - y) + 10;
            x++;
            y--;
        }
        delay(10);
    }
}

int main()
{
    algo a1;
    int r;
    cout << "Enter Radius: ";
    cin >> r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    // for(int i=5; i <r; i++){
    a1.Bresenhams_circle(r);
    //}
    float s, c, ang;
    ang = 3.14 / 180;
    s = r * sin(30 * ang);
    c = r * cos(30 * ang);
    a1.DDA_line(0, -r, 0 - c, 0 - s);
    a1.DDA_line(0 - c, 0 - s, 0 + c, 0 + s);
    a1.DDA_line(0 + c, 0 + s, 0, -r);

    a1.Bresenhams_circle(int(r / 2));

    getch();
    closegraph();
    return 0;
}
