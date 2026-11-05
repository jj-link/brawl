#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct FnDst { u32 a; u32 b; s16 c; s16 d; };
struct Class_15DB8 {
    virtual void fn_27_AC9D8();
    virtual void fn_27_AC37C();
    virtual void* fn_27_AC38C(s32);
    virtual void fn_27_ABFCC();
    virtual void fn_27_ACA50();
    virtual void fn_27_ABF8C();
    virtual void fn_27_AC490();
    virtual void fn_27_AC640();
    virtual void fn_27_AC990();
    virtual void fn_27_AC39C();
    virtual void fn_27_AC54C();
    virtual void fn_27_AC6FC(s32, FnDst*);
    virtual void fn_27_AC814();
    virtual void fn_27_AC33C();
    virtual unsigned int fn_27_AC330();
    char pad[0x68];
    u8 flag;
};
struct soNullable {
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();
    virtual void slot5();
    virtual unsigned int slot6(s32);
    char pad[0xc];
    Class_15DB8 inner;
    inline s32 find(s32 limit) {
        if (limit <= -1) return slot4();
        s32 n = slot4();
        for (s32 i = 0; i < n; i++) {
            s16 val = *(s16*)((u8*)inner.fn_27_AC38C(i) + 0xa);
            if (val <= -1) return i;
            if (val > limit) return i;
        }
        return n;
    }
};
extern "C" s32 fn_27_B00AC(soNullable*);
extern "C" void fn_27_B0328(FnDst*, u32*, s32, s16*, s32);
extern "C" s32 fn_27_AF894(soNullable* self, void* arg1, s32 arg2, s16* arg3, s32 arg4) {
    if (self->inner.fn_27_AC330() == 1U) return -1;
    if (self->inner.flag == 0 || arg2 > -1) {
        if (self->slot6(arg2) == 1U) return -1;
    }
    if (self->inner.flag == 0 && arg2 <= -1) {
        s32 result = fn_27_B00AC(self);
        arg2 = result;
        if (result <= -1) return -1;
    }
    s32 idx = self->find(arg4);
    if (idx < 0) return -1;
    s16 sp8 = *arg3;
    FnDst spC;
    fn_27_B0328(&spC, (u32*)arg1, arg2, &sp8, arg4);
    self->inner.fn_27_AC6FC(idx, &spC);
    return arg2;
}