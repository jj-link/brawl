#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_data_91F78;
extern float lbl_27_rodata_7B24;

struct VT {
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(unsigned int id, void* obj, float v);
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48(float v);
};

struct Mid {
    char pad0[0x1c];
    VT* a;
    char pad1[0x64 - 0x20];
    VT* b;
};

struct Actor {
    char pad[0xd8];
    Mid* mid;
};

struct Sub {
    char pad[0x10];
    float unk10;
    float unk14;
};

struct Self {
    Actor* unk0;
    Sub* unk4;
    char pad8[4];
    float unkC;
    float unk10;
};

extern "C" void fn_27_368B30(Self* self) {
    if (lbl_27_data_91F78 == 0) {
        self->unk0->mid->a->f48(lbl_27_rodata_7B24);
        return;
    }
    float v = lbl_27_rodata_7B24;
    if (self->unkC < self->unk4->unk14) {
        float base = self->unk4->unk10;
        v = base + (lbl_27_rodata_7B24 - base) * (self->unkC / self->unk10);
    }
    self->unk0->mid->a->f48(v);
    self->unk0->mid->b->f13(0x11000013, self->unk0, self->unkC);
}
