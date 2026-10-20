#include <types.h>
#pragma force_active on

extern "C" {
void fn_109_BDD8(void* element, void* argument);
void fn_109_BFA8(s16* destination, const s16* source);
s32 fn_109_BEB8(void* destination, const s16* operation, void* argument);
}

struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" void fn_109_BE28(void* object, const s16* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation[0] & 0x8) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_109_BDD8(element, argument);
        }
    }
    s16 next;
    fn_109_BFA8(&next, operation);
    fn_109_BEB8(composite + 4, &next, argument);
}
