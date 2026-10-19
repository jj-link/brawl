#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

extern "C" const float lbl_96_rodata_B8;

extern "C" void fn_96_1BA64(void*, soModuleAccesser* accesser) {
    if (lbl_96_rodata_B8 == accesser->getPostureModule().getLr()) {
        accesser->getPostureModule().reverseRotYLr();
        accesser->getStageObject().updateNodeSRT();
    }
}
