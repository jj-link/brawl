#pragma force_active on
extern "C" void* fn_122_3BC4(void*, short);
extern "C" void* fn_122_3C20(void*, short);
extern "C" void* fn_122_3C7C(void*, short);
extern "C" void* fn_122_3D5C(void*, short);
extern "C" void* fn_122_21F88(void*, short);
extern "C" void* fn_122_3DE8(void*, short);
extern "C" void* fn_122_6E70(void*, short);
extern "C" void* fn_122_430C(void*, short);
extern "C" void* fn_122_4440(void*, short);
extern "C" void* fn_122_767C(void*, short);
extern "C" void* fn_122_4558(void*, short);
extern "C" void* fn_122_45C4(void*, short);
extern "C" void* fn_122_4624(void*, short);
extern "C" void* fn_122_4684(void*, short);
extern "C" void* fn_122_4850(void*, short);
extern "C" void* fn_122_49E4(void*, short);
extern "C" void* fn_122_5A1C(void*, short);
extern "C" void* fn_122_4B58(void*, short);
extern "C" void* fn_122_4BC4(void*, short);
extern "C" void* fn_122_4C7C(void*, short);
extern "C" void* fn_122_4CBC(void*, short);
extern "C" void __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_122_4D18(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_21E20(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_3BC4(storage + 0x6114, -1);
        fn_122_3C20(storage + 0x60D4, -1);
        fn_122_3C7C(storage + 0x60BC, -1);
        fn_122_3D5C(storage + 0x5F20, -1);
        fn_122_21F88(storage + 0x13C0, -1);
        fn_122_3DE8(storage + 0x1364, -1);
        fn_122_6E70(storage + 0x11A4, -1);
        fn_122_430C(storage + 0x1100, -1);
        fn_122_4440(storage + 0x10CC, -1);
        fn_122_767C(storage + 0x10A8, -1);
        fn_122_4558(storage + 0xF40, -1);
        fn_122_45C4(storage + 0xED8, -1);
        fn_122_4624(storage + 0xECC, -1);
        fn_122_4684(storage + 0xEA4, -1);
        fn_122_4850(storage + 0xE34, -1);
        fn_122_49E4(storage + 0xD1C, -1);
        fn_122_5A1C(storage + 0xB10, -1);
        fn_122_4B58(storage + 0x930, -1);
        fn_122_4BC4(storage + 0x900, -1);
        fn_122_4C7C(storage + 0x8F0, -1);
        fn_122_4CBC(storage + 0x8D8, -1);
        __dt__16soModuleAccesserFv(storage + 0x7F8, -1);
        fn_122_4D18(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
