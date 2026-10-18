#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_5B30[];

struct fn_27_D4680_Obj {
    void *vtbl;
    s16 a;
    s16 b;
    s16 c;
};

void fn_27_D4680(fn_27_D4680_Obj *self, s16 p2)
{
    self->a = -1;
    self->vtbl = lbl_27_data_5B30;
    self->b = p2;
    self->c = -1;
}
}
