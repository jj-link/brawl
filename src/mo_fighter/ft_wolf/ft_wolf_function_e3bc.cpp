#include <types.h>
#pragma force_active on

extern "C" void fn_125_E36C(void*, void*);
extern "C" void fn_125_E53C(s16*, const s16*);
extern "C" void fn_125_E44C(void*, const s16*, void*);

struct WolfElementFlags {
    unsigned char enabled : 1;
};

extern "C" void fn_125_E3BC(void* object, const s16* operation, void* argument) {
    unsigned char* element = static_cast<unsigned char*>(object) + 0xC;

    if (*operation & 8) {
        bool enabled = reinterpret_cast<WolfElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_125_E36C(element, argument);
        }
    }

    s16 next;
    fn_125_E53C(&next, operation);
    fn_125_E44C(static_cast<unsigned char*>(object) + 4, &next, argument);
}
