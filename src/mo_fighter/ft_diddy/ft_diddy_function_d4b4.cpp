#include <types.h>

#pragma force_active on

namespace {
struct DiddyTraversalIndex {
    short value;
};
struct DiddyElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_115_D464(void*, void*);
void fn_115_D71C(short* destination, const short* source);
int fn_115_D544(void*, short*, void*);

extern "C" void fn_115_D4B4(void* object, const DiddyTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<DiddyElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_115_D464(element, argument);
        }
    }
    short next;
    fn_115_D71C(&next, &operation->value);
    fn_115_D544(composite + 4, &next, argument);
}
}
