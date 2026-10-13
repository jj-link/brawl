#include <so/so_module_accesser.h>

struct NessFinalActivationDescriptor {
    unsigned int taskId;
    int identifier0, identifier1, identifier2;
    int ownerId, teamId;
    int field18, field1C;
    Vec3f position;
    float facing;
    int parameter, field34, situation, status, field40, motion, field48;
    u8 active : 1;
    u8 linked : 1;
    u8 field4C2 : 2;
    u8 field4C4 : 1;
    u8 field4C5 : 3;
    u8 field4D0 : 2;
    u8 reserved : 6;

    inline NessFinalActivationDescriptor(int owner, unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(owner), identifier1(owner), identifier2(owner),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), linked(1), field4C2(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};
struct NessFinalInitializationOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
// The common module enumeration leaves the physics interface opaque. Describe
// only the entries used here, retaining the intervening original table slots.
struct NessFinalPhysics;
class NessFinalPhysics : private soNull, public soNullable {
public:
    virtual ~NessFinalPhysics();
    virtual void initialize(u32, int, int, int, int, int, bool, int) = 0;
private:
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
    virtual void setMode(int) = 0;
private:
    virtual void slot_64() = 0;
    virtual void slot_68() = 0;
    virtual void slot_6C() = 0;
    virtual void slot_70() = 0;
    virtual void slot_74() = 0;
    virtual void slot_78() = 0;
    virtual void slot_7C() = 0;
    virtual void slot_80() = 0;
    virtual void slot_84() = 0;
    virtual void slot_88() = 0;
    virtual void slot_8C() = 0;
    virtual void slot_90() = 0;
    virtual void slot_94() = 0;
    virtual void slot_98() = 0;
    virtual void slot_9C() = 0;
    virtual void slot_A0() = 0;
    virtual void slot_A4() = 0;
    virtual void slot_A8() = 0;
    virtual void slot_AC() = 0;
    virtual void slot_B0() = 0;
    virtual void slot_B4() = 0;
    virtual void slot_B8() = 0;
    virtual void slot_BC() = 0;
    virtual void slot_C0() = 0;
    virtual void slot_C4() = 0;
    virtual void slot_C8() = 0;
    virtual void slot_CC() = 0;
    virtual void slot_D0() = 0;
    virtual void slot_D4() = 0;
    virtual void slot_D8() = 0;
public:
    virtual void setScale(float) = 0;
};
inline NessFinalPhysics* getFinalPhysics(const soModuleAccesser* accesser) {
    return static_cast<NessFinalPhysics*>(accesser->m_enumerationStart->m_physicsModule);
}
extern "C" {
extern const float lbl_101_rodata_150[2] = { 0.0f, 20.0f };
extern int lbl_101_data_B5D0 = -1;
Vec3f* fn_101_1303C(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const NessFinalActivationDescriptor*);

void fn_101_20830(NessFinalInitializationOwner* object, unsigned int taskId, int ownerId,
                  int parameter, bool enabled) {
    Vec3f position;
    fn_101_1303C(&position, lbl_101_rodata_150[0], lbl_101_rodata_150[0], lbl_101_rodata_150[0]);
    NessFinalActivationDescriptor descriptor(ownerId, taskId, parameter, position, lbl_101_rodata_150[0]);
    fn_27_1D8370(object, &descriptor);
    NessFinalPhysics* physics = getFinalPhysics(object->accesser);
    soResourceModule* resourceModule = &object->accesser->getResourceModule();
    physics->initialize(resourceModule->getResourceIdAccesser()->getBinResId(),
                        0, lbl_101_data_B5D0, 0, lbl_101_data_B5D0, 0, false, -1);
    physics->setScale(object->accesser->getPostureModule().getScale());
    physics->setMode(2);
    float facing = object->accesser->getLinkModule().getParentLr(3);
    object->accesser->getPostureModule().setLr(facing);
    object->accesser->getWorkManageModule().setFlag(enabled, 0x22000000);
}
}
