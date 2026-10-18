#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_7310[];
}

struct FnObj {
    void *vtbl;
    s16 a;
    s16 b;
    s16 c;
};

extern "C" void fn_27_D4DBC(FnObj *obj, s16 v)
{
    obj->a = -1;
    obj->vtbl = lbl_27_data_7310;
    obj->b = v;
    obj->c = -1;
}
