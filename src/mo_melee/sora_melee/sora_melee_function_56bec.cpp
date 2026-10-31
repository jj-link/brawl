#include <types.h>
#pragma force_active on

class fnTarget {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf7(s32 a, u32 b, u32 c, u32 d);
};

extern "C" {
extern const u32 lbl_27_rodata_558[29][4];

void fn_27_56BEC(fnTarget* p, u32 a, u32 b) {
    u32 v = lbl_27_rodata_558[a][b];
    if (v == 0xFFFFFFFF) {
        return;
    }
    p->vf7(v, 0, 0, 0);
}
}
