#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_23F008(void*);
extern char lbl_27_data_4D7F0[0x7C];

struct SomeClass {
    char _0[0x3c];
    char* m_data;
    char _1[0x58];
    u8 m_flag;
    char _2[0x33];
    s32 m_unk;
    gmAdvData* m_advData;
};

extern "C" SomeClass* fn_27_240538(SomeClass* self) {
    fn_27_23F008(self);
    self->m_data = lbl_27_data_4D7F0;
    self->m_unk = -1;
    self->m_advData = g_GameGlobal->m_advData;
    self->m_flag = 1;
    return self;
}
