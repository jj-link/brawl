#pragma force_active on
extern "C" void* fn_108_6348(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_62EC(void* object, short deleting) {
    if (object != 0) {
        fn_108_6348(object, 0);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
