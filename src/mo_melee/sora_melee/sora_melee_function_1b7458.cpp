#include <types.h>
#pragma force_active on

struct Blk {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wC;
    u32 w10;
};

class SoBase {
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
    virtual Blk* get(void* x);
};

extern "C" {
void fn_27_1B7458(SoBase* self, void* unused, void* p) {
    Blk* src = self->get(unused);
    Blk* dst = self->get(p);
    dst->w0 = src->w0;
    if (&dst->w4 != &src->w4 && &dst->w4 != &src->w4) {
        if (&dst->w8 != &src->w8) {
            dst->w8 = src->w8;
        }
        dst->wC = src->wC;
        dst->w10 = src->w10;
        if (dst->wC == 0) {
            dst->w10 = 0;
        }
    }
}
}
