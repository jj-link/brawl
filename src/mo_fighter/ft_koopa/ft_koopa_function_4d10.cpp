#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_102_4D88(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_4D10(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x11C, -1);
        if (object != 0) {
            fn_102_4D88(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
