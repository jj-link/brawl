#include <types.h>
#include <gr/gr_madein.h>
#pragma force_active on

extern f32 lbl_90_rodata_2C;

struct Obj90 {
    grMadein* m0;
    grMadein* m4;
    grMadein* m8;
    int pad0C;
    f32 m10;
    int m14;
    int m18;
    u32 m1C;
};

extern "C" void fn_90_1304(Obj90* p) {
    if (!(p->m1C & 1)) {
        grMadein* g = p->m0;
        if (g != 0 && (p->m18 != 0 || !(p->m1C & 0x100))) {
            p->m18 = 0;
            p->m1C = p->m1C | 0x100;
            g->setMotion(0);
            g->startEntityAutoLoop();
        }
        if (p->m4 != 0) {
            if (p->m1C & 0x200) {
                p->m1C = p->m1C & 0xFFFFFDFF;
                p->m4->endEntity();
            }
        }
        if (p->m8 != 0) {
            if (p->m1C & 0x400) {
                p->m1C = p->m1C & 0xFFFFFBFF;
                p->m8->endEntity();
            }
        }
        p->m1C = p->m1C | 1;
    }
    p->m10 = lbl_90_rodata_2C;
}
