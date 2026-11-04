#include <so/so_module_accesser.h>
#pragma force_active on

// Activation descriptor consumed by the common weapon-activation routine
// fn_27_1D8370. Layout and bitfield values mirror the other fighters'
// descriptors; the reserved bits of the final byte retain their original
// unspecified values.
struct LucarioWeaponDescriptor {
    unsigned int taskId;
    int identifier0, identifier1, identifier2;
    int ownerId, teamId;
    int field18, field1C;
    Vec3f position;
    float facing;
    int parameter, field34, situation, status, field40, motion, field48;
    u8 active : 1;
    u8 field4C1 : 3;
    u8 field4C4 : 1;
    u8 field4C5 : 3;
    u8 field4D0 : 2;
    u8 reserved : 6;

    inline LucarioWeaponDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};

// View of the fighter object: the module accesser sits at offset 0x60.
struct LucarioWeaponObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" {
void fn_27_1D8370(void*, const LucarioWeaponDescriptor*);

void fn_118_137EC(LucarioWeaponObject* object, unsigned int taskId, int ownerId,
                  const Vec3f* position, float facing, float powerMul) {
    LucarioWeaponDescriptor descriptor(taskId, ownerId, *position, facing);
    fn_27_1D8370(object, &descriptor);
    soModuleAccesser* accesser = object->accesser;
    accesser->getStatusModule().changeStatusForce(0, accesser);
    accesser->getCollisionAttackModule().setPowerMul(powerMul);
}
}
