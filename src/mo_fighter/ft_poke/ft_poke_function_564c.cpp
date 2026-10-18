#pragma force_active on
extern "C" void* fn_116_3CA4(void*, short);
extern "C" void* fn_116_3D28(void*, short);
extern "C" void* fn_116_56E8(void*, short);
extern "C" void* fn_116_5744(void*, short);
extern "C" void* fn_116_615C(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_564C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_3CA4(storage + 0xDB4, -1);
        fn_116_3D28(storage + 0xDA0, -1);
        fn_116_56E8(storage + 0x930, -1);
        fn_116_5744(storage + 0xBC, -1);
        fn_116_615C(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
