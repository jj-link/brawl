#include <so/so_module_accesser.h>
#pragma force_active on
struct Speed { float x, y; };
class KineticView {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual Speed speed(short*);
};
extern const float lbl_113_rodata_E8;
extern "C" void fn_113_23B84(soModuleAccesser* a) {
    switch (a->getWorkManageModule().getInt(0x1000000F)) {
    default:
        return;
    case 0:
    case 1:
    case 3:
        short flag = 1;
        Speed speed = reinterpret_cast<KineticView*>(&a->getKineticModule())->speed(&flag);
        if ((speed.y > lbl_113_rodata_E8) == 0) {
            if (a->getGroundModule().attachGround(0) == 1) {
                a->getSituationModule().setKind(Situation_Ground, false);
                a->getStatusModule().changeStatusRequest(9, a);
            }
        }
        break;
    case 2:
        break;
    }
}