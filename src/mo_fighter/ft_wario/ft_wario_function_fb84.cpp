#pragma force_active on
extern "C" void fn_110_3D08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_FB84(void* object, short deleting) {
    if (object != 0) {
        fn_110_3D08(static_cast<unsigned char*>(object) + 0x4C, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
