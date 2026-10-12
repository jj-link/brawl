#include <ft/fighter.h>

extern "C" void fn_27_1DA868(Fighter*);

extern "C" void fn_99_10648(Fighter* fighter, Vec3f* position) {
    fighter->m_moduleAccesser->getPostureModule().initPos(position);
    fn_27_1DA868(fighter);
    fighter->updateNodeSRT();
}
