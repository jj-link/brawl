#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

struct ZeldaDescriptor {
    unsigned int taskId;
    int id0, id1, id2, ownerId, teamId, field18, field1C;
    Vec3f position;
    float facing;
    int parameter, field34, situation, status, field40, motion, field48;
    u8 active : 1;
    u8 field4C1 : 3;
    u8 field4C4 : 1;
    u8 field4C5 : 3;
    u8 field4D0 : 2;
    u8 reserved : 6;
    ZeldaDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), id0(0xffff), id1(0xffff), id2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos),
          facing(lr), parameter(value), field34(0), situation(2), status(0x80),
          field40(0), motion(0x35f), field48(0), active(1), field4C1(0),
          field4C4(1), field4C5(0), field4D0(0) {}
};
struct ZeldaObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char padding[0x2018];
    const float* parameters;
};
struct ZeldaEnergy {
    unsigned char prefix[8];
    Vec2f speed;
};
extern "C" {
extern const float lbl_104_rodata_98, lbl_104_rodata_A0;
extern const char lbl_104_data_80B4[], lbl_104_data_2404[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const ZeldaDescriptor*);

void fn_104_12290(ZeldaObject* object, unsigned int task, int value, const Vec3f* position, float facing) {
    ZeldaDescriptor descriptor(task, value, *position, facing);
    fn_27_1D8370(object, &descriptor);
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
    object->accesser->getLinkModule().setAttribute(3, static_cast<soLinkConnection::Attribute>(4), true);
    soWorkManageModule& work = object->accesser->getWorkManageModule();
    soKineticModule& kinetic = object->accesser->getKineticModule();
    work.setInt(value, 0x20000001);
    work.setInt(task, 0x20000002);
    work.setFloat(object->parameters[4] * facing, 0x21000002);
    work.setFloat(object->parameters[5], 0x21000003);
    float angle = facing > lbl_104_rodata_98 ? lbl_104_rodata_98 : lbl_104_rodata_A0;
    float direction = work.getFloat(0x21000002);
    Vec2f speed;
    speed.m_x = object->parameters[5] * (float)cos(angle + direction);
    speed.m_y = object->parameters[5] * (float)sin(angle + direction);
    ZeldaEnergy* energy = static_cast<ZeldaEnergy*>(__dynamic_cast(kinetic.getEnergy(0), 0, lbl_104_data_80B4, lbl_104_data_2404, 1));
    energy->speed = speed;
}
}