#pragma force_active on
class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
};

struct Sub {
    char pad[0x3c];
    Obj *obj;
};

struct Owner {
    char pad[0xd8];
    Sub *sub;
};

extern "C" {
void fn_109_C340(void *unused, Owner *owner)
{
    owner->sub->obj->f13();
}
}
