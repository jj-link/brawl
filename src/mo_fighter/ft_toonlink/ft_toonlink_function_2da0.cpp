#pragma force_active on
extern "C" void* fn_121_2D40(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_2DA0(void* object, short deleting) {
    if (object != 0) {
        fn_121_2D40(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
