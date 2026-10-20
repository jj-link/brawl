#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern u8 lbl_27_bss_1858;
extern u32 lbl_27_bss_185C;
extern unsigned char lbl_27_bss_1004[12];

void fn_27_70454(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" u32* fn_27_85E00() {
    if ((signed char)lbl_27_bss_1858 == 0) {
        lbl_27_bss_185C = 0;
        __register_global_object(
            &lbl_27_bss_185C,
            (void*)fn_27_70454,
            lbl_27_bss_1004
        );
        lbl_27_bss_1858 = 1;
    }
    return &lbl_27_bss_185C;
}
