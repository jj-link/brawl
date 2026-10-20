#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_125_6A68(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_69F0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2D0, -1);
        if (object != 0) {
            fn_125_6A68(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
