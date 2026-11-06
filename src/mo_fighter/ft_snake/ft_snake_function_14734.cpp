#include <so/so_module_accesser.h>
#include <so/so_photo_call_back.h>
#include <so/so_world.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern "C" {
extern const char lbl_122_data_774[], lbl_122_data_8C98[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_801AAFF0(void*, int);
unsigned int fn_27_111E30(void*);
}

extern "C" void fn_122_14734(soModuleAccesser* accesser, int status) {
    if (status >= 0x133 || status < 0x131) {
        void* mdl = accesser->m_enumerationStart->m_modelModule->getScnMdl(false);
        if (mdl != 0) {
            fn_801AAFF0(mdl, accesser->m_enumerationStart->m_workManageModule->getInt(0x10000041));
        }
        int id = accesser->m_enumerationStart->m_workManageModule->getInt(0x10000000);
        unsigned int result = fn_27_111E30(g_ftManager->getOwner(id));
        accesser->m_enumerationStart->m_modelModule->resetLayerType((gfSceneRoot::LayerType)(result == 1 ? 5 : 1));
        void* cast = __dynamic_cast(accesser->m_stageObject, 0x3c, lbl_122_data_774, lbl_122_data_8C98, 0);
        if (cast != 0) {
            ((soPhotoCallBack*)((char*)cast + 0x2D020))->removeCallBack();
            float scale = g_soWorld->m_8;
            accesser->m_enumerationStart->m_modelModule->setScaleZ(scale);
            accesser->m_enumerationStart->m_effectModule->ignoreScaleZ(false);
        }
    }
}
