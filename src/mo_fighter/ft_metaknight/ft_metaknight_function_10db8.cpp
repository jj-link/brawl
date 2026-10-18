#include <types.h>
#pragma force_active on

extern "C" const float lbl_111_rodata_48;

extern "C" void fn_111_10DB8(void* object) {
    float value = lbl_111_rodata_48;
    *reinterpret_cast<float*>(static_cast<u8*>(object) + 0xC) = value;
    *reinterpret_cast<float*>(static_cast<u8*>(object) + 0x8) = value;
}
