#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;

struct FnDst { u32 a; u32 b; s16 c; s16 d; };

class InnerObj {
public:
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
    virtual unsigned int s14();
    char pad04[0x14];
    u8 flag;
};

class OuterObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual int v6(s32 arg);
    char pad04[0xC];
    InnerObj inner;

    inline s32 find(s32 limit) {
        if (limit <= -1)
            return v4();
        s32 n = v4();
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

extern "C" s32 fn_27_2646BC(OuterObj* self);
extern "C" void fn_27_FE084(FnDst* dst, u32* src, s32 val, s16* p, s32 val2);

extern "C" s32 fn_27_263EA4(OuterObj* self, void* arg1, s32 arg2, s16* arg3, s32 arg4) {
    if (self->inner.s14() == 1U)
        return -1;

    if (self->inner.flag == 0 || arg2 > -1) {
        if (self->v6(arg2) == 1U)
            return -1;
    }

    if (self->inner.flag == 0 && arg2 <= -1) {
        s32 result = fn_27_2646BC(self);
        arg2 = result;
        if (result <= -1)
            return -1;
    }

    s32 idx = self->find(arg4);
    if (idx < 0)
        return -1;

    s16 sp8 = *arg3;
    FnDst spC;
    fn_27_FE084(&spC, (u32*)arg1, arg2, &sp8, arg4);
    self->inner.s11(idx, &spC);
    return arg2;
}
