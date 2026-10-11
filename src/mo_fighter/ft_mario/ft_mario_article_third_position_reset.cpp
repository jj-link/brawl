#include <so/stageobject.h>

extern "C" void fn_91_18EC4(StageObject* object, Vec3f* position) {
    object->m_moduleAccesser->getPostureModule().initPos(position);
    object->m_moduleAccesser->getLinkModule().removeModelConstraint(true);
    object->updateNodeSRT();
}
