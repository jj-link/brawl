#pragma force_active on
extern "C" void* fn_92_6A78(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_6A1C(void* object, short deleting) {
    if (object != 0) {
        fn_92_6A78(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
