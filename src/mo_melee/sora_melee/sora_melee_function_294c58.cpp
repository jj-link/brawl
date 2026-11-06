#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;

struct FnDst { u32 a; u32 b; s16 c; s16 d; };

struct InnerObj {
    virtual void v08();
    virtual void v0c();
    virtual void* v10(s32 idx);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34(s32 idx, FnDst* dst);
    virtual void v38();
    virtual void v3c();
    virtual unsigned int v40();
};

struct OuterObj {
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual s32 v18();
    virtual void v1c();
    virtual unsigned int v20(s32 arg);
    char pad04[0xC];
    InnerObj inner;
    char pad14[0xF8];
    u8 flag;

    inline s32 find(s32 limit) {
        if (limit <= -1) return v18();
        s32 n = v18();
        for (s32 i = 0; i < n; i++) {
            s16 val = *(s16*)((u8*)inner.v10(i) + 0xA);
            if (val <= -1) return i;
            if (val > limit) return i;
        }
        return n;
    }
};

extern "C" s32 fn_27_295470(OuterObj* self);
extern "C" void fn_27_FE14C(FnDst* dst, u32* src, s32 val, s16* src2, s32 val2);

extern "C" s32 fn_27_294C58(OuterObj* self, void* arg1, s32 arg2, s16* arg3, s32 arg4) {
    if (self->inner.v40() == 1U) return -1;
    if (self->flag == 0 || arg2 > -1) {
        if (self->v20(arg2) == 1U) return -1;
    }
    if (self->flag == 0 && arg2 <= -1) {
        s32 result = fn_27_295470(self);
        arg2 = result;
        if (result <= -1) return -1;
    }
    s32 idx = self->find(arg4);
    if (idx < 0) return -1;
    s16 sp8 = *arg3;
    FnDst spC;
    fn_27_FE14C(&spC, (u32*)arg1, arg2, &sp8, arg4);
    self->inner.v34(idx, &spC);
    return arg2;
}
