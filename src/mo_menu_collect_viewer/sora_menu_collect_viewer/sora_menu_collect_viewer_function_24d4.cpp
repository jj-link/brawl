#include <types.h>
#pragma force_active on

struct Data {
    char pad[0x1cee];
    u8 flag;
};

struct Base {
    char pad[0x3c];
};

struct Object : Base {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual u32 count(int arg) const;
    char pad2[0x1ac - 0x40];
    Data* data;
};

extern "C" u32 fn_6_24D4(const Object* self, int arg) {
    u8 flag = self->data->flag;
    u32 n = self->count(arg);
    return flag + n;
}
