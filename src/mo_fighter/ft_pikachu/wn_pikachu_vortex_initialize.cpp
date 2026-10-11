#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

// Prefix passed to the common weapon activation routine. Reserved flag bits
// remain unspecified, as in the original descriptor constructor.
struct VortexActivationDescriptor {
    int taskId;
    int identifier0, identifier1, identifier2;
    int ownerId, teamId;
    int field18, field1C;
    Vec3f position;
    float field2C;
    int parameter, field34, field38, field3C, field40, field44, field48;
    u8 active : 1;
    u8 field4C1 : 3;
    u8 field4C4 : 1;
    u8 field4C5 : 3;
    u8 field4D0 : 2;
    u8 reserved : 6;

    inline VortexActivationDescriptor(int task, int value, const Vec3f& pos, float zero)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), field2C(zero),
          parameter(value), field34(0), field38(2), field3C(0x80), field40(0),
          field44(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};

struct VortexInitializationOwner {
    char prefix[0x60];
    soModuleAccesser* accesser;
};
struct VortexEnergyEnableView {
    char prefix[5];
    u8 flags;
};
extern "C" const float lbl_98_rodata_E8;
extern "C" void fn_27_1D8370(void*, const VortexActivationDescriptor*);
extern "C" void fn_98_1B9EC(soModuleAccesser*, int);
extern "C" void fn_98_1B904(soModuleAccesser*, int, int);

static inline void initializeWork(soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    work->setInt(0, 0x10000005);
    work->setInt(0, 0x10000006);
    fn_98_1B9EC(accesser, 0x10000006);
    fn_98_1B904(accesser, 0x10000005, 0xe80002);
    work->offFlag(0x12000004);
    work->offFlag(0x12000005);
    work->onFlag(0x12000000);
    accesser->getCameraModule().setWhole(true);
}

static inline void initializeSpeed(soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    float limit;
    const float speed = soValueAccesser::getConstantFloat(accesser, 0xfa3, 0);
    limit = soValueAccesser::getConstantFloat(accesser, 0xfa2, 0);
    work->setFloat(speed, 0x11000003);
    work->setFloat(speed, 0x11000004);
    work->setFloat(limit, 0x11000005);
}

static inline void initializeKinetic(soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soKineticModule* kinetic = &accesser->getKineticModule();
    kinetic->unableEnergyAll();
    kinetic->clearSpeedAll();
    reinterpret_cast<VortexEnergyEnableView*>(kinetic->getEnergy(0))->flags |= 0x80;
    work->setFloat(lbl_98_rodata_E8, 0x11000001);
    work->setFloat(lbl_98_rodata_E8, 0x11000002);
    accesser->getStatusModule().changeStatusForce(0, accesser);
}

static inline void initializeModules(soModuleAccesser* accesser) {
    initializeWork(accesser);
    initializeSpeed(accesser);
    initializeKinetic(accesser);
}

extern "C" void fn_98_1B334(VortexInitializationOwner* owner, int taskId, int, int parameter, const Vec3f* position) {
    VortexActivationDescriptor descriptor(taskId, parameter, *position, lbl_98_rodata_E8);
    fn_27_1D8370(owner, &descriptor);
    initializeModules(owner->accesser);
}
