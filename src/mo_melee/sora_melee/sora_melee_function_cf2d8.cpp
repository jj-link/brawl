#include <types.h>
#pragma force_active on

extern "C" void fn_27_25290();
extern "C" void __destroy_arr(void* ptr, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);

class fn_27_Obj {
public:
    u8 unk0[0xC];
    u8 arr[0x30 * 0x1A];
    ~fn_27_Obj() {
        __destroy_arr(arr, (void (*)(void*, int))fn_27_25290, 0x30, 0x1A);
    }
};

extern "C" fn_27_Obj* fn_27_CF2D8(fn_27_Obj* self, s32 flag) {
    if (self) {
        __destroy_arr(self->arr, (void (*)(void*, int))fn_27_25290, 0x30, 0x1A);
        if (flag > 0) {
            ::operator delete(self);
        }
    }
    return self;
}
