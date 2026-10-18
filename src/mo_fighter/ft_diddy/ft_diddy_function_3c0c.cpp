#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_3C0C(void* array, short size) {
    if (array != 0 && size > 0) {
        __dl__FPv(array);
    }
    return array;
}
