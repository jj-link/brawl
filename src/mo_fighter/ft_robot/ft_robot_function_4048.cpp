#pragma force_active on
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_120_40C0(void* object, short deleteFlag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_4048(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x48c, -1);
        if (object != 0) {
            fn_120_40C0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
