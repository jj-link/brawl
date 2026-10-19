#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct AdvMenuDifficulty {
    char m_pad0[0x40];
    int m_state;
    char m_pad1[0x1b0 - 0x44];
    void* m_res;
    char m_pad2[0x1c8 - 0x1b4];
    int m_value;
    char m_pad3[0x33c - 0x1cc];
    unsigned char m_flag;
};

extern "C" {
int fn_32_C78(AdvMenuDifficulty* self) {
    if (fn_800B61C0(self->m_res)) {
        if (self->m_flag) {
            self->m_state = 1;
        } else {
            self->m_state = 2;
        }
    }
    return self->m_value;
}
}
