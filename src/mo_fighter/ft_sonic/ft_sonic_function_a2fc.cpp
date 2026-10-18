#pragma force_active on
class soModuleAccesser;

struct SonicSpeed {
    float x;
    float y;
};

class SonicEnergyView {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual void unused();
    virtual SonicSpeed getSpeed();
};

struct SonicVector {
    float m_x;
    float m_y;
    float m_z;
};

extern "C" const float lbl_123_rodata_8;

extern "C" void fn_123_A2FC(SonicVector* result, SonicEnergyView* energy) {
    SonicSpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_123_rodata_8;
}
