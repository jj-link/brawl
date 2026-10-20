#pragma force_active on
extern "C" void fn_125_D3D4(void* object, short deleting);
extern "C" void fn_125_D2A0(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_D434(void* object, short deleting) {
    if (object != 0) {
        fn_125_D3D4(static_cast<unsigned char*>(object) + 0x1C8, -1);
        if (object != 0) {
            fn_125_D2A0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
