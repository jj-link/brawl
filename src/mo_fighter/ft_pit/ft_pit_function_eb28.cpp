#pragma force_active on
extern "C" void* fn_112_48A8(void*, short);
extern "C" void* fn_112_492C(void*, short);
extern "C" void* fn_112_EBC4(void*, short);
extern "C" void* fn_112_498C(void*, short);
extern "C" void* fn_112_4A14(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_EB28(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_48A8(storage + 0x120, -1);
        fn_112_492C(storage + 0x10c, -1);
        fn_112_EBC4(storage + 0xec, -1);
        fn_112_498C(storage + 0x48, -1);
        fn_112_4A14(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
