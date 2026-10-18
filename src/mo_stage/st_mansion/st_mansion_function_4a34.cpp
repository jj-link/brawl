#pragma force_active on
struct Object {
    unsigned char pad[0x24];
    float x, y, z;
    unsigned char pad30[8];
    unsigned int flags;
    unsigned char rest[0x2C];
};

extern "C" {
extern signed char lbl_47_bss_60;
extern Object lbl_47_bss_68;
extern const float lbl_47_rodata_70;
extern unsigned char lbl_47_bss_30[12];

void fn_47_2C0C();
void* __register_global_object(void*, void*, void*);

Object* fn_47_4A34() {
    if (lbl_47_bss_60 == 0) {
        lbl_47_bss_68.x = lbl_47_rodata_70;
        lbl_47_bss_68.y = lbl_47_rodata_70;
        lbl_47_bss_68.z = lbl_47_rodata_70;
        lbl_47_bss_68.flags &= ~31u;
        __register_global_object(
            &lbl_47_bss_68,
            reinterpret_cast<void*>(fn_47_2C0C),
            lbl_47_bss_30);
        lbl_47_bss_60 = 1;
    }
    return &lbl_47_bss_68;
}
}
