#pragma force_active on
typedef unsigned char u8;

extern "C" u8 lbl_27_bss_110[0x10];
extern "C" void* fn_27_6F5F8(void* a, void* b);

extern "C" void* fn_27_6A640(void* self)
{
    return fn_27_6F5F8(lbl_27_bss_110, self);
}
