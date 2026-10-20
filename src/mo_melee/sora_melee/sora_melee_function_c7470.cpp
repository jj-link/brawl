#include <types.h>
#pragma force_active on

typedef struct {
    void *f0;
    s32 f4;
    s32 f8;
    s32 fc;
} fn_27_C7470_t;

extern char lbl_27_data_2490[];

extern "C" void fn_27_C7470(fn_27_C7470_t *p, s32 a, s32 b) {
    p->f4 = 0;
    p->f0 = lbl_27_data_2490;
    p->f8 = a;
    p->fc = b;
    if (a == 0) {
        p->fc = 0;
    }
}
