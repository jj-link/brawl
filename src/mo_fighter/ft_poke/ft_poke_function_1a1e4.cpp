#include <types.h>
#pragma force_active on

namespace {
struct PokeTraversalIndex {
    short value;
};
struct PokeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_116_1A1AC(void*, void*);
PokeTraversalIndex* fn_116_1A34C(PokeTraversalIndex* destination, const PokeTraversalIndex* source);
s32 fn_116_1A274(void*, PokeTraversalIndex*, void*);
}

extern "C" void fn_116_1A1E4(void* object, const PokeTraversalIndex* operation, void* argument) {
    unsigned char* element = static_cast<unsigned char*>(object) + 0xC;
    if (operation->value & 8) {
        bool enabled = reinterpret_cast<PokeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_116_1A1AC(element, argument);
        }
    }
    PokeTraversalIndex next;
    fn_116_1A34C(&next, operation);
    fn_116_1A274(static_cast<char*>(object) + 4, &next, argument);
}
