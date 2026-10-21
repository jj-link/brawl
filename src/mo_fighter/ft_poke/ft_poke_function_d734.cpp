#include <types.h>
#pragma force_active on

namespace {
struct PokeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_116_D6E4(void* element, void* argument);
void fn_116_D99C(s16* destination, const s16* source);
s32 fn_116_D7C4(void* object, s16* value, void* argument);
}

extern "C" void fn_116_D734(unsigned char* object, const s16* operation, void* argument) {
    unsigned char* element = object + 0xC;
    if (operation[0] & 4) {
        bool enabled = reinterpret_cast<PokeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_116_D6E4(element, argument);
        }
    }
    s16 value;
    fn_116_D99C(&value, operation);
    fn_116_D7C4(object + 4, &value, argument);
}
