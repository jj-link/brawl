#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_4F04(void* object, short deleting) {
    if (object) {
        if (object) {
            short destroyBase = -1;
            fn_27_1A15B8(object, destroyBase);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
