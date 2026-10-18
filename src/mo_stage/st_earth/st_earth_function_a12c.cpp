#pragma force_active on
extern "C" {

extern char lbl_66_bss_90;

struct Obj66 {
    unsigned char _00[0x24];
    float f_24;
    float f_28;
    float f_2c;
    unsigned char _30[8];
    unsigned int u_38;
    unsigned char _3c[0x2C];
};

extern Obj66 lbl_66_bss_98;
extern void* lbl_66_bss_60[3];
extern const float lbl_66_rodata_1B8;
void fn_66_7E90(void);
void __register_global_object(void*, void*, void*);

void* fn_66_A12C(void) {
    if (lbl_66_bss_90 == 0) {
        lbl_66_bss_98.f_24 = lbl_66_rodata_1B8;
        lbl_66_bss_98.f_28 = lbl_66_rodata_1B8;
        lbl_66_bss_98.f_2c = lbl_66_rodata_1B8;
        lbl_66_bss_98.u_38 &= ~0x1F;
        __register_global_object(&lbl_66_bss_98, (void*)fn_66_7E90, &lbl_66_bss_60);
        lbl_66_bss_90 = 1;
    }
    return &lbl_66_bss_98;
}

}
