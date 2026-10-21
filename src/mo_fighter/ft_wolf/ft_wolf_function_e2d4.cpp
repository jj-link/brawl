#include <types.h>
#pragma force_active on

namespace {
struct WolfTraversalIndex {
    s16 value;
};

struct WolfElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_125_E284(void*, void*);
void fn_125_E53C(s16*, const s16*);
void fn_125_E364(void*, const s16*, void*);
}

extern "C" void fn_125_E2D4(void* object, const WolfTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 4) {
        bool enabled = reinterpret_cast<WolfElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_125_E284(element, argument);
        }
    }

    WolfTraversalIndex next;
    fn_125_E53C(&next.value, &operation->value);
    fn_125_E364(composite + 4, &next.value, argument);
}
