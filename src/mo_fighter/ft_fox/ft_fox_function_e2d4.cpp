#include <types.h>
#pragma force_active on

namespace {
struct FoxTraversalIndex {
    short value;
};
struct FoxElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_97_E284(void*, void*);
void fn_97_E624(s16* destination, const s16* source);
void fn_97_E364(void*, s16*, void*);
}

extern "C" void fn_97_E2D4(void* object, const FoxTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 2) {
        bool enabled = reinterpret_cast<FoxElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_97_E284(element, argument);
        }
    }
    s16 buffer[4];
    fn_97_E624(buffer, &operation->value);
    fn_97_E364(composite + 4, buffer, argument);
}
