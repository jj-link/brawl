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
void fn_103_CB8C(void* element, void* argument);
s16* fn_103_CF2C(s16* destination, const s16* source);
s32 fn_103_CC6C(void* secondary, const s16* mask, void* argument);

s32 fn_103_CBDC(PeachAttributeArray* array, const s16* mask, void* argument) {
    PeachAttributeElement* element = &array->element;
    if ((*mask & 2) && element->enabled.isEnable() == true && element->blocked == 0) {
        fn_103_CB8C(element, argument);
    }
    s16 copiedMask;
    fn_103_CF2C(&copiedMask, mask);
    return fn_103_CC6C(reinterpret_cast<u8*>(array) + 4, &copiedMask, argument);
}
}
