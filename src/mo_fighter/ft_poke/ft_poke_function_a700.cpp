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

class EnergyBase {
public:
    virtual void v0();
    virtual void v1();
    virtual Vec2f getSpeed();
};

extern "C" {
extern const float lbl_116_rodata_8;

void fn_116_A700(Vec3f* result, EnergyBase* energy) {
    Vec2f speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_116_rodata_8;
}
}
