#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_4AD20(void* p, int flag);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
void __dl__FPv(void* p);
}

struct fn_27_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" fn_27_Obj* fn_27_19C6A4(fn_27_Obj* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_4AD20, 0x5C, 5);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
