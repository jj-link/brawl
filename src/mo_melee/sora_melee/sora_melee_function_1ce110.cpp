#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;

struct SubObj {
    virtual void v0();
    virtual void v1();
    virtual char* get(s32 idx);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void set(s32 idx, void* prop);
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
    virtual u32 check(s32 a);
    char pad0[0xC];
    SubObj sub;
    char pad[0x19C - 0x14];
    u8 flag;

    inline s32 find(s32 b) {
        if (b <= -1) return count();
        s32 n = count();
        for (s32 i = 0; i < n; i++) {
            s16 v = *(s16*)(sub.get(i) + 0xa);
            if (v <= -1) return i;
            if (v > b) return i;
        }
        return n;
    }
};

extern "C" s32 fn_27_1CE918(Outer* self);
extern "C" void fn_27_FE124(void* out, s32 e, s32 a, s16* s, s32 b);

extern "C" s32 fn_27_1CE110(Outer* self, s32 arg1, s32 arg2, s16* arg3, s32 arg4)
{
    if (self->sub.full() == 1U) return -1;
    if ((self->flag == 0 || arg2 > -1) && self->check(arg2) == 1U) return -1;
    if (self->flag == 0 && arg2 <= -1) {
        arg2 = fn_27_1CE918(self);
        if (arg2 <= -1) return -1;
    }
    s32 idx = self->find(arg4);
    if (idx < 0) return -1;
    s16 t = *arg3;
    s32 p[3];
    fn_27_FE124(p, arg1, arg2, &t, arg4);
    self->sub.set(idx, p);
    return arg2;
}
