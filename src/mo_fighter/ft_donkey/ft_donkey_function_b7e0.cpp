#pragma force_active on
extern "C" void* fn_92_39F8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_B7E0(void* object, short deleting) {
    if (object != 0) {
        fn_92_39F8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
