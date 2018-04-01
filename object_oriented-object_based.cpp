#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;
/*
 * OO, object-oriented implementation
 * pure virtual function
 */
class Graphic
{
public:
    virtual void drawPoint() = 0;
    virtual void drawLine() = 0;
};

class SpecialGraphic : public Graphic
{
public:
    void drawPoint() override {}
    void drawLine() override {}
};

/*
 * object-based implementation
 * std::function & std::bind
 */
class Graphic2
{
public:
    typedef std::function<void()> DrawCallback;
    Graphic2(){}

    void drawPoint() { m_point(); }
    void setPointCallback(DrawCallback callback) { m_point = callback; }
    void drawLine() { m_line(); }
    void setLineCallback(DrawCallback callback) { m_line = callback; }
private:
    DrawCallback m_point;
    DrawCallback m_line;
};

void draw_point() {}
void draw_line() {}

int main(int argc, char *argv[])
{
    /// OO usage
    Graphic *sg = new SpecialGraphic();
    sg->drawPoint();
    sg->drawLine();

    /// object-based usage
    Graphic2 g2;
    g2.setPointCallback(bind(draw_point));
    g2.setLineCallback(bind(draw_line));
    g2.drawPoint();
    g2.drawLine();

    return 0;
}
