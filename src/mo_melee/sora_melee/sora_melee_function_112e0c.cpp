#include <types.h>
#pragma force_active on

struct fn_27_112E0C_obj {
    u8 pad[0x20];
    u8 flag : 1;
};

extern "C" void fn_27_112E0C(fn_27_112E0C_obj** self, u32 value) {
    (*self)->flag = value;
}
