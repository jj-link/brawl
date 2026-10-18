#pragma force_active on
struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
};

struct Type72 {
    char _0x00[0x24];
    float _0x24;
    float _0x28;
    float _0x2c;
    char _0x30[8];
    int _0x38;
    char _0x3c[0x2c];
};

extern "C" {
extern signed char lbl_72_bss_D0;
extern Type72 lbl_72_bss_D8;
extern DestructorChain lbl_72_bss_3C;
extern const float lbl_72_rodata_6C;
extern void __register_global_object(void *, void *, void *);
void fn_72_2F3C(void);

void *fn_72_4E68(void) {
    if (lbl_72_bss_D0 == 0) {
        lbl_72_bss_D8._0x24 = lbl_72_rodata_6C;
        lbl_72_bss_D8._0x28 = lbl_72_rodata_6C;
        lbl_72_bss_D8._0x2c = lbl_72_rodata_6C;
        lbl_72_bss_D8._0x38 &= ~0x1F;
        __register_global_object(&lbl_72_bss_D8, reinterpret_cast<void *>(fn_72_2F3C), &lbl_72_bss_3C);
        lbl_72_bss_D0 = 1;
    }
    return &lbl_72_bss_D8;
}
}
