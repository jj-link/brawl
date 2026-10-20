#include <types.h>
#pragma force_active on

struct Inner {
    virtual s32 v0();
    virtual s32 v1();
    virtual s32 v2();
    virtual s32 v3();
    virtual s32 v4();
    virtual s32 v5();
    virtual s32 v6();
    virtual s32 v7();
    virtual s32 v8();
    virtual s32 v9();
    virtual s32 v10();
    virtual s32 v11();
    virtual s32 v12();
    virtual s32 v13();
    virtual s32 v14();
    virtual s32 v15();
    virtual s32 v16();
    virtual s32 v17();
    virtual s32 v18();
    virtual s32 target();
};

struct Outer {
    u8 pad[0x1cc];
    Inner m_inner;
};

extern "C" s16 fn_27_263AE8(Outer* self) {
    Inner* inner = &self->m_inner;
    return (s16)inner->target();
}
