#include <types.h>
#pragma force_active on

struct Pair {
    u32 a[2];
};

struct Data {
    u32 w;
    u32 x;
    Pair c;
    Pair d;
    u32 e;
    Pair f;
    Pair g;
    u32 h;
    u32 i;
};

class Vt {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual Data* get(u32);
};

extern "C" Data* fn_27_EA820(Vt* self, u32 a, u32 arg2) {
    Data* src = self->get(a);
    Data* dst = self->get(arg2);
    dst->w = src->w;
    dst->x = src->x;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    dst->g = src->g;
    dst->h = src->h;
    dst->i = src->i;
    return dst;
}
