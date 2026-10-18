#pragma force_active on
extern "C" void* fn_99_3C2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_A1FC(void* object, short deleting) {
    if (object) {
        if (object) {
            fn_99_3C2C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
