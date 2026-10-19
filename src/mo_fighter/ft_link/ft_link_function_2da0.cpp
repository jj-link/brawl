#pragma force_active on
extern "C" void* fn_93_2D40(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_2DA0(void* object, short deleting) {
    if (object) {
        fn_93_2D40(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
