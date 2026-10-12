#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>

// These interfaces return the two float words in r3/r4, not Vec2f's hidden result.
class DededeSpeedEnergy : public soNullable, public soEnable, public soSuspendable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual DededeSpeed getSpeed();
    void enable() { reinterpret_cast<unsigned char*>(this)[5] |= 0x80; }
};
struct DededeDamageEnergy : DededeSpeedEnergy {
    DededeSpeed speed;
    DededeSpeed acceleration;
    DededeSpeed stableSpeed;
    DededeSpeed brake;
};
struct DededeGravityEnergy : DededeSpeedEnergy {
    float speed;
    float acceleration;
    float terminalSpeed;
};

// Compile-time selectors distinguish the embedded energy slots without a
// runtime lookup; their offsets are relative to the kinetic-energy storage.
template <class T, int Offset> struct DededeEnergySlot {};
template <class T, int Offset>
inline T* getDededeEnergy(unsigned char* storage, const DededeEnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
}

extern "C" {
extern const float lbl_117_rodata_C8;
DededeSpeed fn_27_899AC(const DededeSpeed*, const DededeSpeed*);
void fn_117_15C24(const DededeSpeed*, const DededeSpeed*, DededeSpeed*);
void fn_117_D134(DededeSpeed*, const DededeSpeed*);
}

inline DededeSpeed addSpeed(const DededeSpeed& lhs, const DededeSpeed& rhs) {
    DededeSpeed result;
    fn_117_15C24(&lhs, &rhs, &result);
    return result;
}

inline void copySpeed(Vec2f& destination, const DededeSpeed& speed) {
    Vec2f::copy(destination, *reinterpret_cast<const Vec2f*>(&speed));
}
inline const DededeSpeed* speedWords(const Vec2f& speed) {
    return reinterpret_cast<const DededeSpeed*>(&speed);
}

inline void setDamageSpeed(DededeDamageEnergy* energy, const DededeSpeed& speed) {
    fn_117_D134(&energy->speed, &speed);
}

extern "C" void fn_117_15728(int kind, const DededeSpeed* input,
                             unsigned char* energies, soModuleAccesser* accesser) {
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    switch (kind) {
    case 0: {
        DededeSpeed speed = {lbl_117_rodata_C8, lbl_117_rodata_C8};
        switch (accesser->getSituationModule().getKind()) {
        case 0: {
            DededeGroundSpeedView* ground = reinterpret_cast<DededeGroundSpeedView*>(&accesser->getGroundModule());
            Vec2f normal;
            copySpeed(normal, ground->getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0));
            speed = fn_27_899AC(speedWords(Vec2f(input->x, lbl_117_rodata_C8)), speedWords(normal));
            break;
        }
        }
        if (lbl_117_rodata_C8 != speed.x || lbl_117_rodata_C8 != speed.y) {
            DededeSpeed* stopSpeed = getDededeEnergy(energies, DededeEnergySlot<DededeSpeed, 0xb8>());
            fn_117_15C24(stopSpeed, &speed, stopSpeed);
            *reinterpret_cast<float*>(energies + 0xd4) += lbl_117_rodata_C8;
            energies[0xb5] |= 0x80;
        }
        break;
    }
    case 1: {
        DededeSpeed speed = {lbl_117_rodata_C8, lbl_117_rodata_C8};
        DededeSpeed accel = {lbl_117_rodata_C8, lbl_117_rodata_C8};
        switch (accesser->getSituationModule().getKind()) {
        case 0:
            speed.x = input->x;
            accel.x = params->getParamFloat(accesser, 0xfae, 0);
            break;
        case 2:
        case 3:
            speed.x = input->x;
            speed.y += input->y;
            accel.x = params->getParamFloat(accesser, 0xfae, 0);
            break;
        }
        if (lbl_117_rodata_C8 != speed.x || lbl_117_rodata_C8 != speed.y) {
            DededeSpeed* controlSpeed = getDededeEnergy(energies, DededeEnergySlot<DededeSpeed, 0x120>());
            fn_117_15C24(controlSpeed, &speed, controlSpeed);
            *reinterpret_cast<float*>(energies + 0x128) = params->getParamFloat(accesser, 0xfb5, 0);
            fn_117_D134(reinterpret_cast<DededeSpeed*>(energies + 0x10c), &accel);
            energies[0xf1] |= 0x80;
        }
        break;
    }
    case 2: {
        DededeSpeed speed = {lbl_117_rodata_C8, lbl_117_rodata_C8};
        switch (accesser->getSituationModule().getKind()) {
        case 0:
            speed.x = input->x;
            break;
        case 2:
        case 3:
            speed.x = input->x;
            speed.y = input->y;
            break;
        }
        if (lbl_117_rodata_C8 != speed.x) {
            DededeDamageEnergy* damage = getDededeEnergy(energies, DededeEnergySlot<DededeDamageEnergy, 0x70>());
            setDamageSpeed(damage, addSpeed(damage->getSpeed(), speed));
            fn_117_D134(&damage->stableSpeed, speedWords(Vec2f(lbl_117_rodata_C8, lbl_117_rodata_C8)));
            if (accesser->getSituationModule().getKind() == 2) {
                fn_117_D134(&damage->brake, speedWords(Vec2f(params->getParamFloat(accesser, 0xfaf, 0), lbl_117_rodata_C8)));
            } else {
                fn_117_D134(&damage->brake, speedWords(Vec2f(params->getParamFloat(accesser, 0xfae, 0), lbl_117_rodata_C8)));
            }
            damage->enable();
        }
        if (lbl_117_rodata_C8 != speed.y) {
            DededeGravityEnergy* gravity = getDededeEnergy(energies, DededeEnergySlot<DededeGravityEnergy, 0x50>());
            gravity->speed = speed.y + gravity->getSpeed().y;
            if (accesser->getKineticModule().getEnergy(1)->isEnable()) {
                gravity->acceleration = -params->getParamFloat(accesser, 0xfb1, 0);
                gravity->terminalSpeed = params->getParamFloat(accesser, 0xfb2, 0);
                gravity->enable();
            }
        }
        break;
    }
    }
}
