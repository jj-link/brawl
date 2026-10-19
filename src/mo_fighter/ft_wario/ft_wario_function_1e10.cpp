#pragma force_active on
extern "C" {
void fn_110_1BE0(void* array, short release);
void __dl__FPv(void* ptr);

void* fn_110_1E10(void* array, short release) {
    if (array != 0) {
        fn_110_1BE0(array, 0);
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
}
