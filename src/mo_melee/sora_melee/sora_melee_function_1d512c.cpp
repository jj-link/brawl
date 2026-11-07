#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_2710;

struct Obj1D512C {
    float* f[22];
    int* n[75];
    u8* b[20];
    u8 fc[22];
    u8 nc[75];
    u8 bc[20];
};

extern "C" void fn_27_1D512C(Obj1D512C* p) {
    int i, j;
    for (i = 0; i < 22; i++) {
        for (j = 0; j < p->fc[i]; j++) {
            p->f[i][j] = lbl_27_rodata_2710;
        }
    }
    for (i = 0; i < 75; i++) {
        for (j = 0; j < p->nc[i]; j++) {
            p->n[i][j] = 0;
        }
    }
    for (i = 0; i < 20; i++) {
        for (j = 0; j < p->bc[i]; j++) {
            p->b[i][j] = 0;
        }
    }
}
