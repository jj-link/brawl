#pragma force_active on
extern "C" {
void* fn_101_F370(void*, short);
void* fn_101_F250(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_F3D0(void* object, short deleting) {
    if (object != 0) {
        fn_101_F370(static_cast<unsigned char*>(object) + 0x60, static_cast<short>(-1));
        fn_101_F250(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
