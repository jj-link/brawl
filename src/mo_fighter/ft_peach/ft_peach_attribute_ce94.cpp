#include <so/so_enable.h>
#include <types.h>

struct PeachAttributeElement {
    void* vtable;
    u8 unknown;
    soEnable enabled;
    u8 blocked;
};

struct PeachAttributeArray {
    u8 unknown[0xC];
    PeachAttributeElement element;
};

extern "C" {
void fn_103_CE44(void* element, void* argument);
s16* fn_103_CF2C(s16* destination, const s16* source);
s32 fn_103_CF24(void* secondary, const s16* mask, void* argument);

s32 fn_103_CE94(PeachAttributeArray* array, const s16* mask, void* argument) {
    PeachAttributeElement* element = &array->element;
    if ((*mask & 4) && element->enabled.isEnable() == true && element->blocked == 0) {
        fn_103_CE44(element, argument);
    }
    s16 copiedMask;
    fn_103_CF2C(&copiedMask, mask);
    return fn_103_CF24(reinterpret_cast<u8*>(array) + 4, &copiedMask, argument);
}
}
