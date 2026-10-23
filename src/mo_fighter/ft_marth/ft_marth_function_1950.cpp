#pragma force_active on

extern "C" void* fn_106_19E8(void*, short);
extern "C" void* fn_106_1DC8(void*, short);
extern "C" void* fn_106_1E64(void*, short);
extern "C" void* fn_106_1F9C(void*, short);
extern "C" void* fn_27_125E20(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_1950(void* object, short deleting) {
    if (object != 0) {
        fn_106_19E8((char*)object + 0x84AC, -1);
        fn_106_1DC8((char*)object + 0x7FF4, -1);
        fn_106_1E64((char*)object + 0x7FB8, -1);
        fn_106_1F9C((char*)object + 0x194, -1);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
