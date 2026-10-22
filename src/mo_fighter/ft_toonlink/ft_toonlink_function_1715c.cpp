#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_121_7010(void*, short);
void* fn_121_63F0(void*, short);
void* fn_121_644C(void*, short);
void* fn_121_64A8(void*, short);
void* fn_121_706C(void*, short);
void* fn_121_172F4(void*, short);
void* fn_121_6564(void*, short);
void* fn_121_131BC(void*, short);
void* fn_121_175C8(void*, short);
void* fn_121_65C4(void*, short);
void* fn_121_2240(void*, short);
void* fn_121_664C(void*, short);
void* fn_121_66A8(void*, short);
void* fn_121_7154(void*, short);
void* fn_121_6714(void*, short);
void* fn_121_71B4(void*, short);
void* fn_121_12D98(void*, short);
void* fn_121_6774(void*, short);
void* fn_121_2024(void*, short);
void* fn_121_1FB0(void*, short);
void* fn_121_17720(void*, short);
void* fn_121_6888(void*, short);
void* fn_121_68F4(void*, short);
void* fn_121_696C(void*, short);
void* fn_121_1F54(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_121_7210(void*, short);
}

extern "C" void* fn_121_1715C(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short d = -1;
        fn_121_7010(p + 0x30CC, d);
        fn_121_63F0(p + 0x30B4, d);
        fn_121_644C(p + 0x2F5C, d);
        fn_121_64A8(p + 0x2F0C, d);
        fn_121_706C(p + 0x2D78, d);
        fn_121_172F4(p + 0x162C, d);
        fn_121_6564(p + 0x15D0, d);
        fn_121_131BC(p + 0x151C, d);
        fn_121_175C8(p + 0x1334, d);
        fn_121_65C4(p + 0x1290, d);
        fn_121_2240(p + 0x125C, d);
        fn_121_664C(p + 0x1244, d);
        fn_121_66A8(p + 0x10E0, d);
        fn_121_7154(p + 0x1078, d);
        fn_121_6714(p + 0x106C, d);
        fn_121_71B4(p + 0x1044, d);
        fn_121_12D98(p + 0xE74, d);
        fn_121_6774(p + 0xE10, d);
        fn_121_2024(p + 0xDD4, d);
        fn_121_1FB0(p + 0xD1C, d);
        fn_121_17720(p + 0xB10, d);
        fn_121_6888(p + 0x930, d);
        fn_121_68F4(p + 0x900, d);
        fn_121_696C(p + 0x8F0, d);
        fn_121_1F54(p + 0x8D8, d);
        __dt__16soModuleAccesserFv(p + 0x7F8, d);
        fn_121_7210(object, d);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
