#pragma force_active on
extern "C" {
extern void fn_105_1B04(void*, short);
extern void __dl__FPv(void*);
}

extern "C" void* fn_105_1CD8(void* array, short release) {
    if (array != 0) {
        fn_105_1B04(array, 0);
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
