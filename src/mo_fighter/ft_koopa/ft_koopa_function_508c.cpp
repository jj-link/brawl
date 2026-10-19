#pragma force_active on
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_102_3D4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_508C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_102_3D4C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
