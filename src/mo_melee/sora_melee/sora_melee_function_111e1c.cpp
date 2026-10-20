#include <types.h>
#pragma force_active on

struct fn_27_Obj {
    u8 pad[0x1c];
    u8 a : 1;
    u8 b : 1;
    u8 c : 6;
};

extern "C" void fn_27_111E1C(void* ptr, u32 flag) {
    fn_27_Obj* obj = *(fn_27_Obj**)ptr;
    obj->b = flag;
}
