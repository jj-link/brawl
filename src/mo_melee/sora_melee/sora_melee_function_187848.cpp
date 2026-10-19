#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_27_187848(void* array, int release) {
    if (array != 0) {
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
}
