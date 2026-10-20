#include <types.h>
#pragma force_active on

struct fn_27_1A391C_obj {
    void* a;
    void* b;
    u32 c;
};

extern char lbl_27_data_3C260[];

extern "C" {
void fn_27_1A391C(fn_27_1A391C_obj* p) {
    p->a = lbl_27_data_3C260;
    p->b = lbl_27_data_3C260 + 0x48;
    p->c = p->c & 1;
}
}
