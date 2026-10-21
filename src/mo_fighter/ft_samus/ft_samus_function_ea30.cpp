#include <types.h>
#pragma force_active on

extern "C" void fn_94_E9E0(void*, void*);
extern "C" s16* fn_94_EAC8(s16*, const s16*);
extern "C" s32 fn_94_EAC0(void*, const s16*, void*);

namespace {
struct Index {
    s16 value;
};

struct Flags {
    unsigned char enabled : 1;
    unsigned char rest : 7;
};
}

extern "C" void fn_94_EA30(void* object, const Index* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 12;

    if (operation->value & 4) {
        bool enabled = reinterpret_cast<Flags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_94_E9E0(element, argument);
        }
    }

    s16 next;
    fn_94_EAC8(&next, &operation->value);
    fn_94_EAC0(composite + 4, &next, argument);
}
