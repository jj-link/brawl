#pragma force_active on
struct fn27Obj {
    unsigned char pad0[0x2c];
    float m_2c;
    unsigned char pad30[0x18];
    unsigned char m_48;
};

extern "C" {
extern const float lbl_27_rodata_EC8;

float fn_27_C2594(fn27Obj *p) {
    if (p->m_48 == 0) {
        return p->m_2c;
    }
    return lbl_27_rodata_EC8;
}
}
