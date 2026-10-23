#pragma force_active on
extern "C" void fn_106_35E8(void*, short);
extern "C" void fn_106_3688(void*, short);
extern "C" void* fn_27_19E99C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_3570(void* object, short deleteFlag) {
    if (object != 0) {
        fn_106_35E8((char*)object + 0x85C, -1);
        fn_106_3688((char*)object + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
