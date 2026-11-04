#pragma force_active on
extern "C" void* fn_122_3C20(void*, short);
extern "C" void* fn_122_3C7C(void*, short);
extern "C" void* fn_122_3D5C(void*, short);
extern "C" void* fn_122_3DE8(void*, short);
extern "C" void* fn_122_6E70(void*, short);
extern "C" void* fn_122_4440(void*, short);
extern "C" void* fn_122_4558(void*, short);
extern "C" void* fn_122_45C4(void*, short);
extern "C" void* fn_122_4624(void*, short);
extern "C" void* fn_122_4684(void*, short);
extern "C" void* fn_122_4850(void*, short);
extern "C" void* fn_122_5B54(void*, short);
extern "C" void* fn_122_4B58(void*, short);
extern "C" void* fn_122_4BC4(void*, short);
extern "C" void* fn_122_4C7C(void*, short);
extern "C" void* fn_122_4CBC(void*, short);
extern "C" void __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_122_4D18(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_1A304(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_3C20(storage + 0x124C, -1);
        fn_122_3C7C(storage + 0x1234, -1);
        fn_122_3D5C(storage + 0x1098, -1);
        fn_122_3DE8(storage + 0x1038, -1);
        fn_122_6E70(storage + 0xE78, -1);
        fn_122_4440(storage + 0xE40, -1);
        fn_122_4558(storage + 0xCD8, -1);
        fn_122_45C4(storage + 0xC70, -1);
        fn_122_4624(storage + 0xC64, -1);
        fn_122_4684(storage + 0xC3C, -1);
        fn_122_4850(storage + 0xBCC, -1);
        fn_122_5B54(storage + 0xB14, -1);
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
