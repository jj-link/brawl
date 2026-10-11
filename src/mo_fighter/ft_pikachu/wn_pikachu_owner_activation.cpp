#include <wn/weapon.h>

union PikachuActivationVector {
    struct { float x, y, z; };
    float coordinates[3];
};
struct PikachuActivationDescriptor {
    unsigned int founder;
    unsigned int identifiers[3];
    int indices[2];
    unsigned int groups[2];
    PikachuActivationVector position;
    float rotation;
    int variant;
    unsigned int unknown34;
    unsigned int category;
    unsigned int mask;
    unsigned int unknown40;
    unsigned int filter;
    unsigned int unknown48;
    unsigned char active : 1;
    unsigned char middleFlags : 3;
    unsigned char collision : 1;
    unsigned char lowFlags : 3;
    unsigned char upperFlags : 2;
    unsigned char remainingFlags : 6;
};
static_assert(sizeof(PikachuActivationDescriptor) == 0x50, "Activation descriptor layout");

// The module enumeration leaves this manager opaque. Only its query slot is
// used here; preceding virtual entries preserve the original interface layout.
class PikachuGenerationInterface {
    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2C() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3C() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4C() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5C() = 0;
public:
    virtual int queryKindValue(int kind) = 0;
};

extern "C" {
extern const float lbl_98_rodata_D0;
const float* fn_98_9540(void*);
void fn_98_14584(PikachuActivationVector*, const PikachuActivationVector*);
void fn_27_1D8370(Weapon*, const PikachuActivationDescriptor*);
void fn_98_181C0(Weapon*);
void fn_98_17CC8(void*, void*);

void fn_98_17838(Weapon* owner, unsigned int founder, int variant,
                 const PikachuActivationVector* input, int valueE, void* secondary) {
    const float* parameters = fn_98_9540(owner);
    PikachuActivationVector adjusted;
    fn_98_14584(&adjusted, input);
    adjusted.y += parameters[0];
    PikachuActivationVector position;
    fn_98_14584(&position, &adjusted);
    PikachuActivationDescriptor descriptor;
    descriptor.founder = founder;
    descriptor.identifiers[0] = 0xffff;
    descriptor.identifiers[1] = 0xffff;
    descriptor.identifiers[2] = 0xffff;
    descriptor.indices[0] = -1;
    descriptor.indices[1] = -1;
    descriptor.groups[0] = 0;
    descriptor.groups[1] = 0;
    descriptor.position = position;
    descriptor.rotation = lbl_98_rodata_D0;
    descriptor.variant = variant;
    descriptor.unknown34 = 0;
    descriptor.category = 2;
    descriptor.mask = 0x80;
    descriptor.unknown40 = 0;
    descriptor.filter = 0x35f;
    descriptor.unknown48 = 0;
    descriptor.active = 1;
    descriptor.middleFlags = 0;
    descriptor.collision = 1;
    descriptor.lowFlags = 0;
    descriptor.upperFlags = 0;
    fn_27_1D8370(owner, &descriptor);
    soModuleAccesser* accesser = owner->m_moduleAccesser;
    accesser->getStatusModule().changeStatusForce(0, accesser);
    const soModuleEnumeration* modules = owner->m_moduleAccesser->m_enumerationStart;
    soWorkManageModule* work = modules->m_workManageModule;
    PikachuGenerationInterface* generation = static_cast<PikachuGenerationInterface*>(
        modules->m_generateArticleManageModule);
    work->setFloat(adjusted.x, 0x11000001);
    work->setFloat(adjusted.y, 0x11000002);
    work->setFloat(adjusted.z, 0x11000003);
    work->setInt(variant, 0x1000000c);
    work->setInt(valueE, 0x1000000e);
    fn_98_181C0(owner);
    fn_98_17CC8(owner, secondary);
    work->onFlag(0x12000000);
    work->offFlag(0x12000004);
    int count = generation->queryKindValue(0);
    work->setInt(count, 0x10000007);
    work->setInt(count, 0x10000008);
    work->setInt(0, 0x10000009);
    work->setInt(100, 0x1000000b);
}
}
