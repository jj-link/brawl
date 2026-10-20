#include <types.h>

#pragma force_active on

namespace {
struct ElementFlags {
    unsigned char enabled : 1;
};
}

extern "C" void fn_97_E53C(void*, void*);
extern "C" void fn_97_E624(s16*, const s16*);
extern "C" void fn_97_E61C(void*, void*, void*);

extern "C" void fn_97_E58C(void* object, const s16* operation, void* argument) {
    unsigned char* composite = (unsigned char*)object;
    unsigned char* element = composite + 0xC;

    if (operation[0] & 4) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_97_E53C(element, argument);
        }
    }

    s16 next;
    fn_97_E624(&next, operation);
    fn_97_E61C(composite + 4, &next, argument);
}
