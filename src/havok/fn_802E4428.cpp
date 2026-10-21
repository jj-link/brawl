#include <types.h>
#pragma force_active on

extern "C" void fn_802870E4(void*, void*, void*);

extern "C" void fn_802E4428(void* self, void* arg) {
    fn_802870E4(arg, reinterpret_cast<u8*>(self) + 0x10, self);
}
