#include <types.h>
#pragma force_active on

struct Mtx34S { float m[3][4]; };

extern "C" {
extern Mtx34S lbl_80497810;
extern const float lbl_805A1980;
void fn_801EC158(Mtx34S*);
void fn_801EC1B8(Mtx34S*, Mtx34S*, Mtx34S*);
}

extern "C" void fn_80065300(void*, int kind, void*, void*, Mtx34S* m) {
    switch (kind) {
    case 1: {
        Mtx34S tmp;
        lbl_80497810 = *m;
        fn_801EC158(&tmp);
        float s = lbl_805A1980;
        tmp.m[0][2] *= s;
        tmp.m[1][2] *= s;
        tmp.m[2][2] *= s;
        fn_801EC1B8(m, &tmp, m);
        break;
    }
    case 4:
        *m = lbl_80497810;
        break;
    }
}
