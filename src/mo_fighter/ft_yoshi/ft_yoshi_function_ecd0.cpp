#pragma force_active on
#include <types.h>
namespace {
struct YoshiTraversalIndex {
    s16 value;
};
struct YoshiElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_95_EC80(void*, void*);
void fn_95_ED68(YoshiTraversalIndex*, const YoshiTraversalIndex*);
void fn_95_ED60(void*, YoshiTraversalIndex*, void*);
}

extern "C" void fn_95_ECD0(void* object, const YoshiTraversalIndex* operation, void* argument) {
    unsigned char* element = static_cast<unsigned char*>(object) + 0xC;
    if ((operation->value & 4) != 0) {
        bool enabled = reinterpret_cast<YoshiElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_95_EC80(element, argument);
        }
    }
    YoshiTraversalIndex next;
    fn_95_ED68(&next, operation);
    fn_95_ED60(static_cast<unsigned char*>(object) + 4, &next, argument);
}
