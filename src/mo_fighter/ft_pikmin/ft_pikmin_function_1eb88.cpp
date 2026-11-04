#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
extern const float lbl_113_rodata_90;
void fn_113_BC00(Vec2f*, const Vec2f*);
}

struct Flag {
    unsigned char value;
};

struct AttrFlag {
    short mask;
    AttrFlag(short m) : mask(m) {}
};

class PikminKineticView : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(void*, int, const AttrFlag&, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual void* getEnergy(int);
    virtual bool isContain(int);
    virtual void updateEnergy(soModuleAccesser*, const AttrFlag&);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual Vec2f getSumSpeed(const AttrFlag&);
};

struct PikminEnergy {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void activate();

    unsigned char m_isNull;
    unsigned char m_flags;
    unsigned char m_pad[2];
    Vec2f speed;
    Vec2f accel;
    Vec2f p18;
    Vec2f p20;
    Vec2f p28;
    unsigned char active;
};

inline PikminKineticView& kinetic(soModuleAccesser* accesser) {
    return reinterpret_cast<PikminKineticView&>(accesser->getKineticModule());
}

extern "C" void fn_113_1EB88(void*, unsigned char* energies, soModuleAccesser* accesser) {
    PikminEnergy* stop;
    Vec2f speed;
    Vec2f::copy(speed, kinetic(accesser).getSumSpeed(AttrFlag(1)));
    kinetic(accesser).unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    Flag flag = {0};
    stop = reinterpret_cast<PikminEnergy*>(energies + 0x10);
    stop->active = 1;
    stop->activate();
    fn_113_BC00(&stop->speed, &speed);
    fn_113_BC00(&stop->p18, &Vec2f(params->getParamFloat(accesser, 0xFC7, 0), lbl_113_rodata_90));
    fn_113_BC00(&stop->p20, &Vec2f(params->getParamFloat(accesser, 0xFC8, 0), lbl_113_rodata_90));
    fn_113_BC00(&stop->p28, &Vec2f(params->getParamFloat(accesser, 0xFC9, 0), lbl_113_rodata_90));
    float a = params->getParamFloat(accesser, 0xFC6, 0) + params->getParamFloat(accesser, 0xFCF, 0);
    float facing = accesser->getPostureModule().getLr();
    if (facing > lbl_113_rodata_90) {
        a = -a;
    }
    fn_113_BC00(&stop->accel, &Vec2f(a, lbl_113_rodata_90));
    reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
}
