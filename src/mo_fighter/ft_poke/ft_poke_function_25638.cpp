#pragma force_active on
extern "C" void* fn_116_256A8(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_25638(void* object, short deleting) {
    if (object != 0) {
        fn_116_256A8(static_cast<unsigned char*>(object) + 0xCC, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
