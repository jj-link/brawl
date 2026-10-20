#pragma force_active on
typedef signed short s16;

extern "C" {
void fn_96_13228(void* object, void* argument);
s16* fn_96_13310(s16* destination, const s16* source);
void fn_96_13308(void* object, s16* values, void* argument);
}

namespace {
struct KirbyElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" void fn_96_13278(unsigned char* object, s16* source, void* argument) {
    s16 local[4];
    unsigned char* element = object + 0xC;
    if (source[0] & 4) {
        bool enabled = reinterpret_cast<KirbyElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_96_13228(element, argument);
        }
    }
    fn_96_13310(local, source);
    fn_96_13308(object + 4, local, argument);
}
