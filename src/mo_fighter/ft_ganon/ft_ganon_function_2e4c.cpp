#pragma force_active on
extern "C" {
void fn_27_ACC5C(void*, short);
void __dl__FPv(void*);
void* fn_109_2E4C(void* array, short release);
}

void* fn_109_2E4C(void* array, short release) {
    if (array != 0) {
        fn_27_ACC5C(array, static_cast<short>(-1));
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
