#pragma force_active on
extern "C" void* fn_101_FCEC(void*, short);
extern "C" void* fn_101_FBB8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_101_FD4C(void* object, short deleting) {
    if (object != 0) {
        fn_101_FCEC(static_cast<unsigned char*>(object) + 0x204, static_cast<short>(-1));
        if (object != 0) {
            fn_101_FBB8(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
