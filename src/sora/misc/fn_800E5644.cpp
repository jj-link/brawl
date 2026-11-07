#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

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
    virtual void slot8(float f);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(void* a, void* b);
    virtual void slot12();
    virtual void slot13(void* a);
};

class Mgr : public Object_vptr_0 {
public:
    char pad[0xE0];
    void* unkE4;
};

struct Sub {
    char pad0[0xC];
    Object_vptr_0* unkC;
    char pad1[4];
    Object_vptr_0* unk14;
};

struct Mu {
    char pad0[0x10];
    void* unk10;
    Sub* unk14;
};

extern "C" {
void fn_800B70D0(void*, const char*, void*);
void fn_800B798C(void*, u8, float);
extern char lbl_8045A380[];
extern Mgr* lbl_805A02E0;
extern const float lbl_805A23B0;
extern const float lbl_805A23E4;
extern const float lbl_805A245C;
extern const float lbl_805A2460;
extern const float lbl_805A2464;
}

extern "C" s32 fn_800E5644(char* self, s32 idx) {
    char* elem = self + idx * 0x48;
    if (*(u8*)(elem + 0x430) == 0) {
        return 0;
    }
    *(s32*)(self + 0x554) = 0;
    lbl_805A02E0->slot13(((Mu*)(*(void**)(self + 0xEC)))->unk10);
    Mu* o = *(Mu**)(self + 0xEC);
    fn_800B70D0(o, lbl_8045A380, elem + 0x3F0);
    lbl_805A02E0->slot11(lbl_805A02E0->unkE4, o->unk10);
    ((MuObject*)o)->setFrameNode((f32)(*(u8*)(elem + 0x430) - 1));
    o->unk14->unkC->slot8(lbl_805A23B0);
    u8 t4 = *(u8*)(elem + 0x430);
    fn_800B798C(o, t4, (f32)(t4 - 1));
    o->unk14->unk14->slot8(lbl_805A23B0);
    u8 t0 = *(u8*)(elem + 0x430);
    f32 v;
    if (t0 < 0xA) {
        v = lbl_805A245C * (f32)t0;
    } else {
        v = lbl_805A2460;
    }
    if (*(f32*)(self + 0x54C) != v) {
        *(f32*)(self + 0x54C) = v;
    }
    *(s32*)(self + 0x554) = (s32)(lbl_805A23E4 * ((f32)(*(u8*)(elem + 0x430) - 1) / lbl_805A2464)) + 0x46;
    return 1;
}
