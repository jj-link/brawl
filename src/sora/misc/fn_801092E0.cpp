#pragma force_active on

#include <types.h>

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
    virtual void slot13(void* arg);
};

struct Sub {
    char pad0[0x10];
    void* f10;
};

struct MuMsg;

struct Self {
    char pad0[4];
    Sub* f4;
    Sub* f8;
    Sub* fC;
    Sub* f10;
    char pad14[4];
    Object_vptr_0* f18;
    Object_vptr_0* f1C;
    MuMsg* f20;
    char pad24[4];
    void* f28;
};

struct Param {
    s32 flag;
    f32 f4;
    f32 f8;
    u32 fC;
    void* f10;
};

extern "C" {
extern Object_vptr_0* lbl_805A0334;
extern char lbl_8059E61C[8];
extern char lbl_8059E624[8];
extern char lbl_8059E62C[8];
extern char lbl_8059E634[8];
extern char lbl_8045D22C[];
extern f32 lbl_805A2820;
extern f32 lbl_805A2838;
extern f32 lbl_805A283C;
extern f32 lbl_805A2840;
extern f32 lbl_805A2844;
extern f32 lbl_805A2848;

void* memcpy(void*, const void*, u32);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, const char*);
void fn_800B7184(void*, const char*, u32, void*);
void fn_800B8EDC(MuMsg*, void*);
void fn_800B9488(MuMsg*, u32, u32);
void FUN_800b9448__5MuMsgFUlb(MuMsg*, u32, bool);
void FUN_800b9460__5MuMsgFUlUcUcUcf(MuMsg*, u32, u8, u8, u8, f32);
void fn_8006B660(void*, u32, u32);
void fn_800B67E0(void*, f32*, const char*);
void fn_80400AB8(f32);
void printIndex__5MuMsgFUlUlPv(MuMsg*, u32, u32, void*);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(MuMsg*, u32, u32);
void setFontColor__5MuMsgFUlUcUcUcUc(MuMsg*, u32, u8, u8, u8, u8);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(MuMsg*, u32, void*, u32, f32);

void fn_801092E0(Self* arg0, Param* arg1) {
    char buf[8];
    s32 temp_r31;
    u32 temp_r30;
    Object_vptr_0* ptr29;
    Sub* ptr28;
    Sub* ptr27;
    f32 vec[3];

    *(s32*)buf = 0;
    *(s16*)(buf + 4) = 0;

    if (arg1->flag == 0) {
        ptr29 = arg0->f18;
        ptr28 = arg0->f4;
        ptr27 = arg0->fC;
        memcpy(buf, lbl_8059E61C, 5);
    } else {
        arg1->flag = 1;
        ptr29 = arg0->f1C;
        ptr28 = arg0->f8;
        ptr27 = arg0->f10;
        memcpy(buf, lbl_8059E624, 5);
    }

    fn_800B7184(ptr28, lbl_8045D22C, 0, &arg1->f10);
    lbl_805A0334->slot13(ptr29);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(lbl_805A0334, ptr29, buf);
    temp_r30 = arg1->fC;
    temp_r31 = arg1->flag;
    fn_800B8EDC(arg0->f20, ptr28);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(arg0->f20, temp_r31, ptr28->f10, 0, lbl_805A2838);
    FUN_800b9448__5MuMsgFUlb(arg0->f20, temp_r31, 1);
    FUN_800b9460__5MuMsgFUlUcUcUcf(arg0->f20, temp_r31, 0xDD, 0xDD, 0xDD, lbl_805A283C);
    setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(arg0->f20, temp_r31, 1);
    setFontColor__5MuMsgFUlUcUcUcUc(arg0->f20, temp_r31, 0, 0, 0, 0xFF);
    fn_800B9488(arg0->f20, temp_r31, 4);
    fn_8006B660(*(void**)((char*)arg0->f20 + 8), temp_r31, 7);
    printIndex__5MuMsgFUlUlPv(arg0->f20, temp_r31, temp_r30, arg0->f28);

    ptr29->slot13(ptr27->f10);

    if (arg1->f4 > lbl_805A2820) {
        ptr29->slot13(ptr27->f10);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(ptr29, ptr27->f10, lbl_8059E62C);
        f32 q;
        f32 b;
        f32 a;
        a = arg1->f4;
        b = arg1->f8;
        q = a / b;
        s32 n = (s32)(lbl_805A2840 * q);
        f32 f31v = (lbl_805A2844 * a) / b;
        fn_80400AB8(lbl_805A2848 * (f32)n);
        vec[0] = f31v;
        vec[1] = lbl_805A2820;
        vec[2] = lbl_805A2820;
        fn_800B67E0(ptr27, vec, lbl_8059E634);
    }
}
}
