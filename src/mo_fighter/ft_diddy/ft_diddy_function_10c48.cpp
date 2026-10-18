#pragma force_active on
class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(void *);
};

class Holder {
public:
    char pad[0x3c];
    Obj *inner;
};

class Outer {
public:
    char pad[0xd8];
    Holder *holder;
};

extern "C" void fn_115_10C48(void *a, Outer *b)
{
    b->holder->inner->v10(b);
}
