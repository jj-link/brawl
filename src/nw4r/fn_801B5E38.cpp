#include <types.h>
#include <stddef.h>
#pragma force_active on

typedef struct {
    f64 m0;
    f64 m1;
    f64 m2;
    f64 m3;
    f64 m4;
    f64 m5;
} SixD;

extern "C" void* fn_801B5E38(void* a, void* b) {
    if (b != 0) {
        SixD* p = *(SixD**)a;
        if (p != 0) {
            SixD* d = (SixD*)b;
            d->m0 = p->m0;
            d->m1 = p->m1;
            d->m2 = p->m2;
            d->m3 = p->m3;
            d->m4 = p->m4;
            d->m5 = p->m5;
            return b;
        }
    }
    return 0;
}
