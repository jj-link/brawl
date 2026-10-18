#pragma force_active on
extern "C" void* fn_116_3CA4(void*, short);
extern "C" void* fn_116_3D28(void*, short);
extern "C" void* fn_116_1E8E8(void*, short);
extern "C" void* fn_116_5744(void*, short);
extern "C" void* fn_116_615C(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_116_1E84C(void* object, short deleting) {
    if (object != 0) {
        fn_116_3CA4((unsigned char*)object + 0xDBC, -1);
        fn_116_3D28((unsigned char*)object + 0xDA8, -1);
        fn_116_1E8E8((unsigned char*)object + 0x930, -1);
        fn_116_5744((unsigned char*)object + 0xBC, -1);
        fn_116_615C((unsigned char*)object + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
