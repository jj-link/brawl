#pragma force_active on
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_109_50C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_5048(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A18A0(static_cast<unsigned char*>(object) + 0x354, -1);
        if (object != 0) {
            fn_109_50C0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
