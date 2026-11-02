#include <types.h>
#pragma force_active on

struct Pair {
    u32 a[2];
};

struct Blk {
    u32 w0;
    u32 w1;
    Pair p[5];
    f32 f;
    u8 b;
    u16 h;
    u32 x;
    u32 y;
};

class VtA {
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
    virtual Blk* getSrc();
};

class VtB {
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
    virtual Blk* getDst(u32 idx);
};

extern "C" void fn_27_E8DE4(VtA* self, int unused, u32 idx) {
    Blk* src = self->getSrc();
    Blk* dst = ((VtB*)self)->getDst(idx);
    dst->w0 = src->w0;
    dst->w1 = src->w1;
    dst->p[0] = src->p[0];
    dst->p[1] = src->p[1];
    dst->p[2] = src->p[2];
    dst->p[3] = src->p[3];
    dst->p[4] = src->p[4];
    dst->f = src->f;
    dst->b = src->b;
    dst->h = src->h;
    dst->x = src->x;
    dst->y = src->y;
}
