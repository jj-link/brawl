#pragma force_active on
class soModuleAccesser;

struct WolfSpeed {
    float x;
    float y;
};

class WolfEnergyView {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual void unknown();
    virtual WolfSpeed getSpeed();
};

struct Vec3f {
    float m_x;
    float m_y;
    float m_z;
};

extern "C" const float lbl_125_rodata_8;

extern "C" void fn_125_B100(Vec3f* result, WolfEnergyView* energy) {
    WolfSpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_125_rodata_8;
}
