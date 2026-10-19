#pragma force_active on
extern "C" {
void* fn_101_18738(void*, short);
void* fn_101_5D14(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_186C8(void* object, short deleting) {
    if (object != 0) {
        fn_101_18738(static_cast<unsigned char*>(object) + 8, static_cast<short>(-1));
        fn_101_5D14(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
