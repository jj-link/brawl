#pragma force_active on
struct Yakumono {
    void setTeam(int team);
};

struct Target {
    unsigned char pad_0000[0x14c];
    Yakumono* m_yakumono;
    unsigned char pad_0150[0x1a4 - 0x150];
    float m_f1a4;
    unsigned char pad_01a8[0x1ac - 0x1a8];
    unsigned char m_b1ac;
    unsigned char m_b1ad;
};

extern "C" {
extern const float lbl_82_rodata_C0;
}

extern "C" {
void fn_82_42B0(Target* self) {
    if (self->m_yakumono) {
        self->m_yakumono->setTeam(16);
    }
    self->m_b1ac = 0;
    self->m_f1a4 = lbl_82_rodata_C0;
    self->m_b1ad = 0;
}
}
