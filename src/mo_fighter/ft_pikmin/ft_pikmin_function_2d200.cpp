#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_113_2D200(StageObject* object) {
    object->m_moduleAccesser->getLinkModule().unlinkAll();
    object->m_moduleAccesser->getLinkModule().unlinkNodeAll();
}
