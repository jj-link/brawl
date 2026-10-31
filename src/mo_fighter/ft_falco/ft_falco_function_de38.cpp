#include <so/so_null.h>
#include <so/so_enable.h>
#include <so/so_suspend.h>
#pragma force_active on

class soModuleAccesser;

class Energy : public soNullable, public soEnable, public soSuspendable {
public:
    virtual void update(soModuleAccesser* accesser);
};

extern "C" void fn_108_DE38(Energy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true) {
        if (reinterpret_cast<u8*>(energy)[6] != 0) {
            return;
        }
        energy->update(accesser);
        return;
    }
}
