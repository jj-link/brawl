#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

struct Vec3f {
    float m_x;
    float m_y;
    float m_z;
};

class PitSpeedEnergyView {
public:
    virtual void updateEnergy();
    virtual void unknown();
    virtual Vec2f getSpeed();
};

extern "C" const float lbl_112_rodata_8;

extern "C" void fn_112_A8C0(Vec3f* result, PitSpeedEnergyView* energy) {
    Vec2f speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_112_rodata_8;
}
