#pragma force_active on
extern "C" void* fn_116_C378(void* object, short deleting);
extern "C" void* fn_116_C240(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_C3D8(void* object, short deleting) {
    if (object != 0) {
        fn_116_C378(static_cast<char*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_116_C240(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
