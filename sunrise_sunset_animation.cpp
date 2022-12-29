#include <graphics.h>
#include <stdio.h>

void mount();

int main()
{

    int a, b, c, d;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL );
    mount();

    // sun rise
    b = 0;
    for (a = 0; a < 150; a++)
    {
        setcolor(RED);
        circle(getmaxx()/2, 400 - b, 40);
        floodfill(getmaxx()/2, 360 - b, RED);
        b = b + 2;
        delay(30);
        cleardevice();
        mount();
    }
    setcolor(YELLOW);
    circle(getmaxx()/2, 400 - b, 40);
    floodfill(getmaxx()/2, 360 - b, YELLOW);
    delay(1000);

    // circle(400,100,50);

	outtextxy(400,100, "Sun Rise");
	getch();

    delay(1000);
    // sun set
    c = 0;
    for (a = 0; a < 150; a++)
    {
        setcolor(RED);
        circle(getmaxx()/2, 400 - b + c, 40);
        floodfill(getmaxx()/2, 360 - b + c, RED);
        c = c + 2;
        delay(30);
        cleardevice();
        mount();
    }

	outtextxy(450,110, "Sun Set");
    getch();
}

void mount()
{

    setcolor(BROWN);
    // mountain
    line(0, 410, 160, 150);
    line(160, 150, 320, 410);
    line(320, 410, 480, 150);
    line(480, 150, 640, 410);
    line(0, 410, 640, 410);
    floodfill(160, 270, BROWN);
    floodfill(480, 250, BROWN);
}

