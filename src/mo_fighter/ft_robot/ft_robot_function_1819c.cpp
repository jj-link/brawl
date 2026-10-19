#include <ft/fighter.h>
#pragma force_active on

extern "C" void fn_27_1DA030(Fighter*);

extern "C" void fn_120_1819C(Fighter* fighter) {
    soModuleAccesser* accesser = fighter->m_moduleAccesser;
    soModelModule& model = accesser->getModelModule();
    model.getNodeGlobalPosition(0, false);
    fn_27_1DA030(fighter);
}
