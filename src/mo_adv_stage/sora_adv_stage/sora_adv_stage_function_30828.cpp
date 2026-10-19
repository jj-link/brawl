#pragma force_active on
extern "C" {
    void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
    void __dl__FPv(void*);
    void __dt__19soCollisionHitGroupFv(void*, int);

    void* fn_40_30828(void* arr, int release) {
        if (arr != 0) {
            __destroy_arr((char*)arr + 0xc, __dt__19soCollisionHitGroupFv, 0x38, 0xd);
            if (release > 0) {
                __dl__FPv(arr);
            }
        }
        return arr;
    }
}
