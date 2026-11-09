#pragma force_active on

#include <ft/ft_cancel_module.h>
#include <ft/ft_common_data_accesser.h>

extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];
extern "C" void* lbl_27_data_59A0[];
extern "C" void* lbl_27_data_2AD00[];
extern "C" u8 lbl_27_data_2AC40[];

extern "C" ftCancelModuleImpl* fn_27_1404D4(ftCancelModuleImpl* self, soModuleAccesser* accsr) {
    char* p = (char*)self;

    ((void**)p)[0] = lbl_27_data_2AD00;
    p[4] = 0;

    soStatusEventObserver* status = (soStatusEventObserver*)(p + 8);
    status->m_manageID = -1;
    status->m_unitID = 4;
    status->m_sendID = -1;
    *(void**)status = __vt__21soStatusEventObserver;
    status->addObserver(-1, -1);

    soAnimCmdEventObserver* anim = (soAnimCmdEventObserver*)(p + 0x14);
    anim->m_manageID = -1;
    anim->m_unitID = 5;
    anim->m_sendID = -1;
    *(void**)anim = __vt__22soAnimCmdEventObserver;
    anim->addObserver(-1, -1);

    soSituationEventObserver* sit = (soSituationEventObserver*)(p + 0x20);
    sit->m_manageID = -1;
    sit->m_unitID = 8;
    sit->m_sendID = -1;
    *(void**)sit = lbl_27_data_59A0;
    sit->addObserver(-1, -1);

    *(void**)(p + 0x2c) = accsr;
    *(u8**)p = lbl_27_data_2AC40;
    *(u8**)(p + 8) = lbl_27_data_2AC40 + 0x1c;
    *(u8**)(p + 0x14) = lbl_27_data_2AC40 + 0x2c;
    *(u8**)(p + 0x20) = lbl_27_data_2AC40 + 0x40;
    ftDataCommon* common = g_ftCommonData.dataCommon;
    *(s32*)(p + 0x30) = ((s32*)common)[0x2c / 4];
    *(s32*)(p + 0x34) = -1;
    p[0x38] = 0;
    p[0x39] = 0;
    return self;
}
