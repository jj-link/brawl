#include <types.h>
#pragma force_active on

extern "C" {
void fn_63_2B6C(void* self);
void* __ct__14snd3DGeneratorFv(void* self);
extern char lbl_63_data_4598[];
}

struct st_gw_obj {
    char pad_00[0x3C];
    void* m_3C;
    char pad_40[0x174 - 0x40];
    int m_174;
    int m_178;
    unsigned char m_17C;
    unsigned char m_17D;
    unsigned char m_17E;
    unsigned char m_17F;
    unsigned char m_180;
    unsigned char m_181;
    int m_184;
    char m_188[0x4];
};

extern "C" {
st_gw_obj* fn_63_FC60(st_gw_obj* self) {
    int* p;
    fn_63_2B6C(self);
    self->m_3C = lbl_63_data_4598;
    __ct__14snd3DGeneratorFv(self->m_188);
    p = (int*)((char*)self + 0xD0);
    self->m_174 = 0;
    self->m_178 = 0;
    self->m_17C = 4;
    self->m_17D = 0;
    self->m_17E = 0x10;
    self->m_17F = 0;
    self->m_180 = 0;
    self->m_181 = 0;
    self->m_184 = 0;
    if (p == 0) {
        return self;
    }
    {
        int* q = (int*)p[1];
        q[1] |= 1;
    }
    return self;
}
}
