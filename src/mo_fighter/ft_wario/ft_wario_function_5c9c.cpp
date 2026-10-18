#pragma force_active on
extern "C" void fn_110_3D08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_5C9C(void* object, short deleting) {
    if (object != 0) {
        fn_110_3D08(static_cast<unsigned char*>(object) + 0x88, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
