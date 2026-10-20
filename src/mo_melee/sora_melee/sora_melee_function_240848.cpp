#pragma force_active on
extern "C" {
extern void fn_27_23AB44(void* array, int release);
extern void __dl__FPv(void* ptr);

void* fn_27_240848(void* array, int release) {
    if (array != 0) {
        fn_27_23AB44(array, 0);
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
}
