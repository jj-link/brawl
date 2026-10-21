#pragma force_active on
typedef signed short s16;
typedef signed int s32;

extern "C" {
void fn_104_DA78(void*, void*);
s16* fn_104_DC48(s16*, const s16*);
void fn_104_DB58(void*, const s16*, void*);
}

namespace {
struct ZeldaElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" void fn_104_DAC8(void* object, const s16* source, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*source & 8) {
        bool enabled = reinterpret_cast<ZeldaElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_104_DA78(element, argument);
        }
    }
    s16 local;
    fn_104_DC48(&local, source);
    fn_104_DB58(composite + 4, &local, argument);
}
