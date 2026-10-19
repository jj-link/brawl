#include <types.h>
#pragma force_active on

struct ArrayDesc {
    u32* m_elements;
    s32 m_size;
};

extern "C" bool fn_41_2B9D4(void* obj, u32 value) {
    ArrayDesc* desc = *(ArrayDesc**)((char*)obj + 0x68);
    if (!desc) return false;
    u32* arr = desc->m_elements;
    if (!arr) return false;
    s32 count = desc->m_size;
    if (count < 0) return false;
    for (s32 i = 0; i < count; i++) {
        if (arr[i] == value) return true;
    }
    return false;
}
