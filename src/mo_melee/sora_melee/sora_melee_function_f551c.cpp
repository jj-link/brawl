#pragma force_active on
typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct FE0AC_Dst {
    int b[3];
};
struct Unit {
    virtual void v0(); virtual void v1();
    virtual char* get(int);
    virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual void set(int, FE0AC_Dst*);
    virtual void v12(); virtual void v13();
    virtual unsigned int full();
};
struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int count();
    virtual void v5();
    virtual unsigned int bad(int);
    char pad0[12];
    Unit unit;
    char pad[0x34 - 0x14];
    unsigned char flag;
    inline int find(short b) {
        if (b <= -1) return count();
        int n = count();
        for (int i = 0; i < n; i++) {
            int v = *(short*)(unit.get(i) + 0xa);
            if (v <= -1) return i;
            if (v > b) return i;
        }
        return n;
    }
};
extern "C" int fn_27_F5D24(Obj*);
extern "C" void fn_27_FE0AC(FE0AC_Dst* dst, s32* src, u32 val, s16* src2, s16 val2);
extern "C" int fn_27_F551C(Obj* self, s32* e, int a, short* s, short b)
{
    if (self->unit.full() == 1U) return -1;
    if ((self->flag == 0 || a > -1) && self->bad(a) == 1U) return -1;
    if (self->flag == 0 && a <= -1) {
        a = fn_27_F5D24(self);
        if (a <= -1) return -1;
    }
    int idx = self->find(b);
    if (idx < 0) return -1;
    short t = *s;
    FE0AC_Dst p;
    fn_27_FE0AC(&p, e, a, &t, b);
    self->unit.set(idx, &p);
    return a;
}
