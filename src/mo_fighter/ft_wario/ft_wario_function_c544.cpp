#pragma force_active on
typedef signed short s16;
typedef unsigned char u8;

namespace {
struct FlagByte {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_110_C4F4(void* object, void* argument);
s16* fn_110_C6C4(s16* destination, const s16* source);
int fn_110_C5D4(void* object, s16* source, void* argument);
}

extern "C" void fn_110_C544(void* object, const s16* operation, void* argument) {
    u8* p = static_cast<u8*>(object) + 0xC;
    if (operation[0] & 0x8) {
        bool enabled = reinterpret_cast<FlagByte*>(p + 5)->enabled;
        if (enabled == true && p[6] == 0) {
            fn_110_C4F4(p, argument);
        }
    }
    s16 tmp;
    fn_110_C6C4(&tmp, operation);
    fn_110_C5D4(static_cast<u8*>(object) + 4, &tmp, argument);
}
