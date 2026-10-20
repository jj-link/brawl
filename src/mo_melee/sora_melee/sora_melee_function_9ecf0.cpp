#include <types.h>
#pragma force_active on

struct FlagHolder {
    u8 pad[0x135];
    u8 hi : 4;
    u8 flag : 1;
    u8 lo : 3;
};

extern "C" {
void fn_27_9ECF0(void* self, u32 flag) {
    ((FlagHolder*)self)->flag = flag;
}
}
