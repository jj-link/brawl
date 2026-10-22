#include <types.h>
#pragma force_active on

class Obj {
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
    virtual void call(s32 a, s32 b, f32 c, f32 d, f32 e);
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual s32 count();

    u8 m_pad[0x62];
    u16 m_flags;
};

extern "C" {
void fn_27_43CE0(Obj* self, s32 arg1, f32 farg0, f32 farg1, f32 farg2) {
    if ((self->m_flags >> 14) & 1) {
        return;
    }
    s32 n = self->count();
    for (s32 i = 0; i < n; i++) {
        self->call(arg1, i, farg0, farg1, farg2);
    }
}
}
