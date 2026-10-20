#pragma force_active on
extern "C" void* fn_123_BBCC(void* object, short deleting);
extern "C" void* fn_123_BA94(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_BC2C(void* object, short deleting) {
    if (object != 0) {
        fn_123_BBCC(static_cast<unsigned char*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_123_BA94(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
