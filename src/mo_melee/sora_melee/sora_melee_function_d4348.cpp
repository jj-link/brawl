#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_2103C[];
}

struct FnObj27 {
    void* vtbl;
    s16 a;
    s16 b;
    s16 c;
};

extern "C" void fn_27_D4348(FnObj27* p, s16 x) {
    p->vtbl = lbl_27_data_2103C;
    p->a = -1;
    p->b = x;
    p->c = -1;
}
