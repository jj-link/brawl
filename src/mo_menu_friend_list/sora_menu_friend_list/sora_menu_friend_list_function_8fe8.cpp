#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct FnSelf {
    unsigned char pad0[0xC0];
    void* m_res;
    unsigned char pad1[0x24C4 - 0xC4];
    int m_val;
};

extern "C" int fn_14_8FE8(FnSelf* self) {
    return fn_800B61C0(self->m_res) ? 0x1c : self->m_val;
}
