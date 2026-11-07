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

struct Hdr {
    s16 val;
    s32 pad;
};

struct InnerObj {
    virtual void v0();
    virtual void v1();
    virtual void* v2(s32 idx);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(s32 idx, FnDst* dst);
    virtual void v12();
    virtual void v13();
    virtual unsigned int v14();
};

struct OuterObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4();
    virtual void v5();
    virtual unsigned int v6(s32 arg);
    char pad[0xC];
    InnerObj inner;
    char pad2[0x68];
    u8 flag;

    inline s32 find(s32 limit) {
        if (limit <= -1) return v4();
        s32 n = v4();
        for (s32 i = 0; i < n; i++) {
            s16 val = *(s16*)((u8*)inner.v2(i) + 0xE);
            if (val <= -1) return i;
            if (val > limit) return i;
        }
        return n;
    }
};

extern "C" s32 fn_27_1ACBA4(OuterObj* self);
extern "C" void fn_27_D8810(FnDst* dst, u32* src, s32 val, s16* hsrc, s32 hval);

extern "C" s32 fn_27_1AC430(OuterObj* self, void* arg1, s32 arg2, s16* arg3, s32 arg4) {
    if (self->inner.v14() == 1U)
        return -1;
    if (self->flag == 0 || arg2 > -1) {
        if (self->v6(arg2) == 1U)
            return -1;
    }
    if (self->flag == 0 && arg2 <= -1) {
        s32 result = fn_27_1ACBA4(self);
        arg2 = result;
        if (result <= -1)
            return -1;
    }
    s32 idx = self->find(arg4);
    if (idx < 0)
        return -1;
    Hdr h;
    h.val = *arg3;
    FnDst dst;
    fn_27_D8810(&dst, (u32*)arg1, arg2, &h.val, arg4);
    self->inner.v11(idx, &dst);
    return arg2;
}
