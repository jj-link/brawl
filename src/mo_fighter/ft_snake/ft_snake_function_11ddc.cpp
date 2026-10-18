#pragma force_active on
class FtSnakeInner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

extern "C" void fn_122_11DDC(char* self)
{
    FtSnakeInner* inner = reinterpret_cast<FtSnakeInner*>(self + 0x2CA84);
    inner->f2();
}
