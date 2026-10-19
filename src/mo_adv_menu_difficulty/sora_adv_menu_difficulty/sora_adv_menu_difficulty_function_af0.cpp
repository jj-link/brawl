#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct AdvMenuDifficulty {
    char m_pad0[0x1b0];
    void* m_res;
    char m_pad1[0x1c8 - 0x1b4];
    int m_value;
};

extern "C" {
int fn_32_AF0(AdvMenuDifficulty* self) {
    if (fn_800B61C0(self->m_res)) {
        return 2;
    }
    return self->m_value;
}
}
