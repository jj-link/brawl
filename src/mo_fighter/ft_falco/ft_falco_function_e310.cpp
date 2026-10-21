#include <types.h>
#pragma force_active on

struct FalcoElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_108_E2C0(void*, void*);
void fn_108_E490(s16* destination, const s16* source);
void fn_108_E3A0(void*, const s16*, void*);
}

extern "C" void fn_108_E310(void* object, const s16* operation, void* argument) {
    unsigned char* element = static_cast<unsigned char*>(object) + 0xC;
    if ((*operation & 8) != 0) {
        bool enabled = reinterpret_cast<FalcoElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_108_E2C0(element, argument);
        }
    }
    s16 next;
    fn_108_E490(&next, operation);
    fn_108_E3A0(static_cast<unsigned char*>(object) + 4, &next, argument);
}
