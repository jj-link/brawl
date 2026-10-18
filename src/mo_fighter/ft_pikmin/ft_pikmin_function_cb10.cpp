#pragma force_active on
struct Vec3f {
    float m_x;
    float m_y;
    float m_z;
};

struct PikminEnergySpeed {
    float x;
    float y;
};

class PikminEnergyView {
public:
    virtual void updateEnergy();
    virtual PikminEnergySpeed getSpeed();
    virtual PikminEnergySpeed getSpeedIntoRegisters();
};

extern "C" const float lbl_113_rodata_C;

extern "C" void fn_113_CB10(Vec3f* result, PikminEnergyView* energy) {
    PikminEnergySpeed speed = energy->getSpeedIntoRegisters();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_113_rodata_C;
}
