#pragma force_active on
class Base {
public:
    virtual ~Base();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void method(void* ptr);
};

extern "C" void fn_94_8E8C(Base* fp, void* a2, int count)
{
    if (a2 == 0 || count <= 0)
        return;
    for (int i = 0; i < count; i++) {
        fp->method((char*)a2 + (i << 2));
    }
}
