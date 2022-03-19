#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
    Point & operator+=(const Point &pos)
    {
        xpos += pos.xpos;
        ypos += pos.ypos;
        return *this;
    }
    Point & operator-=(const Point &pos)
    {
        xpos -= pos.xpos;
        ypos -= pos.ypos;
        return *this;
    }
    friend Point operator+(const Point &pos1, const Point &pos2);
    friend Point operator-(const Point &pos1, const Point &pos2);
    friend bool operator==(const Point &pos1, const Point &pos2);
    friend bool operator!=(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
    return pos;
}

Point operator-(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
    return pos;
}

bool operator==(const Point &pos1, const Point &pos2)
{
    if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
        return true;
    else
        return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    /*bool i = operator==(pos1, pos2);
    if(i == true)
        return false;
    else
        return true;*/
    return !(pos1==pos2);
}

int main(void)
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1 + pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    cout<<endl;

    Point pos4(15, 25);
    Point pos5(4, 7);
    (pos4 += pos5).ShowPosition();
    pos4.ShowPosition();
    (pos4 -= pos5).ShowPosition();
    pos4.ShowPosition();
    ((pos4 += pos5) -= pos5) -= pos5;
    pos4.ShowPosition();
    pos5.ShowPosition();
    cout<<endl;

    Point pos6(1, 2);
    Point pos7(1, 2);
    cout<<(pos6==pos7)<<endl;
    cout<<(pos6==pos5)<<endl;
    if(pos6==pos7)
        cout<<"equal"<<endl;
    else
        cout<<"not equal"<<endl;
    if(pos6==pos5)
        cout<<"equal"<<endl;
    else
        cout<<"not equal"<<endl;
    cout<<(pos6!=pos7)<<endl;
    cout<<(pos6!=pos5)<<endl;
    if(pos6!=pos7)
        cout<<"not equal"<<endl;
    else
        cout<<"equal"<<endl;
    if(pos6!=pos5)
        cout<<"not equal"<<endl;
    else
        cout<<"equal"<<endl;
    return 0;
}