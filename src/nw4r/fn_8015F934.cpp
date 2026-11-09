#include <types.h>
#pragma force_active on

extern "C" void fn_8015FA64(void* self, void* out, f32 a, f32 b, f32 c);
extern f32 lbl_805A2BC8;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(void* out, s32 arg);
};

struct Out {
    u8 pad0[4];
    s8 c;
    u8 pad5;
    s8 e;
    u8 pad7[0x11];
};

struct Self {
    u8 pad0[0x24];
    f32 f24;
    u8 pad28[4];
    f32 f2c;
    f32 f30;
    f32 f34;
    u8 pad38[0xb];
    u8 b43;
    f32 f44;
    Object_vptr_0* obj48;
};

extern "C" {
f32 fn_8015F934(void* arg0, s32 arg1) {
    Self* self = (Self*)arg0;
    Out out;
    f32 var_f1;
    f32 var_f31;

    self->obj48->slot18(&out, arg1);
    if (self->b43 != 0) {
        f32 d;
        var_f31 = self->f44;
        d = var_f31 - ((f32)out.e * self->f24);
        var_f1 = (d * lbl_805A2BC8) + ((f32)out.c * self->f24);
    } else {
        var_f31 = (f32)out.e * self->f24;
        var_f1 = (f32)out.c * self->f24;
    }
    fn_8015FA64(self, &out, self->f2c + var_f1, self->f30, self->f34);
    self->f2c = self->f2c + var_f31;
    return var_f31;
}
}
