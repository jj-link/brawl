#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_24DFA4(void* self);
void* memset(void* p, int c, unsigned long n);
extern u8 lbl_27_data_4F588[];
extern const f32 lbl_27_rodata_4070;
}

extern "C" void* fn_27_24E71C(void* arg0);

void* fn_27_24E71C(void* arg0) {
    char* self = (char*)arg0;
    fn_27_24DFA4(self);
    *(void**)(self + 0x3C) = lbl_27_data_4F588;
    *(u32*)(self + 0xD0) = 0;
    *(u32*)(self + 0xD4) = 0;
    *(u32*)(self + 0xD8) = 0;
    *(u8*)(self + 0xDC) = 0;
    memset(self + 0xDE, 0xFFFF, 0x10);
    memset(self + 0xEE, 0xFFFF, 0x10);
    memset(self + 0xFE, 0xFFFF, 0x10);
    memset(self + 0x10E, 0xFFFF, 0x10);
    *(s32*)(self + 0x120) = 0x12E;
    *(u8*)(self + 0x124) = 0;
    *(f32*)(self + 0x128) = lbl_27_rodata_4070;
    return self;
}
