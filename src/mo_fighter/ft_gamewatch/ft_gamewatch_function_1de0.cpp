#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void fn_107_1C0C(void*, short);

extern "C" void* fn_107_1DE0(void* array, short release) {
    if (array != 0) {
        fn_107_1C0C(array, 0);
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
