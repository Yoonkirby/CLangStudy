#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPointInfo() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Circle
{
private:
    int radius;
    Point center;
public:
    void Init(int x, int y, int rad)
    {
        radius = rad;
        center.Init(x, y);
    }
    void ShowCircleInfo() const
    {
        cout<<"radius : "<<radius<<endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle inner;
    Circle outter;
public:
    void Init(int ix, int iy, int irad, int ox, int oy, int orad)
    {
        if(irad < orad)
        {
            inner.Init(ix, iy, irad);
            outter.Init(ox, oy, orad);
        }
        else
        {
            cout<<"바깥원이 안쪽원보다 작을 수 없습니다."<<endl;
            exit(1);
        }
    }
    void ShowRingInfo() const
    {
        cout<<"Inner Circle Info..."<<endl;
        inner.ShowCircleInfo();
        cout<<"Outter Circle Info..."<<endl;
        outter.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}