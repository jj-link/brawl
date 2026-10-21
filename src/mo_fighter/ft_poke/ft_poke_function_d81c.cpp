#include <types.h>
#pragma force_active on

namespace {
struct PokeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_116_D7CC(void* element, void* argument);
void fn_116_D99C(s16* destination, const s16* source);
s32 fn_116_D8AC(void* object, s16* value, void* argument);
}

extern "C" void fn_116_D81C(unsigned char* object, const s16* source, void* argument) {
    unsigned char* element = object + 0xC;
    if (source[0] & 8) {
        bool enabled = reinterpret_cast<PokeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_116_D7CC(element, argument);
        }
    }
    s16 value;
    fn_116_D99C(&value, source);
    fn_116_D8AC(object + 4, &value, argument);
}
