#include <types.h>
#pragma force_active on

struct Ret8 {
    u32 lo;
    u32 hi;
};

struct Obj {
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
    virtual Ret8* get(int index);
};

extern "C" Ret8* fn_56_AE64(Obj* self, int a, int b) {
    Ret8* src = self->get(a);
    Ret8* dst = self->get(b);
    *dst = *src;
    return dst;
}