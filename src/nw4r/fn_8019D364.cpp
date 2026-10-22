#pragma force_active on
#include <stddef.h>

extern "C" void *fn_801970A0(void **arg0, unsigned int arg1);
extern "C" void fn_80195F08(void **arg0, void *arg1, float arg2);

extern "C" void *fn_8019D364(void *arg0, void *arg1, unsigned int arg2) {
    void *result = fn_801970A0((void **)((char *)arg0 + 0x20), arg2);
    if (result == NULL) {
        *(int *)arg1 = 0;
        *(int *)((char *)arg1 + 4) = -1;
        return arg1;
    }
    int field28 = *(int *)((char *)arg0 + 0x28);
    if (field28 != 0) {
        return (void *)(field28 + *(int *)((char *)result + 0xC) * 8);
    }
    float fieldC = *(float *)((char *)arg0 + 0xC);
    fn_80195F08(&result, arg1, fieldC);
    return arg1;
}
