#include <types.h>
#pragma force_active on

extern "C" s32 fn_801C96B8(void* self, s32 a);
extern "C" s32 fn_801D399C(void* a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);
extern "C" void fn_801D3B14(void* self, s32 a);
extern "C" void fn_801D3B1C(void* self, u8 a);
extern f32 lbl_805A3620;

class Obj {
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
    virtual void slot11(f32 f);
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(s32 a);
    virtual void slot19(s32 a);
    virtual void slot20(s32 a);
};

struct P2 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
    s32 f10;
    s32 f14;
    s32 f18;
};

struct P3 {
    s32 f0;
    s32 f4;
    u8 f8;
};

extern "C" s32 fn_801CA0FC(void* self, Obj* p1, P2* p2, P3* p3, s32 p4, s32 p5, s32 p6) {
    s32 r;
    s32 flag;
    s32 r30;
    s32 r31 = p6;

    r = fn_801C96B8(self, p2->f0);
    if (r == 0) {
        return 4;
    }
    r30 = p5;
    switch (p4) {
    case 0:
        flag = 1;
        break;
    case 1:
        flag = 0;
        r30 = 0;
        break;
    case 2:
        flag = 0;
        break;
    default:
        flag = 0;
        r30 = 0;
        break;
    }
    if (fn_801D399C(p1, r, p3->f0, flag, r30, r31, (s32)self + 0x28, p2->f0) == 0) {
        return 0xFF;
    }
    p1->slot11((f32)p2->fc / lbl_805A3620);
    fn_801D3B14(p1, p3->f4);
    fn_801D3B1C(p1, p3->f8);
    p1->slot18(p2->f10);
    p1->slot19(p2->f14);
    p1->slot20(p2->f18);
    return 0;
}
