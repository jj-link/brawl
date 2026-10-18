#pragma force_active on
typedef signed short s16;

extern "C" void* fn_27_14B698(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_64B4(void* object, s16 deleteFlag) {
    if (object != 0) {
        fn_27_14B698(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
