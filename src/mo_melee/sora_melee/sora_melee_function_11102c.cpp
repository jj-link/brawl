#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_1D48C0(void* a, u32 b, u32 c, u32 d);
void fn_27_1111CC(void* a);
u8 lbl_27_data_270B8[];
u8 lbl_27_data_27130[];

void* fn_27_11102C(u8* data, u32 arg2, u32 arg3, u32 arg4) {
    *(void**)(data + 0x00) = data + 0x10;
    *(u32*)(data + 0x04) = arg2;
    *(u16*)(data + 0x08) = (u16)arg4;
    *(u8*)(data + 0xA) = 1;
    *(void**)(data + 0xC) = lbl_27_data_270B8;
    
    fn_27_1D48C0(data + 0x848, arg2, arg3, arg4);
    
    *(void**)(data + 0xD54) = data + 0x10;
    *(u32*)(data + 0xD58) = arg3;
    *(u16*)(data + 0xD5C) = (u16)arg4;
    *(u8*)(data + 0xD5E) = 1;
    *(void**)(data + 0xD60) = lbl_27_data_27130;
    
    fn_27_1111CC(data);
    
    return data;
}
}
