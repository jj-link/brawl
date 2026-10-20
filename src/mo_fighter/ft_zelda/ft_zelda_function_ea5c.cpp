#pragma force_active on
#pragma always_inline on
#pragma inline_depth(8)

struct Vec2f {
    float m_x, m_y;
};

struct ZeldaSpeed {
    float x, y;
};

class Kinetic {
public:
    virtual bool isNull() const;
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy();
    virtual void eraseEnergy();
    virtual void eraseEnergyAll();
    virtual void* getEnergy(int);
    virtual void isContain();
    virtual void updateEnergy();
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual ZeldaSpeed getSumSpeed(const short&);
    virtual void getSumSpeed3f();
    virtual void getSumRotation();
    virtual void setConsiderGroundFriction();
    virtual void mulSpeed();
    virtual void mulAccel();
    virtual void reflectSpeed();
    virtual void reflectAccel();
    virtual void changeKinetic(int, void*);
};

class Situation {
public:
    virtual ~Situation();
    virtual void activate();
    virtual void deactivate();
    virtual int getKind();
};

class Visibility {
public:
    virtual void activate();
    virtual void setData();
    virtual void set();
    virtual void setStatusDefault();
    virtual void setDefaultAll();
    virtual void update();
    virtual void hideAll();
    virtual void setWhole(unsigned char);
};

struct Enumeration {
    char pad0[0x14];
    Situation* situation;
    char pad1[0x40];
    Visibility* visibility;
    char pad2[0x20];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Enumeration* modules;
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern const char lbl_104_data_7138[];
extern const char lbl_104_data_2404[];
extern const char lbl_104_data_72B4[];
extern const float lbl_104_rodata_50;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_104_CDE4(Vec2f*, const Vec2f*);
void* __memcpy(void*, const void*, unsigned long);
}

#pragma always_inline on
#pragma inline_depth(8)

extern "C" void fn_104_EA5C(void*, Accesser* accesser) {
    Vec2f speed;
    Kinetic* kinetic = accesser->modules->kinetic;
    Situation* situation = accesser->modules->situation;
    char* params = *(char**)((char*)
        getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 13) + 0x84);

    short mask = -1;
    ZeldaSpeed sum = kinetic->getSumSpeed(mask);
    __memcpy(&speed, &sum, sizeof(speed));

    kinetic->clearSpeedAll();

    signed char* stop = (signed char*)__dynamic_cast(
        kinetic->getEnergy(3), 0,
        lbl_104_data_7138, lbl_104_data_2404, 1);

    signed char* gravity = (signed char*)__dynamic_cast(
        kinetic->getEnergy(1), 0,
        lbl_104_data_72B4, lbl_104_data_2404, 1);

    if (situation->getKind() == 0) {
        kinetic->changeKinetic(6, accesser);
        speed.m_x *= *(float*)(params + 0x2c);
        speed.m_y = lbl_104_rodata_50;
        fn_104_CDE4((Vec2f*)(stop + 8), &speed);
        stop[5] |= 0x80;
    } else {
        kinetic->changeKinetic(11, accesser);
        speed.m_x *= *(float*)(params + 0x2c);
        speed.m_y *= *(float*)(params + 0x2c);
        fn_104_CDE4((Vec2f*)(stop + 8), &speed);
        stop[5] |= 0x80;
        gravity[5] &= ~0x80;
    }

    accesser->modules->visibility->setWhole(1);
}
