#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

#pragma options align=mac68k4byte
struct VortexProcess { void* vtable; };
struct VortexTypeInfo { const char* name; const void* bases; };
struct VortexBaseInfo { const void* type; int adjustment; const void* end; };
struct VortexRegistration { void* next; void* object; void* destructor; };
typedef void (*VortexMethod)();
struct VortexVtable { const VortexTypeInfo* type; unsigned long reserved; VortexMethod methods[14]; };
#pragma options align=reset

// The normal energy's speed immediately follows its eight-byte base.
struct VortexEnergySpeed { soKineticEnergy base; Vec2f speed; };
static_assert(sizeof(VortexProcess) == 4, "Status object layout");
static_assert(sizeof(VortexTypeInfo) == 8, "RTTI layout");
static_assert(sizeof(VortexRegistration) == 12, "Destructor record layout");
static_assert(sizeof(VortexVtable) == 64, "Status vtable layout");

extern "C" {
extern const char lbl_98_data_723C[], lbl_98_data_24B0[], lbl_98_data_600[];
extern const char lbl_98_data_2F88[], lbl_98_data_76B8[];
extern VortexVtable lbl_98_data_9850, lbl_98_data_98D0, lbl_98_data_994C;
extern VortexTypeInfo lbl_98_data_98C8, lbl_98_data_9944, lbl_98_data_99C0;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void __register_global_object(void*, void*, void*);
Vec3f* fn_98_14584(Vec3f*, const Vec3f*);
float fn_98_11B2C(float, float, float);
void fn_98_98B8(void*, soCameraModule*);
void fn_98_1B878(soModuleAccesser*, int);
void fn_98_1BCB8(soModuleAccesser*);
void fn_98_1BD54(soModuleAccesser*);
void fn_98_1C064(soModuleAccesser*);
void fn_98_1C10C(soModuleAccesser*);
VortexProcess* fn_98_1C2C4(VortexProcess*);
VortexProcess* fn_98_1C2D4(VortexProcess*);
VortexProcess* fn_98_1C2E4(VortexProcess*);
void fn_98_10060(); void fn_98_FFDC(); void fn_98_FF94(); void fn_98_FF90();
void fn_98_FF8C(); void fn_98_FF84(); void fn_98_FF7C(); void fn_98_FF78();
void fn_98_FF70(); void fn_98_FF6C(); void fn_98_FF64();
}

extern "C" void fn_98_1BBC8(VortexProcess*, soModuleAccesser* accesser) {
    fn_98_1BCB8(accesser);
    fn_98_1BD54(accesser);
    fn_98_1C064(accesser);
}
extern "C" void fn_98_1BC08(VortexProcess*, soModuleAccesser* accesser) { fn_98_1C10C(accesser); }
extern "C" void fn_98_1BC10(VortexProcess*, soModuleAccesser* accesser) {
    fn_98_1BCB8(accesser);
    fn_98_1BD54(accesser);
    fn_98_1C064(accesser);
}
extern "C" void fn_98_1BC50(VortexProcess*, soModuleAccesser* accesser) { fn_98_1C10C(accesser); }
extern "C" void fn_98_1BC58(VortexProcess*, soModuleAccesser* accesser) { fn_98_1B878(accesser, 1); }
extern "C" void fn_98_1BC64(VortexProcess*, soModuleAccesser* accesser) {
    fn_98_1BCB8(accesser);
    fn_98_1BD54(accesser);
    fn_98_1C064(accesser);
}
extern "C" void fn_98_1BCA4(VortexProcess*, soModuleAccesser* accesser) { fn_98_1C10C(accesser); }
extern "C" void fn_98_1BCAC(VortexProcess*, soModuleAccesser* accesser) { fn_98_1B878(accesser, 0); }

// Refresh additive and speed-dependent attack power from the weapon parameters.
extern "C" void fn_98_1BCB8(soModuleAccesser* accesser) {
    soCollisionAttackModule& attack = accesser->getCollisionAttackModule();
    const float powerAdd = soValueAccesser::getConstantFloat(accesser, 0xfa1, 0);
    const float powerSpeed = soValueAccesser::getConstantFloat(accesser, 0xfa0, 0);
    attack.setPowerAddStatus(powerAdd);
    attack.setPowerSpeedStatus(powerSpeed);
}

// Steer toward the linked fighter's node, then apply the normal energy speed.
extern "C" void fn_98_1BD54(soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    soPostureModule& posture = accesser->getPostureModule();
    Vec3f position;
    Vec3f target;
    Vec3f rawPosition = posture.getPos();
    fn_98_14584(&position, &rawPosition);
    Vec3f rawTarget = accesser->getLinkModule().getParentModelNodeGlobalPosition(3, 5, true);
    fn_98_14584(&target, &rawTarget);
    Vec2f speed;
    speed.m_x = work.getFloat(0x11000001);
    speed.m_y = work.getFloat(0x11000002);
    float limit = work.getFloat(0x11000004);
    const float acceleration = work.getFloat(0x11000005);
    if (target.m_x < position.m_x) speed.m_x -= acceleration;
    if (position.m_x < target.m_x) speed.m_x += acceleration;
    if (target.m_y > position.m_y) speed.m_y += acceleration;
    if (target.m_y < position.m_y) speed.m_y -= acceleration;
    speed.m_x = fn_98_11B2C(speed.m_x, -limit, limit);
    speed.m_y = fn_98_11B2C(speed.m_y, -limit, limit);
    work.setFloat(speed.m_x, 0x11000001);
    work.setFloat(speed.m_y, 0x11000002);
    VortexEnergySpeed* energy = static_cast<VortexEnergySpeed*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(0), 0, lbl_98_data_723C, lbl_98_data_24B0, 1));
    Vec2f appliedSpeed = speed;
    appliedSpeed.m_y *= soValueAccesser::getConstantFloat(accesser, 0xfa7, 0);
    energy->speed = appliedSpeed;

    // Reacquire work after the kinetic and parameter callbacks.
    soWorkManageModule& currentWork = accesser->getWorkManageModule();
    const float currentLimit = currentWork.getFloat(0x11000004);
    limit = currentWork.getFloat(0x11000003);
    if (currentLimit != limit) {
        const float step = soValueAccesser::getConstantFloat(accesser, 0xfa5, 0);
        float nextLimit;
        if (currentLimit > limit) {
            nextLimit = currentLimit - step;
            if (nextLimit < limit) nextLimit = limit;
        } else {
            nextLimit = currentLimit + step;
            if (nextLimit > limit) nextLimit = limit;
        }
        currentWork.setFloat(nextLimit, 0x11000004);
    }
}
extern "C" void fn_98_1C064(soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    if (work.isFlag(0x12000005)) work.onFlag(0x12000004);
    else work.offFlag(0x12000004);
    work.offFlag(0x12000005);
}
extern "C" void fn_98_1C10C(soModuleAccesser* accesser) {
    StageObject* parent = accesser->getLinkModule().getParent(3);
    if (parent) {
        void* fighter = __dynamic_cast(parent, 0x3c, lbl_98_data_600, lbl_98_data_2F88, 1);
        fn_98_98B8(fighter, &accesser->getCameraModule());
    }
}
extern "C" VortexProcess* fn_98_1C184(VortexProcess* process, int deleting) {
    if (process && static_cast<short>(deleting) > 0) operator delete(process);
    return process;
}
extern "C" VortexProcess* fn_98_1C1C4(VortexProcess* process, int deleting) {
    if (process && static_cast<short>(deleting) > 0) operator delete(process);
    return process;
}
extern "C" VortexProcess* fn_98_1C204(VortexProcess* process, int deleting) {
    if (process && static_cast<short>(deleting) > 0) operator delete(process);
    return process;
}
extern "C" {
static VortexRegistration lbl_98_bss_458;
VortexProcess lbl_98_bss_464;
static VortexRegistration vortexAttackRegistration;
VortexProcess lbl_98_bss_474;
static VortexRegistration vortexDischargeRegistration;
VortexProcess lbl_98_bss_484;
}
#pragma dont_inline on
extern "C" void fn_98_1C244() {
    fn_98_1C2C4(&lbl_98_bss_464);
    __register_global_object(&lbl_98_bss_464, reinterpret_cast<void*>(fn_98_1C204), &lbl_98_bss_458);
    fn_98_1C2D4(&lbl_98_bss_474);
    __register_global_object(&lbl_98_bss_474, reinterpret_cast<void*>(fn_98_1C1C4), &vortexAttackRegistration);
    fn_98_1C2E4(&lbl_98_bss_484);
    __register_global_object(&lbl_98_bss_484, reinterpret_cast<void*>(fn_98_1C184), &vortexDischargeRegistration);
}
extern "C" VortexProcess* fn_98_1C2C4(VortexProcess* process) { process->vtable = &lbl_98_data_994C; return process; }
extern "C" VortexProcess* fn_98_1C2D4(VortexProcess* process) { process->vtable = &lbl_98_data_98D0; return process; }
extern "C" VortexProcess* fn_98_1C2E4(VortexProcess* process) { process->vtable = &lbl_98_data_9850; return process; }
#pragma dont_inline reset

extern "C" {
VortexVtable lbl_98_data_9850 = { &lbl_98_data_98C8, 0, {
    reinterpret_cast<VortexMethod>(fn_98_1C184), reinterpret_cast<VortexMethod>(fn_98_1BC58),
    reinterpret_cast<VortexMethod>(fn_98_1BCAC), reinterpret_cast<VortexMethod>(fn_98_1BC64),
    fn_98_FF94, fn_98_FF90, fn_98_FF8C, reinterpret_cast<VortexMethod>(fn_98_1BCA4),
    fn_98_FF84, fn_98_FF7C, fn_98_FF78, fn_98_FF70, fn_98_FF6C, fn_98_FF64 }};
char lbl_98_data_9890[] = "wnPikachuVortexStatusUniqProcessDischarge";
VortexBaseInfo lbl_98_data_98BC = { lbl_98_data_76B8, 0, 0 };
VortexTypeInfo lbl_98_data_98C8 = { lbl_98_data_9890, &lbl_98_data_98BC };
VortexVtable lbl_98_data_98D0 = { &lbl_98_data_9944, 0, {
    reinterpret_cast<VortexMethod>(fn_98_1C1C4), fn_98_10060, fn_98_FFDC,
    reinterpret_cast<VortexMethod>(fn_98_1BC10), fn_98_FF94, fn_98_FF90, fn_98_FF8C,
    reinterpret_cast<VortexMethod>(fn_98_1BC50), fn_98_FF84, fn_98_FF7C, fn_98_FF78,
    fn_98_FF70, fn_98_FF6C, fn_98_FF64 }};
char lbl_98_data_9910[] = "wnPikachuVortexStatusUniqProcessAttack";
VortexBaseInfo lbl_98_data_9938 = { lbl_98_data_76B8, 0, 0 };
VortexTypeInfo lbl_98_data_9944 = { lbl_98_data_9910, &lbl_98_data_9938 };
VortexVtable lbl_98_data_994C = { &lbl_98_data_99C0, 0, {
    reinterpret_cast<VortexMethod>(fn_98_1C204), fn_98_10060, fn_98_FFDC,
    reinterpret_cast<VortexMethod>(fn_98_1BBC8), fn_98_FF94, fn_98_FF90, fn_98_FF8C,
    reinterpret_cast<VortexMethod>(fn_98_1BC08), fn_98_FF84, fn_98_FF7C, fn_98_FF78,
    fn_98_FF70, fn_98_FF6C, fn_98_FF64 }};
char lbl_98_data_998C[] = "wnPikachuVortexStatusUniqProcessNormal";
VortexBaseInfo lbl_98_data_99B4 = { lbl_98_data_76B8, 0, 0 };
VortexTypeInfo lbl_98_data_99C0 = { lbl_98_data_998C, &lbl_98_data_99B4 };
}
__declspec(section ".ctors") extern void (*const vortexInitializer)() = fn_98_1C244;
