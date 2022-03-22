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
};

template <typename T>
void SwapData(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main(void)
{
    Point p1(1, 2);
    Point p2(3, 4);
    SwapData(p1, p2);
    p1.ShowPosition();
    p2.ShowPosition();
    return 0;
}