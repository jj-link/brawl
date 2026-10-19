#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_7CBDC(void* array, int release) {
    if (array != 0 && release > 0) {
        __dl__FPv(array);
    }
    return array;
}
