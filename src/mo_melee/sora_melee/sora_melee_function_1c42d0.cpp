#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;

struct FnDst {
    u32 a;
    u32 b;
    s16 c;
    s16 d;
};

struct InnerObj {
    virtual void s0();
    virtual void s1();
    virtual void* s2(s32 idx);
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11(s32 idx, FnDst* dst);
    virtual void s12();
    virtual void s13();
    virtual u32 s14();
};

struct OuterObj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual s32 s4();
    virtual void s5();
    virtual u32 s6(s32 arg);
    char pad04[0xC];
    InnerObj inner;
    char pad54[0x44];
    u8 flag;

    inline s32 find(s32 limit) {
        if (limit <= -1)
            return s4();
        s32 n = s4();
        for (s32 i = 0; i < n; i++) {
            s16 val = *(s16*)((u8*)inner.s2(i) + 0xA);
            if (val <= -1)
                return i;
            if (val > limit)
                return i;
        }
        return n;
    }
};

extern "C" s32 fn_27_1C4AD8(OuterObj* self);
extern "C" void fn_27_FE0FC(FnDst* dst, u32* src, s32 val, s16* hsrc, s32 hval);

extern "C" s32 fn_27_1C42D0(OuterObj* self, void* arg1, s32 arg2, s16* arg3, s32 arg4) {
    if (self->inner.s14() == 1U)
        return -1;
    if (self->flag == 0 || arg2 > -1) {
        if (self->s6(arg2) == 1U)
            return -1;
    }
    if (self->flag == 0 && arg2 <= -1) {
        s32 result = fn_27_1C4AD8(self);
        arg2 = result;
        if (result <= -1)
            return -1;
    }
    s32 idx = self->find(arg4);
    if (idx < 0)
        return -1;
    s16 sp8 = *arg3;
    FnDst spC;
    fn_27_FE0FC(&spC, (u32*)arg1, arg2, &sp8, arg4);
    self->inner.s11(idx, &spC);
    return arg2;
}
