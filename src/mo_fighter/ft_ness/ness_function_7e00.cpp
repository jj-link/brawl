#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void fn_101_7E78(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_7E00(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x11C, static_cast<short>(-1));
        if (object != 0) {
            fn_101_7E78(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
