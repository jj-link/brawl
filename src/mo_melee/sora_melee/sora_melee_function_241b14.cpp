#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_23EB70(void* self, s32 param);
extern char lbl_27_data_4DF50[];

struct SomeClass {
    char _0[0x3c];
    char* m_data;
    char _1[0x2c];
    s32 m_unk;
    gmAdvData* m_advData;
};

extern "C" SomeClass* fn_27_241B14(SomeClass* self) {
    fn_27_23EB70(self, 4);
    self->m_unk = -1;
    self->m_data = lbl_27_data_4DF50;
    self->m_advData = g_GameGlobal->m_advData;
    return self;
}
