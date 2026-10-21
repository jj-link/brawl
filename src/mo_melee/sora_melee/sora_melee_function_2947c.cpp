#include <types.h>
#pragma force_active on

struct Res {
    u8 pad[0x154];
    u32 a, b, c;
    u8 d, e;
};

struct Ret {
    u8 pad[4];
    Res* res;
};

class Inner {
public:
    virtual void unused();
    virtual Ret* get(int);
};

struct Obj {
    u8 pad[0x28];
    Inner* inner;
};

struct Params {
    Params() : a(0), b(0), c(0), d(0) {
        bits.flag = 0;
    }

    u32 a, b, c;
    u8 d;
    union {
        u8 e;
        struct {
            u8 flag : 1;
            u8 other : 7;
        } bits;
    };
};

extern "C" void fn_80114AAC(Params*, Res*);

extern "C" void fn_27_2947C(Obj* __restrict arg0, int arg1) {
    Params p;
    Res* res = arg0->inner->get(arg1)->res;
    p.a = res->a;
    p.b = res->b;
    p.c = res->c;
    p.d = res->d;
    p.e = res->e;
    fn_80114AAC(&p, res);
}
