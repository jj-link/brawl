#include <types.h>
#pragma force_active on

struct FlagHolder {
    u32 pad[2];
    u32 dword8;
};

extern "C" void fn_27_29580C(FlagHolder* arg) {
    arg->dword8 &= ~0x2000U;
}
