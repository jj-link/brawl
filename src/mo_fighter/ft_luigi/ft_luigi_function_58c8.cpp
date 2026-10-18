#pragma force_active on
extern "C" void* fn_99_4034(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_58C8(void* object, short deleting) {
    if (object) {
        if (object) {
            int destroyBase = 0;
            fn_99_4034(object, destroyBase);
        }
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
