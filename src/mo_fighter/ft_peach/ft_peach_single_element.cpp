#include <types.h>

struct PeachSingleElement {
    u8 unknown[0xC];
    u8 element;
};

extern "C" {
void* fn_103_B3B8(PeachSingleElement* array, s32 index) {
    if (index == 0) {
        return &array->element;
    }
    return 0;
}

const void* fn_103_B3D0(const PeachSingleElement* array, s32 index) {
    if (index == 0) {
        return &array->element;
    }
    return 0;
}
}
