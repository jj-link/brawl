#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct FnDst { u32 a; u32 b; s16 c; s16 d; };
class Object_vptr_10 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2(s32);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(s32, FnDst*);
    virtual void slot12();
    virtual void slot13();
    virtual unsigned int slot14();
    char pad[0x20];
    u8 flag;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();
    virtual void slot5();
    virtual unsigned int slot6(s32);
    char pad[0xC];
    Object_vptr_10 inner;
    inline s32 find(s32 limit) {
        if (limit <= -1) return slot4();
        s32 n = slot4();
        for (s32 i = 0; i < n; i++) {
            s16 val = *(s16*)((u8*)inner.slot2(i) + 0xA);
            if (val <= -1) return i;
            if (val > limit) return i;
        }
        return n;
    }
};
extern "C" s32 fn_27_FD3D4(Object_vptr_0*);
extern "C" void fn_27_FE1EC(FnDst*, u32*, s32, s16*, s32);
extern "C" s32 fn_27_FCBCC(Object_vptr_0* self, void* arg1, s32 arg2, s16* arg3, s32 arg4) {
    if (self->inner.slot14() == 1U) return -1;
    if (self->inner.flag == 0 || arg2 > -1) {
        if (self->slot6(arg2) == 1U) return -1;
    }
    if (self->inner.flag == 0 && arg2 <= -1) {
        s32 result = fn_27_FD3D4(self);
        arg2 = result;
        if (result <= -1) return -1;
    }
    s32 idx = self->find(arg4);
    if (idx < 0) return -1;
    s16 sp8 = *arg3;
    FnDst spC;
    fn_27_FE1EC(&spC, (u32*)arg1, arg2, &sp8, arg4);
    self->inner.slot11(idx, &spC);
    return arg2;
}