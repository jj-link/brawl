#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_F59C(void* array, short count) {
    if (array != 0 && count > 0) {
        __dl__FPv(array);
    }
    return array;
}
