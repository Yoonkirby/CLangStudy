#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    { }
    Point(const Point &copy) : xpos(copy.xpos), ypos(copy.ypos)
    { }
    void ShowPosition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<"]"<<endl;
    }
    Point& operator++()
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    friend Point& operator--(Point &ref);
    Point& operator-()
    {
        static Point ref(-xpos, -ypos);
        return ref;
    }
    friend Point operator~(Point ref);
};

Point& operator--(Point &ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

Point operator~(const Point ref)
{
    Point pos(ref.ypos, ref.xpos);
    return pos;
}

int main(void)
{
    Point pos(1, 2);
    (++pos).ShowPosition();
    (--pos).ShowPosition();

    (++(++pos)).ShowPosition();
    (--(--pos)).ShowPosition();

    Point pos2 = -pos;
    pos2.ShowPosition();

    (~pos).ShowPosition();
    pos2.ShowPosition();
    return 0;
}