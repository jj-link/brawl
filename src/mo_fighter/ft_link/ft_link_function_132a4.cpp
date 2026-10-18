#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_93_13248(void*, short);
void* fn_93_7140(void*, short);
void* fn_93_63F0(void*, short);
void* fn_93_644C(void*, short);
void* fn_93_719C(void*, short);
void* fn_93_131E8(void*, short);
void* fn_93_13170(void*, short);
void* fn_93_12FC0(void*, short);
void* fn_93_65C4(void*, short);
void* fn_93_2240(void*, short);
void* fn_93_66A8(void*, short);
void* fn_93_7284(void*, short);
void* fn_93_6714(void*, short);
void* fn_93_72E4(void*, short);
void* fn_93_12D4C(void*, short);
void* fn_93_6774(void*, short);
void* fn_93_317C(void*, short);
void* fn_93_12BE4(void*, short);
void* fn_93_12B6C(void*, short);
void* fn_93_6888(void*, short);
void* fn_93_68F4(void*, short);
void* fn_93_696C(void*, short);
void* fn_93_1F54(void*, short);
void* fn_93_7340(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
}

extern "C" void* fn_93_132A4(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_93_13248(p + 0x19D0, -1);
        fn_93_7140(p + 0x1990, -1);
        fn_93_63F0(p + 0x1978, -1);
        fn_93_644C(p + 0x1820, -1);
        fn_93_719C(p + 0x1688, -1);
        fn_93_131E8(p + 0x163C, -1);
        fn_93_13170(p + 0x1588, -1);
        fn_93_12FC0(p + 0x13BC, -1);
        fn_93_65C4(p + 0x1318, -1);
        fn_93_2240(p + 0x12E4, -1);
        fn_93_66A8(p + 0x117C, -1);
        fn_93_7284(p + 0x1114, -1);
        fn_93_6714(p + 0x1108, -1);
        fn_93_72E4(p + 0x10E0, -1);
        fn_93_12D4C(p + 0xF10, -1);
        fn_93_6774(p + 0xEAC, -1);
        fn_93_317C(p + 0xE00, -1);
        fn_93_12BE4(p + 0xD1C, -1);
        fn_93_12B6C(p + 0xB10, -1);
        fn_93_6888(p + 0x930, -1);
        fn_93_68F4(p + 0x900, -1);
        fn_93_696C(p + 0x8F0, -1);
        fn_93_1F54(p + 0x8D8, -1);
        __dt__16soModuleAccesserFv(p + 0x7F8, -1);
        fn_93_7340(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
