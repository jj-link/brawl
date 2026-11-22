#include <ft/ft_common_data_accesser.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern "C" {
extern char lbl_104_data_72B4[];
extern char lbl_104_data_7138[];
extern char lbl_104_data_2404[];
extern const float lbl_104_rodata_150;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* __memcpy(void*, const void*, unsigned long);
}

class KineticSpeedView {
public:
    virtual void v0();
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(void*, int, short, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual void* getEnergy(int);
    virtual bool isContain(int);
    virtual void updateEnergy(void*, short);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual Vec2f getSumSpeed(const short&);
};

class ModuleA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool check(void*);
};

struct Enumeration {
    unsigned char pad0[0x14];
    ModuleA* a;
    unsigned char pad1[0x7c - 0x18];
    KineticSpeedView* k;
};

struct Accesser {
    unsigned char pad0[0xd8];
    Enumeration* e;
};

inline ModuleA* getModule(Enumeration* e, KineticSpeedView*& kinetic) {
    ModuleA* a = e->a;
    kinetic = e->k;
    return a;
}

extern "C" void fn_104_1EF50(void*, Accesser* accesser) {
    Enumeration* e = accesser->e;
    KineticSpeedView* kinetic;
    if (getModule(e, kinetic)->check(e)) {
        float* scale = *reinterpret_cast<float**>(
            reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)0xE)) + 0x84);
        short flag = -1;
        Vec2f speed;
        __memcpy(&speed, &kinetic->getSumSpeed(flag), 8);
        kinetic->clearSpeedAll();
        char* energy1 = static_cast<char*>(
            __dynamic_cast(kinetic->getEnergy(1), 0, lbl_104_data_72B4, lbl_104_data_2404, 1));
        *reinterpret_cast<float*>(energy1 + 0xc) = *scale;
        energy1[5] |= 0x80;
        char* energy2 = static_cast<char*>(
            __dynamic_cast(kinetic->getEnergy(3), 0, lbl_104_data_7138, lbl_104_data_2404, 1));
        *reinterpret_cast<Vec2f*>(energy2 + 0x8) = Vec2f(speed.m_x, lbl_104_rodata_150);
        energy2[5] |= 0x80;
    }
}
