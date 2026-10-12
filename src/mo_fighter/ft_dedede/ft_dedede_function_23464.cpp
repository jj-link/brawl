#include <so/so_module_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>

// Kinetic speed is returned in r3/r4, unlike the nontrivial Vec2f result.
class DededeNormalSpeedEnergy : public soNullable, public soEnable, public soSuspendable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual DededeSpeed getSpeed();
    Vec2f speed;
};

extern "C" {
extern const float lbl_117_rodata_140[4];
extern const char lbl_117_data_83EC[], lbl_117_data_36A8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_117_23464(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_117_rodata_140;
    if (accesser->getWorkManageModule().getInt(0x20000004) != 2) {
        switch (accesser->getStatusModule().getStatusKind()) {
        case 23:
            if (accesser->getWorkManageModule().getFloat(0x21000001) <= constants[0]) {
                accesser->getWorkManageModule().onFlag(0x2200000B);
                accesser->getStatusModule().changeStatusRequest(21, accesser);
            }
            break;
        }
        if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(6), 0)) {
            switch (accesser->getStatusModule().getStatusKind()) {
            case 18:
                accesser->getStatusModule().changeStatusRequest(19, accesser);
                accesser->getWorkManageModule().addInt(1, 0x20000002);
                break;
            case 20:
                accesser->getWorkManageModule().onFlag(0x22000007);
                break;
            }
            if (accesser->getStatusModule().getStatusKind() != 18) {
                DededeNormalSpeedEnergy* energy = static_cast<DededeNormalSpeedEnergy*>(__dynamic_cast(
                    accesser->getKineticModule().getEnergy(0), 0,
                    lbl_117_data_83EC, lbl_117_data_36A8, 1));
                energy->speed = Vec2f(constants[0], energy->getSpeed().y);
            }
            accesser->getWorkManageModule().onFlag(0x22000009);
            accesser->getWorkManageModule().subInt(1, 0x20000006);
            if (accesser->getWorkManageModule().getInt(0x20000006) <= 0)
                accesser->getWorkManageModule().onFlag(0x22000004);
        }
    } else {
        if (accesser->getPostureModule().getLr() == constants[2])
            accesser->getModelModule().setNodeRotateY(4, constants[3]);
    }
}
