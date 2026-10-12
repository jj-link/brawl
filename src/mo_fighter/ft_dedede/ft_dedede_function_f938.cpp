#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

// The concrete normal-energy type is not declared by the shared headers.
struct DededeNormalEnergy {
    unsigned char base[8];
    Vec2f speed;
    void setSpeed(const Vec2f& value) {
        speed.m_x = value.m_x;
        speed.m_y = value.m_y;
    }
};

struct DededeCaptureLinkEvent : soLinkEventArgs {
    DededeCaptureLinkEvent() : soLinkEventArgs(0x844) {}
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_117_data_8498[], lbl_117_data_36A8[];
extern const float lbl_117_rodata_50, lbl_117_rodata_54;
void fn_117_FD3C(void*, soModuleAccesser*, int, bool);
void fn_117_FF50(void*, soModuleAccesser*);
}

struct DededeCaptureProcess {
    void update(soModuleAccesser* accesser);
};

inline void DededeCaptureProcess::update(soModuleAccesser* accesser) {
    DededeCaptureProcess* self = this;
    if (accesser->getStatusModule().getStatusKind() == 0x137)
        return;
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x130: {
        float speed = soValueAccesser::getConstantFloat(accesser, 0xFC0, 0);
        float facing = accesser->getPostureModule().getLr();
        DededeNormalEnergy* energy = static_cast<DededeNormalEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(2), 0,
            lbl_117_data_8498, lbl_117_data_36A8, 1));
        energy->setSpeed(Vec2f(speed * facing, lbl_117_rodata_50));
        fn_117_FD3C(self, accesser, 0x22, true);
        break;
    }
    case 0x131:
    case 0x133:
    case 0x135:
        fn_117_FD3C(self, accesser, 0x22, false);
        break;
    }

    if (accesser->getWorkManageModule().isFlag(0x22000012)) {
        if (!accesser->getWorkManageModule().isFlag(0x22000013)) {
            DededeCaptureLinkEvent event;
            accesser->getLinkModule().sendEventNodes(1, event, 0);
            accesser->getWorkManageModule().onFlag(0x22000014);
            accesser->getWorkManageModule().onFlag(0x22000013);
        }
        soDamageModule& damage = accesser->getDamageModule();
        if (damage.getDamage(0) < static_cast<float>(
                soValueAccesser::getConstantInt(accesser, 0x5DC8, 0))) {
            accesser->getWorkManageModule().addInt(1, 0x20000003);
            soWorkManageModule& work = accesser->getWorkManageModule();
            int maxCount = soValueAccesser::getConstantInt(accesser, 0x5DC7, 0);
            if (work.getInt(0x20000003) >= maxCount) {
                accesser->getWorkManageModule().addInt(1, 0x20000004);
                accesser->getDamageModule().addDamage(lbl_117_rodata_54, 0);
                accesser->getWorkManageModule().setInt(0, 0x20000003);
            }
        }
    }
    fn_117_FF50(self, accesser);
}

extern "C" void fn_117_F938(DededeCaptureProcess* self, soModuleAccesser* accesser) {
    self->update(accesser);
}
