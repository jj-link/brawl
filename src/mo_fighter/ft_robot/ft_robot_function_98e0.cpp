#include <so/so_null.h>
#pragma force_active on

class soModuleAccesser;

struct RobotPosition {
    float m_x;
    float m_y;
};

class RobotPositionEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual RobotPosition getPosition();
};

struct RobotVector3 {
    float m_x;
    float m_y;
    float m_z;
};

extern "C" const float lbl_120_rodata_8;

extern "C" void fn_120_98E0(RobotVector3* result, RobotPositionEnergyView* energy) {
    RobotPosition position = energy->getPosition();
    result->m_x = position.m_x;
    result->m_y = position.m_y;
    result->m_z = lbl_120_rodata_8;
}
