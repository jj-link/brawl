#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_93_7140(void*, short);
void* fn_93_63F0(void*, short);
void* fn_93_644C(void*, short);
void* fn_93_64A8(void*, short);
void* fn_93_719C(void*, short);
void* fn_93_172A8(void*, short);
void* fn_93_6564(void*, short);
void* fn_93_13170(void*, short);
void* fn_93_1757C(void*, short);
void* fn_93_65C4(void*, short);
void* fn_93_2240(void*, short);
void* fn_93_664C(void*, short);
void* fn_93_66A8(void*, short);
void* fn_93_7284(void*, short);
void* fn_93_6714(void*, short);
void* fn_93_72E4(void*, short);
void* fn_93_12D4C(void*, short);
void* fn_93_6774(void*, short);
void* fn_93_2024(void*, short);
void* fn_93_1FB0(void*, short);
void* fn_93_176D4(void*, short);
void* fn_93_6888(void*, short);
void* fn_93_68F4(void*, short);
void* fn_93_696C(void*, short);
void* fn_93_1F54(void*, short);
void* fn_93_7340(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
}

extern "C" void* fn_93_17110(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short d = -1;
        fn_93_7140(p + 0x30CC, d);
        fn_93_63F0(p + 0x30B4, d);
        fn_93_644C(p + 0x2F5C, d);
        fn_93_64A8(p + 0x2F0C, d);
        fn_93_719C(p + 0x2D78, d);
        fn_93_172A8(p + 0x162C, d);
        fn_93_6564(p + 0x15D0, d);
        fn_93_13170(p + 0x151C, d);
        fn_93_1757C(p + 0x1334, d);
        fn_93_65C4(p + 0x1290, d);
        fn_93_2240(p + 0x125C, d);
        fn_93_664C(p + 0x1244, d);
        fn_93_66A8(p + 0x10E0, d);
        fn_93_7284(p + 0x1078, d);
        fn_93_6714(p + 0x106C, d);
        fn_93_72E4(p + 0x1044, d);
        fn_93_12D4C(p + 0xE74, d);
        fn_93_6774(p + 0xE10, d);
        fn_93_2024(p + 0xDD4, d);
        fn_93_1FB0(p + 0xD1C, d);
        fn_93_176D4(p + 0xB10, d);
        fn_93_6888(p + 0x930, d);
        fn_93_68F4(p + 0x900, d);
        fn_93_696C(p + 0x8F0, d);
        fn_93_1F54(p + 0x8D8, d);
        __dt__16soModuleAccesserFv(p + 0x7F8, d);
        fn_93_7340(object, d);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
