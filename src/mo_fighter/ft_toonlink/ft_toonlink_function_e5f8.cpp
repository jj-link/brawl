#include <types.h>
#pragma force_active on

extern "C" void fn_121_E5A8(void*, void*);
extern "C" void fn_121_E948(s16*, const s16*);
extern "C" s32 fn_121_E688(void*, const s16*, void*);

struct ToonLinkIndex {
    s16 value;
};

struct ToonLinkElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" void fn_121_E5F8(void* object, const ToonLinkIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 2) {
        bool enabled = reinterpret_cast<ToonLinkElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_121_E5A8(element, argument);
        }
    }

    ToonLinkIndex next;
    fn_121_E948(&next.value, &operation->value);
    fn_121_E688(composite + 4, &next.value, argument);
}
