#include <so/so_value_accesser.h>
#include <so/status/so_status_module_impl.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

struct GroundPad {
    int pad0;
    int pad4;
};

class GroundCall : public GroundPad {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
    virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
    virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29();
    virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34();
    virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
    virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44();
    virtual void f45(); virtual void f46(); virtual void f47(); virtual void f48(); virtual void f49();
    virtual void f50(); virtual void f51(); virtual void f52(); virtual void f53(); virtual void f54();
    virtual void f55(); virtual void f56(); virtual void f57(); virtual void f58(); virtual void f59();
    virtual void f60(); virtual void f61(); virtual void f62(); virtual void f63(); virtual void f64();
    virtual void f65(); virtual void f66(); virtual void f67(); virtual void f68(); virtual void f69();
    virtual void f70(); virtual void f71(); virtual void f72(); virtual void f73(); virtual void f74();
    virtual void f75(); virtual void f76(); virtual void f77(); virtual void f78(); virtual void f79();
    virtual void f80(); virtual void f81(); virtual void f82(); virtual void f83(); virtual void f84();
    virtual void f85(); virtual void f86(); virtual void f87(); virtual void f88(); virtual void f89();
    virtual void f90(); virtual void f91(); virtual void f92(); virtual void f93(); virtual void f94();
    virtual void f95(); virtual void f96(); virtual void f97(); virtual void f98(); virtual void f99();
    virtual void f100(); virtual void f101(); virtual void f102(); virtual void f103(); virtual void f104();
    virtual void f105(); virtual void f106(); virtual void f107(); virtual void f108();
    virtual u32 f109(u32 index);
};

extern "C" void fn_27_168C88(void*, soModuleAccesser* accesser) {
    soStatusModule* status = accesser->m_enumerationStart->m_statusModule;
    switch (status->getStatusKind()) {
    case 0x11: {
        int id = accesser->m_enumerationStart->m_workManageModule->getInt(0x20000000);
        if (id > 0) {
            accesser->m_enumerationStart->m_workManageModule->setInt(id - 1, 0x20000000);
        }

        if (id == -1) {
            soControllerModule* ctrl = accesser->m_enumerationStart->m_controllerModule;
            float limit = soValueAccesser::getConstantFloat(accesser, 0xC73, 0);
            if (ctrl->getStickY() <= limit) {
                soControllerModule* ctrl2 = accesser->m_enumerationStart->m_controllerModule;
                int maxv = soValueAccesser::getConstantInt(accesser, 0x5A06, 0);
                if ((u8)ctrl2->getFlickY() < maxv) {
                    GroundCall* ground = (GroundCall*)accesser->m_enumerationStart->m_groundModule;
                    if (ground->f109(0) == 1) {
                        float v = soValueAccesser::getConstantFloat(accesser, 0xC75, 0);
                        accesser->m_enumerationStart->m_workManageModule->setInt((int)v, 0x20000000);
                    }
                }
            }
        }
        break;
    }
    default:
        break;
    }
}
