#pragma force_active on
extern "C" void* fn_99_3C2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_A064(void* object, short deleting) {
    if (object) {
        if (object) {
            int destroyBase = 0;
            fn_99_3C2C(object, destroyBase);
        }
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
