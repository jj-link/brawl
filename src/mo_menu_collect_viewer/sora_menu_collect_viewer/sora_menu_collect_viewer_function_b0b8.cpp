#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct Self {
    char pad0[0x40];
    void* m_res;
    char pad1[0x128 - 0x44];
    int m_flag;
};

extern "C" int fn_6_B0B8(Self* self) {
    if (fn_800B61C0(self->m_res)) {
        return 1;
    }
    return self->m_flag;
}
