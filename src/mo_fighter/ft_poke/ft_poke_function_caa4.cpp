#pragma force_active on
extern "C" {
void fn_116_CA2C(void*, short);
void __dl__FPv(void*);

void* fn_116_CAA4(void* array, int release) {
    if (array != 0) {
        fn_116_CA2C(array, (short)0);
        if ((short)release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
}
