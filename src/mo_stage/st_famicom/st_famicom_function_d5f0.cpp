#pragma force_active on
extern "C" {

typedef struct FamicomObj {
    char pad0[0x24];
    float f_24;
    float f_28;
    float f_2c;
    char pad4[8];
    int i_38;
    char pad5[0x2c];
} FamicomObj;

typedef struct Chain {
    void *next;
    void *destructor;
    void *object;
} Chain;

extern signed char lbl_68_bss_F0;
extern FamicomObj lbl_68_bss_F8;
extern float lbl_68_rodata_D4;
extern Chain lbl_68_bss_74;
void fn_68_C57C(void *);
void *__register_global_object(void *, void *, void *);

FamicomObj *fn_68_D5F0(void) {
    if (lbl_68_bss_F0 == 0) {
        lbl_68_bss_F8.f_24 = lbl_68_rodata_D4;
        lbl_68_bss_F8.f_28 = lbl_68_rodata_D4;
        lbl_68_bss_F8.f_2c = lbl_68_rodata_D4;
        lbl_68_bss_F8.i_38 &= 0xFFFFFFE0;
        __register_global_object(&lbl_68_bss_F8, (void *)fn_68_C57C, &lbl_68_bss_74);
        lbl_68_bss_F0 = 1;
    }
    return &lbl_68_bss_F8;
}

}
