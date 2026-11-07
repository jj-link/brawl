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

struct Inner {
    virtual void i0();
    virtual void i1();
    virtual void* i2(s32 idx);
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual void i6();
    virtual void i7();
    virtual void i8();
    virtual void i9();
    virtual void i10();
    virtual void i11(s32 idx, FnDst* dst);
    virtual void i12();
    virtual void i13();
    virtual unsigned int i14();
};

struct Outer {
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual s32 o4();
    virtual void o5();
    virtual unsigned int o6(s32 arg);
    char pad04[0xC];
    Inner inner;
    char pad14[0x68];
    u8 flag;

    inline s32 find(s32 limit) {
        if (limit <= -1)
            return o4();
        s32 n = o4();
        for (s32 i = 0; i < n; i++) {
            s16 val = *(s16*)((u8*)inner.i2(i) + 0xA);
            if (val <= -1)
                return i;
            if (val > limit)
                return i;
        }
        return n;
    }
};

extern "C" s32 fn_27_1C1964(Outer* self);
extern "C" void fn_27_1CF500(FnDst* dst, void* src, u32 val, s16* hsrc, s32 hval);

extern "C" s32 fn_27_1C115C(Outer* self, void* arg1, s32 arg2, s16* arg3, s32 arg4) {
    if (self->inner.i14() == 1U)
        return -1;

    if (self->flag == 0 || arg2 > -1) {
        if (self->o6(arg2) == 1U)
            return -1;
    }

    if (self->flag == 0 && arg2 <= -1) {
        s32 result = fn_27_1C1964(self);
        arg2 = result;
        if (result <= -1)
            return -1;
    }

    s32 idx = self->find(arg4);
    if (idx < 0)
        return -1;

    s16 sp8 = *arg3;
    FnDst spC;
    fn_27_1CF500(&spC, arg1, (u32)arg2, &sp8, arg4);
    self->inner.i11(idx, &spC);
    return arg2;
}
