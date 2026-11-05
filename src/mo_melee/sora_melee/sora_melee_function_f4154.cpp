#include <types.h>
#pragma force_active on
struct FnDst { u32 a; u32 b; s16 c; s16 d; };
struct InnerObj {
    virtual void v00(); virtual void v04();
    virtual void* v08(s32);
    virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28();
    virtual void v2c(s32, FnDst*);
    virtual void v30(); virtual void v34();
    virtual unsigned int v38();
};
class soNullable {
public:
    virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual s32 slot4(); virtual void slot5(); virtual unsigned int slot6(s32);
    char pad04[0xC];
    InnerObj inner;
    char pad14[0x38];
    u8 flag;
    inline s32 find(s32 limit) {
        if (limit <= -1) return slot4();
        s32 n = slot4();
        for (s32 i = 0; i < n; i++) {
            s16 val = *(s16*)((u8*)inner.v08(i) + 0xA);
            if (val <= -1) return i;
            if (val > limit) return i;
        }
        return n;
    }
};
extern "C" s32 fn_27_F495C(soNullable*);
extern "C" void fn_27_FE084(FnDst*, u32*, s32, s16*, s32);
extern "C" s32 fn_27_F4154(soNullable* self, void* arg1, s32 arg2, s16* arg3, s32 arg4) {
    if (self->inner.v38() == 1U) return -1;
    if (self->flag == 0 || arg2 > -1) {
        if (self->slot6(arg2) == 1U) return -1;
    }
    if (self->flag == 0 && arg2 <= -1) {
        s32 result = fn_27_F495C(self);
        arg2 = result;
        if (result <= -1) return -1;
    }
    s32 idx = self->find(arg4);
    if (idx < 0) return -1;
    s16 sp8 = *arg3;
    FnDst spC;
    fn_27_FE084(&spC, (u32*)arg1, arg2, &sp8, arg4);
    self->inner.v2c(idx, &spC);
    return arg2;
}