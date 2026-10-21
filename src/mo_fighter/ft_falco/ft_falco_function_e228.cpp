#include <types.h>
#pragma force_active on

namespace {
struct FalcoElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_108_E1D8(void* element, void* argument);
void fn_108_E490(s16* destination, const s16* source);
s32 fn_108_E2B8(void* a, void* b, void* c);
}

extern "C" void fn_108_E228(unsigned char* composite, const s16* operation, void* argument) {
    unsigned char* element = composite + 0xC;
    if ((operation[0] & 4) != 0) {
        bool enabled = reinterpret_cast<FalcoElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_108_E1D8(element, argument);
        }
    }
    s16 next;
    fn_108_E490(&next, operation);
    fn_108_E2B8(composite + 4, &next, argument);
}
