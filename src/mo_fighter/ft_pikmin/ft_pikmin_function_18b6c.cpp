#include <types.h>
#pragma force_active on

extern "C" u32 fn_113_18110(void*);
extern "C" s32 fn_113_182BC(f32);
extern "C" f32 fn_113_182E4(f32*);
extern "C" u64 fn_113_18DE4(void*);
extern "C" u32 fn_113_18F1C(void*);

struct Pair {
    u32 x;
    u32 y;
};

struct Pad8 {
    u32 a;
    u32 b;
};

class Sub : public Pad8 {
public:
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual f32 m5(void* a, s32 b, s32 c);
};

class Obj {
public:
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual s32 m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual Sub* m24();
};

extern "C" s32 fn_113_18B6C(void* arg0) {
    Obj* st = *(Obj**)((char*)*(void**)((char*)*(void**)((char*)arg0 + 0x60) + 0xd8) + 0x70);
    s32 kind = st->m17();
    bool flag;
    switch (kind) {
    case 0x1e:
    case 0x1f:
    case 0x2c:
        flag = true;
        break;
    default:
        flag = false;
        break;
    }
    if (flag == 1) {
        return 0;
    }
    if (fn_113_18F1C(arg0) == 1 || fn_113_18110(arg0) == 1) {
        Pair v;
        u64 raw = fn_113_18DE4(arg0);
        v = *(Pair*)&raw;
        s32 r = fn_113_182BC(*(f32*)&v.x);
        if (r != 0) {
            r = fn_113_182BC(*(f32*)&v.y);
        }
        if (r != 0) {
            void* mod = *(void**)((char*)arg0 + 0x60);
            Obj* h = *(Obj**)((char*)*(void**)((char*)mod + 0xd8) + 0x64);
            Sub* q = h->m24();
            f32 lim = q->m5(mod, 0xfbc, 0);
            if (!(fn_113_182E4((f32*)&v) > lim)) {
                goto tail;
            }
        }
        return 0;
    }
tail:
    st = *(Obj**)((char*)*(void**)((char*)*(void**)((char*)arg0 + 0x60) + 0xd8) + 0x70);
    switch (st->m17()) {
    case 16:
    case 19:
    case 21:
    case 25:
    case 26:
    case 28:
        return 0;
    default:
        return 1;
    }
}
