#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct Self {
    char pad[0x40];
    void* m_res;
    int m_val;
};

extern "C" {
int fn_12_113C(Self* self) {
    if (fn_800B61C0(self->m_res)) {
        return 6;
    }
    return self->m_val;
}
}
