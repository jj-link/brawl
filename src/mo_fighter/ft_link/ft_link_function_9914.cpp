#pragma force_active on
class V {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void method13(int a, int b, int c);
};

struct T {
    char pad[0x24];
    V* v;
};

struct A {
    char pad[0xd8];
    T* actor;
};

struct This {
    char pad[0x1A348];
    unsigned char flag;
};

extern "C" {
void fn_93_9914(This* self, A* a, unsigned int arg2) {
    if (self->flag != 1)
        return;
    if (arg2 == 1)
        return a->actor->v->method13(0, 0, 1);
    return a->actor->v->method13(0, 1, 1);
}
}
