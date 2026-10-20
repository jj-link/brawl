#pragma force_active on
extern "C" void* __memcpy(void*, const void*, unsigned long);
extern "C" const float lbl_27_rodata_27E8;

struct Vec2f {
    float m_x, m_y;

    static void copy(Vec2f& dest, const Vec2f& src) {
        __memcpy(&dest, &src, sizeof(Vec2f));
    }
};

struct AttributeFlag {
    unsigned short mask;
};

class KineticModule {
public:
    virtual bool isNull() const;
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy();
    virtual void eraseEnergy();
    virtual void eraseEnergyAll();
    virtual void getEnergy();
    virtual void isContain();
    virtual void updateEnergy();
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual Vec2f getSumSpeed(const AttributeFlag&);
};

struct ModuleEnumeration {
    char padding[0x7c];
    KineticModule* kineticModule;
};

struct ModuleAccesser {
    char padding[0xd8];
    ModuleEnumeration* enumeration;
};

extern "C" bool fn_27_1DC790(void*, ModuleAccesser* accesser) {
    AttributeFlag flag;
    flag.mask = 2;

    Vec2f speed;
    Vec2f::copy(speed, accesser->enumeration->kineticModule->getSumSpeed(flag));

    float xSq = speed.m_x * speed.m_x;
    float ySq = speed.m_y * speed.m_y;
    return xSq + ySq > lbl_27_rodata_27E8;
}
