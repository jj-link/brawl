#pragma force_active on
extern const float lbl_27_rodata_8F8;

struct SoraObj {
    char pad[0x54];
    float m_54;
};

extern "C" void fn_27_64E88(SoraObj* self) {
    self->m_54 = lbl_27_rodata_8F8;
}
