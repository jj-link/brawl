#include <types.h>
#pragma force_active on

struct Pad {
    u32 a;
    u32 b;
};

class Obj : public Pad {
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
    virtual void v20(u32 x, u32 y);
    virtual void v21();
    virtual u32 v22();
};

extern "C" {
u32 fn_41_C0C8(Obj* a, u32 b, u32 c) {
    u32 r = a->v22();
    if (r == 1) {
        a->v20(b, c);
    }
    return r;
}
}
