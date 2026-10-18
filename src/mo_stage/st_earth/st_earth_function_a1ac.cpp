#pragma force_active on
struct Storage {
    unsigned char pad[0x24];
    float x, y, z;
    unsigned char pad30[8];
    unsigned int flags;
    unsigned char tail[0x2c];
};

extern "C" {
extern signed char lbl_66_bss_100;
extern Storage lbl_66_bss_108;
extern const float lbl_66_rodata_1B8;
extern unsigned char lbl_66_bss_6C[12];

void fn_66_7E90(void*, short);
void* __register_global_object(void*, void*, void*);

Storage* fn_66_A1AC() {
    if (lbl_66_bss_100 == 0) {
        lbl_66_bss_108.x = lbl_66_rodata_1B8;
        lbl_66_bss_108.y = lbl_66_rodata_1B8;
        lbl_66_bss_108.z = lbl_66_rodata_1B8;
        lbl_66_bss_108.flags &= ~31u;
        __register_global_object(
            &lbl_66_bss_108, (void*)fn_66_7E90, lbl_66_bss_6C);
        lbl_66_bss_100 = 1;
    }
    return &lbl_66_bss_108;
}
}
