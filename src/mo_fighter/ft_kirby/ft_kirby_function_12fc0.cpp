#pragma force_active on
typedef short s16;
typedef int s32;
typedef unsigned char u8;

struct KirbyElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_96_12F70(void* object, void* argument);
s16* fn_96_13310(s16* destination, const s16* source);
s32 fn_96_13050(void* object, s16* source, void* argument);
}

extern "C" void fn_96_12FC0(void* object, const s16* source, void* argument) {
    u8* composite = static_cast<u8*>(object);
    u8* element = composite + 0xC;
    if (source[0] & 2) {
        bool enabled = reinterpret_cast<KirbyElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_96_12F70(element, argument);
        }
    }
    s16 tmp[4];
    fn_96_13310(&tmp[0], source);
    fn_96_13050(composite + 4, &tmp[0], argument);
}
