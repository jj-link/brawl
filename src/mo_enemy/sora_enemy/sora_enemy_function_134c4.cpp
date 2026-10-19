#include <types.h>

extern "C" void fn_27_60A90(void*, void*);

#pragma force_active on
extern "C" void fn_41_134C4(void* self, void* arg) {
    fn_27_60A90(arg, reinterpret_cast<u8*>(self) + 0x64);
}
