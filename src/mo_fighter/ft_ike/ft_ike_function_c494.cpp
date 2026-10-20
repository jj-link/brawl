#pragma force_active on
typedef signed short s16;

namespace {
struct IkeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_119_C444(void*, void*);
s16* fn_119_C52C(s16* destination, const s16* source);
void fn_119_C524(void* destination, s16* source, void* argument);
}

extern "C" void fn_119_C494(void* object, const s16* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 4) {
        bool enabled = reinterpret_cast<IkeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_119_C444(element, argument);
        }
    }
    s16 local;
    fn_119_C52C(&local, operation);
    fn_119_C524(composite + 4, &local, argument);
}
