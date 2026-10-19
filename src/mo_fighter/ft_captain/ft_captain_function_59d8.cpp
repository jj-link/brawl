#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_100_5A48(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_59D8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x1C, static_cast<short>(-1));
        fn_100_5A48(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
