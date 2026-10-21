#pragma force_active on
extern "C" {
void fn_50_1F78(void* self);
void __ct__14snd3DGeneratorFv(void* self);
extern char lbl_50_data_19C0[];
extern const float lbl_50_rodata_A0;
}

struct St_donkey_obj {
    char pad_00[0x3C];
    void* m_3C;
    char pad_40[0x164 - 0x40];
    unsigned char m_164;
    char pad_165[3];
    int m_168;
    float m_16C;
    float m_170;
    float m_174;
    unsigned char m_178;
    unsigned char m_179;
    int m_17C;
    int m_180;
    int m_184;
    unsigned char m_188;
    char pad_189[3];
    float m_18C;
    char m_190[8];
    float m_198;
    int m_19C;
    int m_1A0;
    int m_1A4;
};

extern "C" {
St_donkey_obj* fn_50_3E6C(St_donkey_obj* self) {
    unsigned int* p;
    float z;
    fn_50_1F78(self);
    self->m_3C = lbl_50_data_19C0;
    __ct__14snd3DGeneratorFv(self->m_190);
    z = lbl_50_rodata_A0;
    p = (unsigned int*)((char*)self + 0xD0);
    self->m_164 = 1;
    self->m_168 = 0;
    self->m_16C = z;
    self->m_170 = z;
    self->m_174 = z;
    self->m_17C = 0;
    self->m_178 = 0;
    self->m_179 = 0;
    self->m_198 = z;
    self->m_19C = -1;
    self->m_1A0 = -1;
    self->m_1A4 = -1;
    self->m_180 = 0;
    self->m_184 = 0;
    self->m_188 = 2;
    self->m_18C = z;
    if (p == 0) {
        return self;
    }
    {
        unsigned int* q = (unsigned int*)p[1];
        q[1] |= 1;
    }
    return self;
}
}
