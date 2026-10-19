#pragma force_active on
typedef unsigned int u32;

extern char lbl_96_bss_1038;
extern u32 lbl_96_bss_103C;
extern unsigned char lbl_96_bss_EE0[];

extern "C" {
void fn_27_300614(void* self);
void fn_27_300624(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_96_2028C(void)
{
    if (lbl_96_bss_1038 == 0) {
        fn_27_300614(&lbl_96_bss_103C);
        __register_global_object(&lbl_96_bss_103C, (void*)fn_27_300624, lbl_96_bss_EE0);
        lbl_96_bss_1038 = 1;
    }
    return &lbl_96_bss_103C;
}
}
