#include <types.h>
#pragma force_active on

void fn_80387DD0(void* arg0, u32 arg1) {
    *(u32*)((u8*)arg0 + 0x28) = arg1;
}
