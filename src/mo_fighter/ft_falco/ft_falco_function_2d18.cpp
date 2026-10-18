#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_2D18(void* object, short count) {
    if (object != 0) {
        fn_27_BED74(object, static_cast<short>(-1));
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
