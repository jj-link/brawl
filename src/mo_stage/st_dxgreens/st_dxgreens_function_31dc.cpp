#pragma force_active on
extern "C" {
    extern void __dl__FPv(void*);

    void* fn_79_31DC(void* array, int release) {
        if (array != 0 && release > 0) {
            __dl__FPv(array);
        }
        return array;
    }
}
