#include <types.h>
#pragma force_active on

struct Pair { u32 w[6]; };

struct VBase {
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
    virtual Pair* getSrc();
};

struct VDst {
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
    virtual Pair* getDst(u32 idx);
};

extern "C" Pair* fn_27_125324(VBase* self, u32 unused, u32 idx) {
    Pair* src = self->getSrc();
    Pair* dst = ((VDst*)self)->getDst(idx);
    dst->w[0] = src->w[0];
    dst->w[1] = src->w[1];
    dst->w[2] = src->w[2];
    dst->w[3] = src->w[3];
    dst->w[4] = src->w[4];
    dst->w[5] = src->w[5];
    return dst;
}
