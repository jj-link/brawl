#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct Self {
    char pad0[0x4];
    void* m_res;
    char pad1[0x110 - 0x8];
    int m_value;
};

extern "C" int fn_800FF514(Self* self) {
    if (fn_800B61C0(self->m_res)) {
        return 3;
    }
    return self->m_value;
}
