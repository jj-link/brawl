#include <gr/gr_gimmick.h>
#include <gm/gm_global.h>
#include <new>
#pragma force_active on

extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" void fn_47_1750(void*, const char*);
extern "C" unsigned char lbl_47_data_10D0[];
extern "C" const float lbl_47_rodata_48;
extern "C" const float lbl_47_rodata_4C;

struct Object {
    char pad[0x3c];
    void* vt;
    char pad40[0x118];
    unsigned char a158;
    float a15c;
    unsigned char a160;
    unsigned int a164, a168, a16c;
    float a170, a174, a178, a17c, a180;
    unsigned char a184;
    float a188;
    unsigned char a18c;
    float a190;
    unsigned int a194, a198, a19c, a1a0, a1a4;
    char gen[8];
    unsigned char a1b0;
};

extern "C" Object* fn_47_1B04(Object* self, const char* name) {
    fn_47_1750(self, name);
    self->vt = lbl_47_data_10D0;
    __ct__14snd3DGeneratorFv(self->gen);
    self->a158 = 0;
    self->a15c = lbl_47_rodata_48;
    self->a160 = 0;
    self->a164 = 0;
    self->a168 = 0;
    self->a16c = 0;
    self->a170 = lbl_47_rodata_48;
    self->a174 = lbl_47_rodata_48;
    self->a178 = lbl_47_rodata_48;
    self->a17c = lbl_47_rodata_48;
    self->a180 = lbl_47_rodata_4C;
    self->a184 = 0;
    self->a188 = lbl_47_rodata_48;
    self->a18c = 1;
    self->a190 = lbl_47_rodata_48;
    self->a194 = 0;
    self->a198 = 0;
    self->a19c = 0;
    self->a1a0 = 0;
    self->a1a4 = 0;
    self->a1b0 = 0;
    ((grGimmick*)self)->makeCalcuCallback(1, (Heaps::HeapType)15);
    ((grGimmick*)self)->setCalcuCallbackRoot(0x15);
    unsigned char* mode = (unsigned char*)g_GameGlobal->m_modeMelee;
    if (!mode) return self;
    if ((((unsigned int)mode[8] >> 2) & 0x3f) != 7) return self;
    if (mode[0x10] == 0x9e) self->a1b0 = 1;
    return self;
}