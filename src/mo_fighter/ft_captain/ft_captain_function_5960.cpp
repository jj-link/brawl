#pragma force_active on
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_100_59D8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_5960(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x88, -1);
        if (object != 0) {
            fn_100_59D8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
