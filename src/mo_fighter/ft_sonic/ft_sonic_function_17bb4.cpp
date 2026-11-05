#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#pragma force_active on

namespace {
struct SonicSummedSpeed {
    float x;
    float y;
};

class SonicKineticSpeedView : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(soKineticEnergy*, int, soKineticEnergy::AttributeFlag, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int);
    virtual bool isContain(int);
    virtual void updateEnergy(soModuleAccesser*, soKineticEnergy::AttributeFlag);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual SonicSummedSpeed getSumSpeed(const unsigned short&);
};

struct SonicRangeConfiguration {
    const void* vtable;
    unsigned char baseState[4];
    SonicSummedSpeed ranges[5];
    bool firstFlag;
    bool secondFlag;
    bool initialized;
};

struct SonicEnergyBlock {
    char pad0[0x14];
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    char pad17;
    Vec2f unk18;
    Vec2f unk20;
    Vec2f unk28;
    Vec2f unk30;
    Vec2f unk38;
    bool unk40;
    bool unk41;
    bool unk42;
};

struct LocalFlag {
    bool value;
};
}

extern "C" {
extern const unsigned char lbl_27_data_13608[];
extern const float lbl_123_rodata_98;
extern const float lbl_123_rodata_9C;
void* fn_123_396C(void*, short);
void fn_123_9574(Vec2f&, const Vec2f&);
Vec2f* fn_123_13A10(Vec2f*, float, float);
}

extern "C" void fn_123_17BB4(SonicEnergyBlock* energy, soModuleAccesser* accesser) {
    unsigned short attributes = 1;
    Vec2f speed;
    SonicSummedSpeed summed = reinterpret_cast<SonicKineticSpeedView*>(&accesser->getKineticModule())->getSumSpeed(attributes);
    __memcpy(&speed, &summed, sizeof(speed));
    accesser->getKineticModule().unableEnergyAll();
    LocalFlag unused = {false};
    Vec2f e, d, c, b, a;
    a.m_x = lbl_123_rodata_98;
    a.m_y = lbl_123_rodata_98;
    b.m_x = lbl_123_rodata_9C;
    b.m_y = lbl_123_rodata_9C;
    c.m_x = lbl_123_rodata_98;
    c.m_y = lbl_123_rodata_98;
    d.m_x = lbl_123_rodata_9C;
    d.m_y = lbl_123_rodata_9C;
    e.m_x = lbl_123_rodata_9C;
    e.m_y = lbl_123_rodata_9C;
    {
        SonicRangeConfiguration cfg;
        cfg.baseState[0] = 0;
        cfg.baseState[1] |= 0x80;
        cfg.baseState[2] = 0;
        cfg.vtable = lbl_27_data_13608;
        __memcpy(&cfg.ranges[0], &e, sizeof(Vec2f));
        __memcpy(&cfg.ranges[1], &d, sizeof(Vec2f));
        __memcpy(&cfg.ranges[2], &c, sizeof(Vec2f));
        __memcpy(&cfg.ranges[3], &b, sizeof(Vec2f));
        __memcpy(&cfg.ranges[4], &a, sizeof(Vec2f));
        cfg.firstFlag = false;
        cfg.secondFlag = false;
        cfg.initialized = true;
        energy->unk14 = cfg.baseState[0];
        energy->unk15 = cfg.baseState[1];
        energy->unk16 = cfg.baseState[2];
        __memcpy(&energy->unk18, &cfg.ranges[0], sizeof(Vec2f));
        __memcpy(&energy->unk20, &cfg.ranges[1], sizeof(Vec2f));
        __memcpy(&energy->unk28, &cfg.ranges[2], sizeof(Vec2f));
        __memcpy(&energy->unk30, &cfg.ranges[3], sizeof(Vec2f));
        __memcpy(&energy->unk38, &cfg.ranges[4], sizeof(Vec2f));
        energy->unk40 = cfg.firstFlag;
        energy->unk41 = cfg.secondFlag;
        energy->unk42 = cfg.initialized;
        fn_123_396C(&cfg, 0);
    }
    if (accesser->getKineticModule().getKineticType() == 0x20 ||
        accesser->getKineticModule().getKineticType() == 0x21) {
        fn_123_9574(energy->unk18, speed);
    }
    Vec2f v1;
    fn_123_13A10(&v1, soValueAccesser::getConstantFloat(accesser, 0xFA1, 0),
                 soValueAccesser::getConstantFloat(accesser, 0xFA3, 0));
    fn_123_9574(energy->unk38, v1);
    Vec2f v2;
    fn_123_13A10(&v2, soValueAccesser::getConstantFloat(accesser, 0xFA1, 0),
                 soValueAccesser::getConstantFloat(accesser, 0xFA3, 0));
    fn_123_9574(energy->unk28, v2);
    energy->unk15 |= 0x80;
}
