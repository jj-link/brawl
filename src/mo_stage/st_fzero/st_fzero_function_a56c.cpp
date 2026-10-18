#pragma force_active on
struct Object {
    unsigned char pad[0x24];
    float x, y, z;
    unsigned char pad30[8];
    unsigned int flags;
    unsigned char tail[0x2C];
};

extern "C" {
extern signed char lbl_61_bss_B8;
extern Object lbl_61_bss_C0;
extern const float lbl_61_rodata_140[];
extern unsigned char lbl_61_bss_30[];

void fn_61_7D94();
void* __register_global_object(void*, void*, void*);

Object* fn_61_A56C() {
    if (lbl_61_bss_B8 == 0) {
        lbl_61_bss_C0.x = lbl_61_rodata_140[0];
        lbl_61_bss_C0.y = lbl_61_rodata_140[0];
        lbl_61_bss_C0.z = lbl_61_rodata_140[0];
        lbl_61_bss_C0.flags &= ~31u;
        __register_global_object(
            &lbl_61_bss_C0,
            (void*)fn_61_7D94,
            lbl_61_bss_30
        );
        lbl_61_bss_B8 = 1;
    }
    return &lbl_61_bss_C0;
}
}
