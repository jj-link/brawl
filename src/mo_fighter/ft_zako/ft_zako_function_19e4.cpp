#pragma force_active on
extern "C" void fn_126_1980(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_19E4(void* array, short release) {
    if (array != 0) {
        fn_126_1980(array, (short)0);
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
