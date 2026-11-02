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

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void* get(s32 idx);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void set(s32 idx, FnDst* dst);
    virtual void v12();
    virtual void v13();
    virtual u32 full();
};

struct Outer {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 count();
    virtual void v5();
    virtual u32 check(s32 arg);
    char pad0[0xC];
    Sub sub;
    char pad[0x28 - 0x14];
    u8 flag;

    inline s32 find(s32 limit) {
        if (limit <= -1)
            return count();
        s32 n = count();
        for (s32 i = 0; i < n; i++) {
            s16 val = *(s16*)((u8*)sub.get(i) + 0xA);
            if (val <= -1)
                return i;
            if (val > limit)
                return i;
        }
        return n;
    }
};

extern "C" s32 fn_27_F0420(Outer* self);
extern "C" void fn_27_FDFBC(FnDst* dst, u32* src, u32 val, s16* half, s32 val2);

extern "C" s32 fn_27_EFC18(Outer* self, void* arg1, s32 arg2, s16* arg3, s32 arg4) {
    if (self->sub.full() == 1U)
        return -1;

    if (self->flag == 0 || arg2 > -1) {
        if (self->check(arg2) == 1U)
            return -1;
    }

    if (self->flag == 0 && arg2 <= -1) {
        s32 result = fn_27_F0420(self);
        arg2 = result;
        if (result <= -1)
            return -1;
    }

    s32 idx = self->find(arg4);
    if (idx < 0)
        return -1;

    s16 sp8 = *arg3;
    FnDst spC;
    fn_27_FDFBC(&spC, (u32*)arg1, (u32)arg2, &sp8, arg4);
    self->sub.set(idx, &spC);
    return arg2;
}
