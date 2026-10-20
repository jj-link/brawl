#include <types.h>
#pragma force_active on

struct Pre {
    u32 pa;
    u32 pb;
};

struct Obj : Pre {
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual s32 v34(void* self, s32 a, s32 b);
};

struct Outer {
    u8 pad[0x8d0];
    Obj* m_8d0;
};

extern "C" s32 fn_27_28877C(Outer* self, s32 a, s32 b) {
    return self->m_8d0->v34(self, a, b);
}
