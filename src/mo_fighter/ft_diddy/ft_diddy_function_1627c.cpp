#pragma force_active on
extern "C" void* fn_115_16220(void* object, short flag);
extern "C" void* fn_115_161C4(void* object, short flag);
extern "C" void* fn_115_16168(void* object, short flag);
extern "C" void* fn_115_1610C(void* object, short flag);
extern "C" void* fn_115_16080(void* object, short flag);
extern "C" void* fn_115_16020(void* object, short flag);
extern "C" void* fn_115_15FA8(void* object, short flag);
extern "C" void* fn_115_15F0C(void* object, short flag);
extern "C" void* fn_115_15CB0(void* object, short flag);
extern "C" void* fn_115_3CF8(void* object, short flag);
extern "C" void* fn_115_15BF4(void* object, short flag);
extern "C" void* fn_115_15B88(void* object, short flag);
extern "C" void* fn_115_15B1C(void* object, short flag);
extern "C" void* fn_115_15A7C(void* object, short flag);
extern "C" void* fn_115_15A20(void* object, short flag);
extern "C" void* fn_115_159AC(void* object, short flag);
extern "C" void* fn_115_15928(void* object, short flag);
extern "C" void* fn_115_158A4(void* object, short flag);
extern "C" void* fn_115_157E0(void* object, short flag);
extern "C" void* fn_115_5E68(void* object, short flag);
extern "C" void* fn_115_5EC4(void* object, short flag);
extern "C" void* fn_115_5F30(void* object, short flag);
extern "C" void* fn_115_156B4(void* object, short flag);
extern "C" void* fn_115_15514(void* object, short flag);
extern "C" void* fn_115_1549C(void* object, short flag);
extern "C" void* fn_115_153E0(void* object, short flag);
extern "C" void* fn_115_3DD4(void* object, short flag);
extern "C" void* __dt__16soModuleAccesserFv(void* object, short flag);
extern "C" void* fn_115_15218(void* object, short flag);
void operator delete(void*);

extern "C" void* fn_115_1627C(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        fn_115_16220((unsigned char*)object + 0x1ee8, destroy);
        fn_115_161C4((unsigned char*)object + 0x1ea8, destroy);
        fn_115_16168((unsigned char*)object + 0x1e90, destroy);
        fn_115_1610C((unsigned char*)object + 0x1d38, destroy);
        fn_115_16080((unsigned char*)object + 0x1ba0, destroy);
        fn_115_16020((unsigned char*)object + 0x1b40, destroy);
        fn_115_15FA8((unsigned char*)object + 0x1930, destroy);
        fn_115_15F0C((unsigned char*)object + 0x1754, destroy);
        fn_115_15CB0((unsigned char*)object + 0x16b0, destroy);
        fn_115_3CF8((unsigned char*)object + 0x167c, destroy);
        fn_115_15BF4((unsigned char*)object + 0x1648, destroy);
        fn_115_15B88((unsigned char*)object + 0x14e4, destroy);
        fn_115_15B1C((unsigned char*)object + 0x147c, destroy);
        fn_115_15A7C((unsigned char*)object + 0x1470, destroy);
        fn_115_15A20((unsigned char*)object + 0x1448, destroy);
        fn_115_159AC((unsigned char*)object + 0x1294, destroy);
        fn_115_15928((unsigned char*)object + 0x10e8, destroy);
        fn_115_158A4((unsigned char*)object + 0xf24, destroy);
        fn_115_157E0((unsigned char*)object + 0xec0, destroy);
        fn_115_5E68((unsigned char*)object + 0xe84, destroy);
        fn_115_5EC4((unsigned char*)object + 0xddc, destroy);
        fn_115_5F30((unsigned char*)object + 0xd28, destroy);
        fn_115_156B4((unsigned char*)object + 0xb1c, destroy);
        fn_115_15514((unsigned char*)object + 0x93c, destroy);
        fn_115_1549C((unsigned char*)object + 0x90c, destroy);
        fn_115_153E0((unsigned char*)object + 0x8fc, destroy);
        fn_115_3DD4((unsigned char*)object + 0x8e4, destroy);
        __dt__16soModuleAccesserFv((unsigned char*)object + 0x804, destroy);
        fn_115_15218(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}