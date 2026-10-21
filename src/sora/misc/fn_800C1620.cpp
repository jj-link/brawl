#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct Self {
    char pad0[0x40];
    void* m_res;
    char pad1[0x10C - 0x44];
    int m_val;
};

extern "C" int fn_800C1620(Self* self) {
    if (fn_800B61C0(self->m_res)) {
        return 3;
    }
    return self->m_val;
}
