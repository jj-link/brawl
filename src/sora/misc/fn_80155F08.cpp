#pragma force_active on
extern "C" int fn_8015227C(void*, int);

struct Self {
    char pad0[0x38C];
    int m_unk38C;
    char m_unk390;
    char pad1[3];
    void* m_unk394;
    char m_unk398;
};

extern "C" void fn_80155F08(Self* self, int unused, int arg2) {
    int result = fn_8015227C(self->m_unk394, arg2);
    if (result != 0) {
        self->m_unk38C = result;
        self->m_unk390 = 1;
        self->m_unk398 = 1;
    }
}
