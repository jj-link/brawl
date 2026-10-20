#pragma force_active on
extern "C" void* fn_27_D2904(void*, short);
extern "C" void* fn_102_4C98(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_4C20(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x154, -1);
        if (object != 0) {
            fn_102_4C98(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
