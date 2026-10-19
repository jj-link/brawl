#pragma force_active on
extern "C" {
extern void fn_122_1AD0(void*, short);
extern void __dl__FPv(void*);

void* fn_122_1BEC(void* array, short release) {
    if (array != 0) {
        fn_122_1AD0(array, 0);
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
}
