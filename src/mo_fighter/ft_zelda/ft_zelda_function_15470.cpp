#include <so/so_module_accesser.h>
#pragma force_active on

struct Descriptor {
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
    inline Descriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};
struct Owner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
extern "C" {
extern float lbl_104_rodata_C0, lbl_104_rodata_C8;
void fn_27_1D8370(void*, const Descriptor*);
void fn_104_15470(Owner* object, unsigned int taskId, int value,
                  const Vec3f* position, float facing, float power) {
    Descriptor descriptor(taskId, value, *position, facing);
    fn_27_1D8370(object, &descriptor);
    soWorkManageModule* work = &object->accesser->getWorkManageModule();
    work->setFloat(lbl_104_rodata_C8, 0x21000000);
    work->setFloat(lbl_104_rodata_C0, 0x21000002);
    work->setFloat(power, 0x21000001);
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
}
}