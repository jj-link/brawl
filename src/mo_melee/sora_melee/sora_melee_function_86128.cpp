#pragma force_active on
typedef unsigned int u32;

struct soCollisionAttackAbsolute {
    unsigned char m_00[0x24];
    float m_24;
    float m_28;
    float m_2c;
    u32 m_30;
    u32 m_34;
    u32 m_38;
    unsigned char m_3c[0x68 - 0x40];
};

extern "C" {
extern signed char lbl_27_bss_18B0;
extern soCollisionAttackAbsolute lbl_27_bss_18B8;
extern unsigned char lbl_27_bss_1028[12];
extern const float lbl_27_rodata_B74;
void __dt__25soCollisionAttackAbsoluteFv(void);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_27_86128() {
    if (lbl_27_bss_18B0 == 0) {
        lbl_27_bss_18B8.m_24 = lbl_27_rodata_B74;
        lbl_27_bss_18B8.m_28 = lbl_27_rodata_B74;
        lbl_27_bss_18B8.m_2c = lbl_27_rodata_B74;
        lbl_27_bss_18B8.m_38 = lbl_27_bss_18B8.m_38 & ~31u;
        __register_global_object(&lbl_27_bss_18B8, (void*)__dt__25soCollisionAttackAbsoluteFv, lbl_27_bss_1028);
        lbl_27_bss_18B0 = 1;
    }
    return &lbl_27_bss_18B8;
}
}
