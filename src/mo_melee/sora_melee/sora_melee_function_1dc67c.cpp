#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1DC67C(void* self, s32 idx, s32 flag) {
    if (flag == 0) {
        switch (idx) {
        case 0:
            return *(void**)(*(u8**)((u8*)self + 0x8) + 0x14);
        case 1:
            return *(void**)(*(u8**)((u8*)self + 0x8) + 0x18);
        case 2:
            return *(void**)(*(u8**)((u8*)self + 0x8) + 0x1c);
        case 3:
            return *(void**)(*(u8**)((u8*)self + 0x8) + 0x20);
        case 5:
            return *(void**)((u8*)self + 0x38);
        }
    }
    return nullptr;
}
