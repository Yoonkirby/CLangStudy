#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y)
        :xpos(x), ypos(y) {}
    void PointSet(int x, int y)
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
    Circle(int x, int y, int rad)
        :center(x, y), radius(rad) {}
    void CircleSet(int x, int y, int rad)
    {
        radius = rad;
        center.PointSet(x, y);
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
    Ring(int ix, int iy, int irad, int ox, int oy, int orad)
        :inner(ix, iy, irad), outter(ox, oy, orad){}
    void RingSet(int ix, int iy, int irad, int ox, int oy, int orad)
    {
        if(irad < orad)
        {
            inner.CircleSet(ix, iy, irad);
            outter.CircleSet(ox, oy, orad);
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
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}