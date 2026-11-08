#pragma force_active on
#include <types.h>

class X {
public:
    virtual int v0() = 0;
    virtual int v1() = 0;
    virtual int v2() = 0;
    virtual int v3() = 0;
    virtual int v4() = 0;
    virtual int v5() = 0;
    virtual int v6() = 0;
    virtual int v7() = 0;
    virtual int v8() = 0;
    virtual int v9() = 0;
    virtual int v10() = 0;
    virtual int v11() = 0;
    int pad[44];
    u8 b;
};

static int call_v11(X* p) {
    return p->v11();
}

extern "C" int fn_80182AE4(X* p, int a) {
    switch (a) {
    case 0x10:
        return p->b;
    default:
        return call_v11(p);
    }
}