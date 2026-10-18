#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_115_161C4(void*, short);
void* fn_115_16168(void*, short);
void* fn_115_16080(void*, short);
void* fn_115_16020(void*, short);
void* fn_115_1AF0C(void*, short);
void* fn_115_1AD5C(void*, short);
void* fn_115_15CB0(void*, short);
void* fn_115_3CF8(void*, short);
void* fn_115_1AC44(void*, short);
void* fn_115_15B88(void*, short);
void* fn_115_15B1C(void*, short);
void* fn_115_15A7C(void*, short);
void* fn_115_15A20(void*, short);
void* fn_115_158A4(void*, short);
void* fn_115_157E0(void*, short);
void* fn_115_5E68(void*, short);
void* fn_115_5EC4(void*, short);
void* fn_115_5F30(void*, short);
void* fn_115_1ABCC(void*, short);
void* fn_115_15514(void*, short);
void* fn_115_1549C(void*, short);
void* fn_115_153E0(void*, short);
void* fn_115_3DD4(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_115_1AAA0(void*, short);
}

extern "C" void* fn_115_1AF84(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_115_161C4(static_cast<unsigned char*>(object) + 0x1858, -1);
        fn_115_16168(p + 0x1840, -1);
        fn_115_16080(p + 0x16A4, -1);
        fn_115_16020(p + 0x1644, -1);
        fn_115_1AF0C(p + 0x1590, -1);
        fn_115_1AD5C(p + 0x13D8, -1);
        fn_115_15CB0(p + 0x1334, -1);
        fn_115_3CF8(p + 0x1300, -1);
        fn_115_1AC44(p + 0x12E8, -1);
        fn_115_15B88(p + 0x1184, -1);
        fn_115_15B1C(p + 0x111C, -1);
        fn_115_15A7C(p + 0x1110, -1);
        fn_115_15A20(p + 0x10E8, -1);
        fn_115_158A4(p + 0xF18, -1);
        fn_115_157E0(p + 0xEB4, -1);
        fn_115_5E68(p + 0xE78, -1);
        fn_115_5EC4(p + 0xDD0, -1);
        fn_115_5F30(p + 0xD1C, -1);
        fn_115_1ABCC(p + 0xB10, -1);
        fn_115_15514(p + 0x930, -1);
        fn_115_1549C(p + 0x900, -1);
        fn_115_153E0(p + 0x8F0, -1);
        fn_115_3DD4(p + 0x8D8, -1);
        __dt__16soModuleAccesserFv(p + 0x7F8, -1);
        fn_115_1AAA0(p, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
