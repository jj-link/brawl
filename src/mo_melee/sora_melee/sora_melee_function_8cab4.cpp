#include <so/so_external_value_accesser.h>
#pragma force_active on

float soExternalValueAccesser::getLr(StageObject* stageObject) {
    return stageObject->m_moduleAccesser->getPostureModule().getLr();
}
