#include <so/stageobject.h>
#pragma force_active on

struct ZeldaWeaponDescriptor {
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
    u8 field4D0 : 1;
    u8 field4D1 : 1;
    u8 reserved : 6;

    inline ZeldaWeaponDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0), field4D1(0) { field4D0 = 1; }
};

extern "C" {
extern const float lbl_104_rodata_198;
extern const float lbl_104_rodata_190;
void fn_27_1D8370(void*, const ZeldaWeaponDescriptor*);

void fn_104_21A98(StageObject* object, unsigned int taskId, int value,
                  const Vec3f* position, float facing) {
    ZeldaWeaponDescriptor descriptor(taskId, value, *position, facing);
    fn_27_1D8370(object, &descriptor);
    soMotionChangeParam motion;
    motion.m_kind = 0;
    motion.m_frame = lbl_104_rodata_198;
    motion.m_rate = lbl_104_rodata_190;
    motion._12 = 0;
    motion._13 = 0;
    motion._14 = 0;
    motion._15 = 0;
    object->m_moduleAccesser->getMotionModule().changeMotionRequest(&motion);
}
}
