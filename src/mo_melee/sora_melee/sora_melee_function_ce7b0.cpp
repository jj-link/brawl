#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_25290(void* ptr, int count);

class fn_27_Obj {
public:
    u8 m_head[0xC];
    u8 m_arr[0x30 * 0x10];
    fn_27_Obj() { }
    ~fn_27_Obj() {
        __destroy_arr(m_arr, (void (*)(void*, int))fn_27_25290, 0x30, 0x10);
    }
};

extern "C" fn_27_Obj* fn_27_CE7B0(fn_27_Obj* self, int flag) {
    if (self) {
        __destroy_arr(self->m_arr, (void (*)(void*, int))fn_27_25290, 0x30, 0x10);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
