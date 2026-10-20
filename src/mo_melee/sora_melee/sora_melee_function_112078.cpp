#include <types.h>
#pragma force_active on

struct fn_27_112078_Obj {
    u8 pad[0x1E];
    u8 flag0 : 1;
    u8 rest : 7;
};

extern "C" {
void fn_27_112078(fn_27_112078_Obj** self, u32 flag) {
    fn_27_112078_Obj* obj = *self;
    obj->flag0 = flag;
}
}
