#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v7(int a, unsigned int b);
};

struct Mid {
    char pad[0x64];
    Inner* inner;
};

struct Outer {
    char pad[0xd8];
    Mid* mid;
};

struct Top {
    char pad[0x60];
    Outer* outer;
};

extern "C" {
int fn_120_7BF8(Top* t) {
    return t->outer->mid->inner->v7(0, 0x10000044);
}
}
