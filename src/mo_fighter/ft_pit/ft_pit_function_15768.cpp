#pragma force_active on
extern "C" void* fn_112_48A8(void*, short);
extern "C" void* fn_112_492C(void*, short);
extern "C" void* fn_112_15804(void*, short);
extern "C" void* fn_112_498C(void*, short);
extern "C" void* fn_112_15860(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_15768(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_48A8(storage + 0x118, -1);
        fn_112_492C(storage + 0x104, -1);
        fn_112_15804(storage + 0xf0, -1);
        fn_112_498C(storage + 0x4c, -1);
        fn_112_15860(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
