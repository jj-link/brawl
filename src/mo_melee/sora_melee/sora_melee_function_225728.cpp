#include <types.h>

#pragma force_active on
extern "C" void setBgmChange__5StageFfbUl(void* self, bool b, f32 f, u32 v) {
    *reinterpret_cast<u8*>(reinterpret_cast<u8*>(self) + 0x184) = b;
    *reinterpret_cast<u32*>(reinterpret_cast<u8*>(self) + 0x188) = v;
    *reinterpret_cast<f32*>(reinterpret_cast<u8*>(self) + 0x18C) = f;
}
