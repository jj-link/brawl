#pragma force_active on
typedef unsigned int u32;

extern char lbl_94_bss_2F4;
extern u32 lbl_94_bss_2F8;
extern unsigned char lbl_94_bss_2E0[0x14];

extern "C" {
void fn_27_300614(void* self);
void fn_27_300624(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_94_17EEC()
{
    if (lbl_94_bss_2F4 == 0) {
        fn_27_300614(&lbl_94_bss_2F8);
        __register_global_object(&lbl_94_bss_2F8, (void*)fn_27_300624, lbl_94_bss_2E0);
        lbl_94_bss_2F4 = 1;
    }
    return &lbl_94_bss_2F8;
}
}
