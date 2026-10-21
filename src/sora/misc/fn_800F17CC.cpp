#pragma force_active on
extern "C" int fn_800F2894(void*);
extern "C" void exit__6gfTaskFv(void*);

struct Self {
    char pad0[0x34];
    int m_34;
    char pad1[0x5c - 0x38];
    void* m_5c;
};

extern "C" int fn_800F17CC(Self* self) {
    if (fn_800F2894(self->m_5c)) {
        exit__6gfTaskFv(self->m_5c);
        self->m_5c = 0;
        return 1;
    }
    return self->m_34;
}
