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

struct Item {
    char pad[0xA];
    s16 val;
};

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual Item* get(s32 idx);
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
    char pad[0x14];
};

struct Outer {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 count();
    virtual void v5();
    virtual u32 check(s32 a);
    char pad0[0xC];
    Inner inner;
    u8 flag;
    inline s32 find(s32 limit) {
        if (limit <= -1)
            return count();
        s32 n = count();
        for (s32 i = 0; i < n; i++) {
            s16 val = inner.get(i)->val;
            if (val <= -1)
                return i;
            if (val > limit)
                return i;
        }
        return n;
    }
};

extern "C" s32 fn_27_1E5208(Outer* self);
extern "C" void fn_27_FE1C4(FnDst* dst, const int* a, s32 b, const s16* c, s32 d);

extern "C" s32 fn_27_1E49F0(Outer* self, const int* arg1, s32 idx, s16* arg3, s32 limit)
{
    if (self->inner.full() == 1U)
        return -1;

    if ((self->flag == 0 || idx > -1) && self->check(idx) == 1U)
        return -1;

    if (self->flag == 0 && idx <= -1) {
        s32 result = fn_27_1E5208(self);
        idx = result;
        if (result <= -1)
            return -1;
    }

    s32 pos = self->find(limit);
    if (pos < 0)
        return -1;

    s16 sp8 = *arg3;
    FnDst spC;
    fn_27_FE1C4(&spC, arg1, idx, &sp8, limit);
    self->inner.set(pos, &spC);
    return idx;
}
