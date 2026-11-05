#include <mu/mu_object.h>

#pragma force_active on

extern "C" void fn_800B330C(void* obj, void* data, int flag);
extern "C" void fn_800B7AA4(void* obj, float rate, unsigned char flag);
extern "C" void fn_800B7F38(void* obj, float rate, unsigned char flag);

extern char lbl_2_data_4338[];
extern char lbl_2_data_4490[];
extern float lbl_2_rodata_159C;

struct Self {
    char pad[0x64];
    MuObject* m64;
    MuObject* m68;
    MuObject* m6c;
    char pad2[0x7c - 0x70];
    int f7c;
};

extern "C" void fn_2_36824(Self* self) {
    fn_800B330C(self->m6c, lbl_2_data_4338 + 0xdc, 0);
    fn_800B7AA4(self->m6c, *(float*)(lbl_2_data_4338 + 0xe0), *(unsigned char*)(lbl_2_data_4338 + 0xec));
    fn_800B7F38(self->m6c, lbl_2_rodata_159C, *(unsigned char*)(lbl_2_data_4338 + 0xec));
    fn_800B330C(self->m68, lbl_2_data_4490 + 0x14, 0);
    fn_800B7AA4(self->m68, *(float*)(lbl_2_data_4490 + 0x18), *(unsigned char*)(lbl_2_data_4490 + 0x24));
    fn_800B7F38(self->m68, lbl_2_rodata_159C, *(unsigned char*)(lbl_2_data_4490 + 0x24));
    self->m64->m_modelAnim->setUpdateRate(lbl_2_rodata_159C);
    self->m68->m_modelAnim->setUpdateRate(lbl_2_rodata_159C);
    self->m6c->m_modelAnim->setUpdateRate(lbl_2_rodata_159C);
    self->f7c = 0x22;
}
