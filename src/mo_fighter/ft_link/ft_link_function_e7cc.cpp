#pragma force_active on
typedef signed short s16;

namespace {
struct LinkElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_93_E77C(void*, void*);
void fn_93_E94C(s16*, const s16*);
void fn_93_E85C(void*, s16*, void*);
}

extern "C" void fn_93_E7CC(void* object, const s16* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 8) {
        bool enabled = reinterpret_cast<LinkElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_93_E77C(element, argument);
        }
    }
    s16 next[4];
    fn_93_E94C(next, operation);
    fn_93_E85C(composite + 4, next, argument);
}
