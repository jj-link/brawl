#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_9D6C(void* object, int shouldDelete) {
    if (object != 0) {
        fn_27_BED74(object, static_cast<short>(-1));
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
