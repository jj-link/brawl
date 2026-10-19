#include <types.h>
#pragma force_active on

struct fn27Pair {
    u32 a;
    u32 b;
};

struct fn27Obj {
    u32* base;
    u8 pad[6];
    u8 flag;
};

extern "C" {
void fn_27_112F84(void* self, fn27Pair* arg);

void fn_27_112F3C(fn27Obj* obj, fn27Pair* src) {
    if (obj->flag == 1) {
        fn27Pair tmp = *src;
        fn_27_112F84((void*)((u8*)obj->base + 0x838), &tmp);
    }
}
}
