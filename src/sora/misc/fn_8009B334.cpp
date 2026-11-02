#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(u32 size, s32 align);
};

class Obj {
public:
    virtual void release(s32 flag);
    u16 f4;
    s16 f6;
};

struct Inner {
    u8 pad00[0x70];
    void* m70;
};

struct Owner {
    u8 pad00[0x54];
    Inner* f54;
    u8 pad58[4];
    u8 f5c;
    void** f60;
    s32 f64;
};

struct Params {
    float f00;
    float f04;
    float f08;
    float f0c;
    float sub[4];
    float f40;
    float f44;
    float f48;
    float f4c;
    u8 pad50[8];
    u8 f58;
    u8 pad59[0x27];
    float f80;
    u8 pad84[0x4c];
};

extern SoHeapAllocator* lbl_805A0EB8;
extern float lbl_805A1D68;
extern float lbl_805A1D6C;
extern float lbl_805A1D70;
extern float lbl_805A1D74;

extern "C" {
    void fn_80095F70(void* p);
    void fn_802AAA38(void* p);
    void fn_802AC30C(void* p);
    void* fn_802CD0B0(void* p);
    void* fn_802EEF18(void* p, void* arg, u32 size);
    void fn_802EFD3C(void* a, void* b, u8* flag, s32 c, s32 d);
    void fn_802F00DC(void* p);
    void fn_802F01CC(void* p, float a, float b);
    void fn_802F0200(void* p, s32 n);
    void* fn_8032BEA4(void* p, s32 n);
}

extern "C" void fn_8009B334(Owner* self) {
    __declspec(align(16)) Params p;
    __declspec(align(4)) u8 flag14;
    u8 flag10;
    Obj* r30;
    s32 i;

    if (self->f5c != 0) {
        for (i = 0; i < self->f64; i++) {
            fn_80095F70(self->f60[i]);
        }
        if (self->f5c != 0 && self->f54 == 0) {
            fn_802F00DC(p.sub);
            fn_802F0200(p.sub, 5);
            p.f00 = lbl_805A1D68;
            p.f04 = lbl_805A1D6C;
            p.f08 = lbl_805A1D68;
            p.f0c = lbl_805A1D68;
            p.f40 = lbl_805A1D68;
            p.f44 = lbl_805A1D6C;
            p.f48 = lbl_805A1D68;
            p.f4c = lbl_805A1D68;
            fn_802F01CC(p.sub, lbl_805A1D70, lbl_805A1D68);
            p.f58 = 3;
            p.f80 = lbl_805A1D74;

            Obj* q = (Obj*)lbl_805A0EB8->alloc(0x2f0, 0x2d);
            q->f4 = 0x2f0;
            if (q != 0) {
                q = (Obj*)fn_802EEF18(q, p.sub, 40000);
            }
            self->f54 = (Inner*)q;
            fn_802AC30C(self->f54->m70);
            fn_802AAA38(self->f54->m70);

            r30 = (Obj*)lbl_805A0EB8->alloc(0x20, 0x25);
            r30->f4 = 0x20;
            if (r30 != 0) {
                r30 = (Obj*)fn_8032BEA4(r30, 0);
            }
            flag14 = 1;
            fn_802EFD3C(self->f54, r30, &flag14, 0, 1);
            if (r30->f4 != 0) {
                if (--r30->f6 == 0 && r30 != 0) {
                    r30->release(1);
                }
            }

            r30 = (Obj*)lbl_805A0EB8->alloc(0x9c, 0x25);
            r30->f4 = 0x9c;
            if (r30 != 0) {
                r30 = (Obj*)fn_802CD0B0(r30);
            }
            flag10 = 1;
            fn_802EFD3C(self->f54, r30, &flag10, 0, 1);
            if (r30->f4 != 0) {
                if (--r30->f6 == 0 && r30 != 0) {
                    r30->release(1);
                }
            }
        }
    }
}
