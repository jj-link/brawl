#pragma force_active on
extern "C" void* fn_99_A970(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_A9E8(void* object, short deleting) {
    if (object) {
        int destroyBase = 0;
        fn_99_A970(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
