#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_121_13294(void*, short);
void* fn_121_7010(void*, short);
void* fn_121_63F0(void*, short);
void* fn_121_644C(void*, short);
void* fn_121_706C(void*, short);
void* fn_121_13234(void*, short);
void* fn_121_131BC(void*, short);
void* fn_121_1300C(void*, short);
void* fn_121_65C4(void*, short);
void* fn_121_2240(void*, short);
void* fn_121_66A8(void*, short);
void* fn_121_7154(void*, short);
void* fn_121_6714(void*, short);
void* fn_121_71B4(void*, short);
void* fn_121_12D98(void*, short);
void* fn_121_6774(void*, short);
void* fn_121_317C(void*, short);
void* fn_121_12C30(void*, short);
void* fn_121_12BB8(void*, short);
void* fn_121_6888(void*, short);
void* fn_121_68F4(void*, short);
void* fn_121_696C(void*, short);
void* fn_121_1F54(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_121_7210(void*, short);
}

extern "C" void* fn_121_132F0(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_121_13294(p + 0x19D0, -1);
        fn_121_7010(p + 0x1990, -1);
        fn_121_63F0(p + 0x1978, -1);
        fn_121_644C(p + 0x1820, -1);
        fn_121_706C(p + 0x1688, -1);
        fn_121_13234(p + 0x163C, -1);
        fn_121_131BC(p + 0x1588, -1);
        fn_121_1300C(p + 0x13BC, -1);
        fn_121_65C4(p + 0x1318, -1);
        fn_121_2240(p + 0x12E4, -1);
        fn_121_66A8(p + 0x117C, -1);
        fn_121_7154(p + 0x1114, -1);
        fn_121_6714(p + 0x1108, -1);
        fn_121_71B4(p + 0x10E0, -1);
        fn_121_12D98(p + 0xF10, -1);
        fn_121_6774(p + 0xEAC, -1);
        fn_121_317C(p + 0xE00, -1);
        fn_121_12C30(p + 0xD1C, -1);
        fn_121_12BB8(p + 0xB10, -1);
        fn_121_6888(p + 0x930, -1);
        fn_121_68F4(p + 0x900, -1);
        fn_121_696C(p + 0x8F0, -1);
        fn_121_1F54(p + 0x8D8, -1);
        __dt__16soModuleAccesserFv(p + 0x7F8, -1);
        fn_121_7210(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
