#include <types.h>
#pragma force_active on

class soTarget;

class soTarget {
public:
    virtual void vf0();
    virtual void vf1();
    virtual soTarget* vf2(u32 v);
};

struct soPair {
    soTarget* p;
    u8 b;
};

extern "C" {
soPair fn_27_778CC(soTarget* p, u32 n) {
    soPair s;
    s.p = p->vf2(n + 1);
    s.b = 0;
    return s;
}
}
