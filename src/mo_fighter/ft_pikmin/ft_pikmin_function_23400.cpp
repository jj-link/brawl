#include <types.h>
#pragma force_active on

class soTarget {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual s32 vf3();
};

struct soPair {
    soTarget* p;
    u8 b;
};

extern "C" {
soPair fn_27_778CC(soTarget* p, u32 n);
int fn_113_23504(soPair*);
float fn_113_23524(soPair*);
u32 fn_113_2357C(soPair*);
s32 fn_113_2359C(soPair*);
float fn_113_23CA0(void*, s32);
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, u32 id, u32 index);
}

extern "C" bool fn_113_23400(void* a0, void* a1, soTarget* t, void* acc) {
    soPair pair;
    soPair tmp = fn_27_778CC(t, 0);
    pair.p = tmp.p;
    pair.b = tmp.b;
    soPair* pp = &pair;
    float v;
    if (fn_113_23504(pp) == 1) {
        v = fn_113_23524(pp);
    } else {
        v = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, fn_113_2357C(pp), 0);
    }
    s32 n = 3;
    if (t->vf3() - 1 >= 2) {
        soPair p2 = fn_27_778CC(t, 1);
        n = fn_113_2359C(&p2);
    }
    float r = fn_113_23CA0(acc, n);
    __fabsf(r);
    return r >= v;
}
