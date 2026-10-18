#pragma force_active on
extern "C" {
struct Registration {
    void *next;
    void *object;
    void *destructor;
};

extern signed char lbl_61_bss_48;
extern unsigned char lbl_61_bss_50[];
extern unsigned char lbl_61_bss_24[];
extern float lbl_61_rodata_140;
void fn_61_7D94(void *);
void __register_global_object(void *, void *, Registration *);

unsigned char *fn_61_A4EC() {
    if (lbl_61_bss_48 == 0) {
        unsigned char *object = lbl_61_bss_50;
        float value = lbl_61_rodata_140;
        unsigned int flags = *(unsigned int *)(object + 0x38);

        *(float *)(object + 0x24) = value;
        *(float *)(object + 0x28) = value;
        *(float *)(object + 0x2C) = value;
        *(unsigned int *)(object + 0x38) = flags & ~31u;
        __register_global_object(object, (void *)fn_61_7D94,
                                 (Registration *)lbl_61_bss_24);
        lbl_61_bss_48 = 1;
    }
    return lbl_61_bss_50;
}
}
