#include <types.h>
#pragma force_active on

extern "C" void fn_103_9C84(void*);

extern "C" void fn_103_D2A0(void* self) {
    fn_103_9C84(reinterpret_cast<u8*>(self) - 0x186F0);
}
