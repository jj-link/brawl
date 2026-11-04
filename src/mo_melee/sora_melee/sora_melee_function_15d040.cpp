#include <ft/ft_manager.h>
#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <types.h>
#pragma force_active on

extern "C" void* getOwner__9ftManagerFi(ftManager* manager, s32 id);
extern "C" float fn_27_1120B4(void* arg);
extern "C" const float lbl_27_rodata_1F70[3];

class soNullableVtbl {
public:
    virtual void isNull();
    virtual void fn_27_15D4E4();
    virtual void fn_27_15D890();
    virtual void fn_27_7FCF8();
    virtual void fn_27_15D878();
    virtual void fn_27_15D040();
    virtual void fn_27_15D4D4();
    virtual void fn_27_15D874();
    virtual void fn_27_15D6CC();
    virtual void fn_27_15D6E0();
    virtual void fn_27_15D6F4();
    virtual void fn_27_15D7B4();
    virtual void fn_27_7FCF4();

    u32 m_pad04;
    s32 m_state;
    float m_c;
    float m_10;
    float m_14;
    float m_18;
    float m_1C;
    float m_20;
    s32 m_24;
};

extern "C" void fn_27_15D040(soNullableVtbl* self, s32 arg1, const float* arg2, u32 unused, soModuleAccesser* acc) {
    self->fn_27_15D4D4();
    self->m_state = arg1;
    self->m_24 = -1;
    s32 id = acc->m_enumerationStart->m_workManageModule->getInt(0x10000000);
    self->m_20 = fn_27_1120B4(getOwner__9ftManagerFi(g_ftManager, id));
    self->m_c = arg2[1];
    switch (self->m_state) {
    case 0:
        self->m_10 = -soValueAccesser::getConstantFloat(acc, 0xBCF, 0);
        self->m_14 = soValueAccesser::getConstantFloat(acc, 0xBD0, 0);
        self->m_18 = soValueAccesser::getConstantFloat(acc, 0xBD1, 0);
        self->m_1C = soValueAccesser::getConstantFloat(acc, 0xBD2, 0);
        self->m_24 = 0;
        break;
    case 1:
        self->m_10 = soValueAccesser::getConstantFloat(acc, 0xBCF, 0);
        self->m_14 = soValueAccesser::getConstantFloat(acc, 0xBD0, 0);
        self->m_18 = soValueAccesser::getConstantFloat(acc, 0xBD1, 0);
        self->m_1C = soValueAccesser::getConstantFloat(acc, 0xBD2, 0);
        self->m_24 = 1;
        break;
    case 2:
        self->m_10 = soValueAccesser::getConstantFloat(acc, 0xC11, 0);
        self->m_14 = soValueAccesser::getConstantFloat(acc, 0xC12, 0);
        self->m_18 = soValueAccesser::getConstantFloat(acc, 0xBD1, 0);
        self->m_1C = soValueAccesser::getConstantFloat(acc, 0xBD2, 0);
        self->m_24 = 1;
        break;
    case 3:
        self->m_10 = -soValueAccesser::getConstantFloat(acc, 0xD1C, 0);
        self->m_14 = soValueAccesser::getConstantFloat(acc, 0xBD0, 0);
        self->m_18 = soValueAccesser::getConstantFloat(acc, 0xBD1, 0);
        self->m_1C = soValueAccesser::getConstantFloat(acc, 0xBD2, 0);
        self->m_24 = 0;
        break;
    case 4: {
        float t = soValueAccesser::getConstantFloat(acc, 0xC16, 0);
        float n = -soValueAccesser::getConstantFloat(acc, 0xBCF, 0);
        self->m_10 = n * t;
        self->m_14 = soValueAccesser::getConstantFloat(acc, 0xBD0, 0);
        self->m_18 = soValueAccesser::getConstantFloat(acc, 0xBD1, 0);
        self->m_1C = soValueAccesser::getConstantFloat(acc, 0xBD2, 0);
        self->m_24 = 0;
        break;
    }
    case 5:
        self->m_10 = -acc->m_enumerationStart->m_workManageModule->getFloat(0x21000008);
        self->m_14 = soValueAccesser::getConstantFloat(acc, 0xBD0, 0);
        self->m_18 = soValueAccesser::getConstantFloat(acc, 0xBD1, 0);
        self->m_1C = soValueAccesser::getConstantFloat(acc, 0xBD2, 0);
        self->m_24 = 0;
        break;
    case 6: {
        float t = soValueAccesser::getConstantFloat(acc, 0xD09, 0);
        float n = -soValueAccesser::getConstantFloat(acc, 0xBCF, 0);
        self->m_10 = n * t;
        self->m_14 = soValueAccesser::getConstantFloat(acc, 0xBD0, 0);
        self->m_18 = soValueAccesser::getConstantFloat(acc, 0xBD1, 0);
        self->m_1C = soValueAccesser::getConstantFloat(acc, 0xBD2, 0);
        self->m_24 = 0;
        break;
    }
    case 7: {
        float* p = (float*)soValueAccesser::getConstantIndefinite(acc, 0xA80B, 0);
        self->m_c = self->m_c + p[2];
        self->m_10 = p[3] * -soValueAccesser::getConstantFloat(acc, 0xBCF, 0);
        self->m_14 = soValueAccesser::getConstantFloat(acc, 0xBD0, 0);
        self->m_18 = soValueAccesser::getConstantFloat(acc, 0xBD1, 0);
        self->m_1C = soValueAccesser::getConstantFloat(acc, 0xBD2, 0);
        self->m_24 = 0;
        break;
    }
    case 8:
        self->m_10 = -soValueAccesser::getConstantFloat(acc, 0xDA3, 0);
        self->m_14 = soValueAccesser::getConstantFloat(acc, 0xDA4, 0);
        self->m_18 = lbl_27_rodata_1F70[0];
        self->m_1C = soValueAccesser::getConstantFloat(acc, 0xDA4, 0);
        self->m_24 = 0;
        break;
    }
}
