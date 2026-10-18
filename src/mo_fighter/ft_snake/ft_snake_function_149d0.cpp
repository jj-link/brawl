#pragma force_active on
struct Target
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void call(unsigned int);
};

struct Inner
{
    char pad[0x64];
    Target *target;
};

struct Outer
{
    char pad[0xD8];
    Inner *inner;
};

extern "C" void fn_122_149D0(void *unused, Outer *object)
{
    object->inner->target->call(0x20000002);
}
