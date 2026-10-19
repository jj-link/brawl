#pragma force_active on
struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(int a, int b);
    virtual void v6();
    virtual void v7();
};

struct Mid {
    char pad[0x64];
    Target* c;
};

struct Top {
    char pad[0xd8];
    Mid* b;
};

struct Owner {
    char pad[0x60];
    Top* a;
};

extern "C" {
int fn_113_18080(Owner* o, int x) {
    return o->a->b->c->v5(x, 0x1000000F);
}
}
