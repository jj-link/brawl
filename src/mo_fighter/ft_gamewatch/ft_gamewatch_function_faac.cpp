#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

class CallbackObject {
public:
    virtual void slot0();
    virtual void update(soModuleAccesser*);
};

extern "C" void fn_107_FAAC(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
        reinterpret_cast<CallbackObject*>(energy)->update(accesser);
    }
}
