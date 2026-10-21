#pragma force_active on
namespace {
struct SonicElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_123_E128(void*, void*);
void fn_123_ED34(short*, const short*);
int fn_123_E524(void*, const short*, void*);
}

extern "C" void fn_123_E494(void* object, const short* flags, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*flags & 4) {
        bool enabled = reinterpret_cast<SonicElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_123_E128(element, argument);
        }
    }
    short next;
    fn_123_ED34(&next, flags);
    fn_123_E524(composite + 4, &next, argument);
}
