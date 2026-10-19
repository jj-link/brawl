#pragma force_active on
extern "C" void fn_27_B21D0(void*, short);
extern "C" void fn_27_CB4A0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_50FC(void* object, short deleting) {
    if (object != 0) {
        fn_27_B21D0(static_cast<unsigned char*>(object) + 0x50, -1);
        if (object != 0) {
            fn_27_CB4A0(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
