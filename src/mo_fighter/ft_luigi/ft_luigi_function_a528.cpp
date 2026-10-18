#pragma force_active on
extern "C" void* fn_99_3C2C(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_99_A528(void* object, short deleting) {
    if (object) {
        if (object) {
            int destroyBase = 0;
            fn_99_3C2C(object, destroyBase);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
