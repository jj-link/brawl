#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_34E88[];
}

struct soWorkState {
    unsigned char* m_0;
    unsigned char* m_4;
    unsigned int m_8;
};

extern "C" void fn_27_1A5384(soWorkState* self) {
    unsigned int r0 = self->m_8;
    unsigned char* base = lbl_27_data_34E88;
    self->m_0 = base;
    self->m_4 = base + 0x48;
    self->m_8 = r0 & 0x003FFFFF;
}
