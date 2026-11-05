#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct SpeedPair { float x, y; };

class EnergyView {
public:
    virtual void isNull();
    virtual void slot1();
    virtual SpeedPair slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    char pad[12];
    Vec2f accel;
    Vec2f limit;
    Vec2f speed;
    Vec2f brake;
    void setAccel(const Vec2f& v) { accel.m_x = v.m_x; accel.m_y = v.m_y; }
    void setLimit(const Vec2f& v) { limit.m_x = v.m_x; limit.m_y = v.m_y; }
    void setSpeed(const Vec2f& v) { speed.m_x = v.m_x; speed.m_y = v.m_y; }
    void setBrake(const Vec2f& v) { brake.m_x = v.m_x; brake.m_y = v.m_y; }
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_7A90;
extern const float lbl_27_rodata_7A98;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_8003DBA8(Vec2f*);
}

extern "C" void fn_27_361C24(void*, void*, void*, soModuleAccesser* accesser) {
    EnergyView* stop = (EnergyView*)__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    EnergyView* gravity = (EnergyView*)__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    Vec3f rot1;
    Vec3f rot2;
    Vec2f stopSpeed;
    Vec2f gravitySpeed;
    Vec2f speed;
    SpeedPair temp1 = stop->slot2();
    __memcpy(&stopSpeed, &temp1, 8);
    SpeedPair temp2 = gravity->slot2();
    __memcpy(&gravitySpeed, &temp2, 8);
    rot1.m_x = lbl_27_rodata_7A90;
    rot1.m_y = lbl_27_rodata_7A90;
    rot1.m_z = lbl_27_rodata_7A90;
    fn_27_89D08(1, accesser, 0, &gravitySpeed, &rot1);
    rot2.m_x = lbl_27_rodata_7A90;
    rot2.m_y = lbl_27_rodata_7A90;
    rot2.m_z = lbl_27_rodata_7A90;
    fn_27_89D08(3, accesser, 10, &stopSpeed, &rot2);
    float accel = soValueAccesser::getConstantFloat(accesser, 0xFAB, 0);
    float limit = soValueAccesser::getConstantFloat(accesser, 0xFAC, 0);
    float magnitude = soValueAccesser::getConstantFloat(accesser, 0xFAD, 0);
    gravity->accel.m_x = -accel;
    gravity->limit.m_x = lbl_27_rodata_7A90;
    gravity->accel.m_y = limit;
    gravity->limit.m_y = limit;
    stop->setAccel(Vec2f(lbl_27_rodata_7A90, lbl_27_rodata_7A90));
    stop->setLimit(Vec2f(lbl_27_rodata_7A98, lbl_27_rodata_7A98));
    stop->setBrake(stopSpeed);
    Vec2f::copy(speed, stopSpeed);
    fn_8003DBA8(&speed);
    speed.m_x *= accesser->getPostureModule().getLr();
    speed.m_x *= magnitude;
    speed.m_y *= magnitude;
    stop->setSpeed(speed);
}
