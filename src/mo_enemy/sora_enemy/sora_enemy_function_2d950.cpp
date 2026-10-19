#include <types.h>
#pragma force_active on

struct FnObj;

extern "C" void fn_27_D4DBC(FnObj* obj, s16 v);
extern "C" void fn_27_D4DDC(FnObj* obj, s16 a, s8 b);
extern "C" char lbl_41_data_D7C[];

extern "C" FnObj* fn_41_2D950(FnObj* self, int a, int b) {
    s16 v = 0x11;
    fn_27_D4DBC(self, v);
    *(char**)self = lbl_41_data_D7C;
    fn_27_D4DDC(self, (s16)a, (s8)b);
    return self;
}
