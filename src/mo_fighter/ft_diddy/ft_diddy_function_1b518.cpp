#include <so/so_module_accesser.h>
#pragma force_active on

struct WeaponActivationDescriptor {
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

    inline WeaponActivationDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};

struct VirtualSlot7 {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5(unsigned int a, unsigned int b) = 0;
};

struct VirtualSlot36 {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
    virtual void slot26() = 0;
    virtual void slot27() = 0;
    virtual void slot28() = 0;
    virtual void slot29() = 0;
    virtual void slot30() = 0;
    virtual void slot31() = 0;
    virtual void slot32() = 0;
    virtual void slot33() = 0;
    virtual void slot34(unsigned int value) = 0;
};

struct WeaponObject {
    unsigned char prefix[0x60];
    unsigned char* accesser;
};

extern "C" {
void fn_27_1D8370(void*, const WeaponActivationDescriptor*);

void fn_115_1B518(WeaponObject* object, unsigned int taskId, int parameter, const Vec3f* position, float facing) {
    WeaponActivationDescriptor descriptor(taskId, parameter, *position, facing);
    fn_27_1D8370(object, &descriptor);

    unsigned char* first = *(unsigned char**)(object->accesser + 0xD8);
    VirtualSlot7* second = *(VirtualSlot7**)(first + 0x64);
    second->slot5(**(unsigned int**)((unsigned char*)object + 0x1F94), 0x10000005);

    soModuleAccesser* accesser = (soModuleAccesser*)object->accesser;
    accesser->getStatusModule().changeStatusForce(0, accesser);
}
}
