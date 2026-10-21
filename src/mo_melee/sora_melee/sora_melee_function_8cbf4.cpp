#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

extern "C" int getStatusKind__23soExternalValueAccesserFP11StageObject(StageObject* object)
{
    return object->m_moduleAccesser->m_enumerationStart->m_statusModule->getStatusKind();
}
