#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    { }
    Point(Point &copy) : xpos(copy.xpos), ypos(copy.ypos)
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
    friend Point& operator~(Point &ref);
};

Point& operator--(Point &ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

Point& operator~(Point &ref)
{
    ref.xpos = ~ref.xpos;
    ref.ypos = ~ref.ypos;
    return ref;
}

int main(void)
{
    Point pos(1, 2);
    ++pos;
    pos.ShowPosition();
    --pos;
    pos.ShowPosition();

    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();

    Point pos2 = -pos;
    pos2.ShowPosition();

    Point pos3(1, 0);
    ~pos3;
    pos3.ShowPosition();
    return 0;
}