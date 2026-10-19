#pragma force_active on
struct PictChatObject {
    unsigned char pad00[0x24];
    float values[3];
    unsigned char pad30[0x08];
    unsigned int flags;
};

extern "C" {
extern signed char lbl_73_bss_B8;
extern PictChatObject lbl_73_bss_C0;
extern float lbl_73_rodata_88;
extern unsigned char lbl_73_bss_30[];

void* fn_73_4518(void*, int);
void __register_global_object(void*, void*, void*);

PictChatObject* fn_73_A8B8() {
    if (lbl_73_bss_B8 == 0) {
        float value = lbl_73_rodata_88;
        lbl_73_bss_C0.values[0] = value;
        lbl_73_bss_C0.values[1] = value;
        lbl_73_bss_C0.values[2] = value;
        lbl_73_bss_C0.flags &= ~31u;
        __register_global_object(
            &lbl_73_bss_C0,
            reinterpret_cast<void*>(fn_73_4518),
            lbl_73_bss_30
        );
        lbl_73_bss_B8 = 1;
    }
    return &lbl_73_bss_C0;
}
}
