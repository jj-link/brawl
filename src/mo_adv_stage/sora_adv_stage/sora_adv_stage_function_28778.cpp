#pragma force_active on
extern "C" {
extern const float lbl_40_rodata_420;
extern signed char lbl_40_bss_1328;
extern unsigned char lbl_40_bss_1330[];
extern unsigned char lbl_40_bss_11B8[];
void fn_40_27CEC();
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_40_28778()
{
    if (!lbl_40_bss_1328) {
        float f = lbl_40_rodata_420;
        *(float*)(lbl_40_bss_1330 + 0x24) = f;
        *(float*)(lbl_40_bss_1330 + 0x28) = f;
        *(float*)(lbl_40_bss_1330 + 0x2c) = f;
        *(unsigned int*)(lbl_40_bss_1330 + 0x38) = *(unsigned int*)(lbl_40_bss_1330 + 0x38) & ~0x1f;
        __register_global_object(lbl_40_bss_1330, (void*)fn_40_27CEC, lbl_40_bss_11B8);
        lbl_40_bss_1328 = 1;
    }
    return lbl_40_bss_1330;
}
}
