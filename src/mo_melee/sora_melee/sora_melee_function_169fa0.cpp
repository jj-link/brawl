#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <math.h>
#pragma force_active on
extern const float lbl_27_rodata_20F0[];
class Work {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual float getFloat(unsigned long);
virtual void setFloat(float, unsigned long);
};
class Controller {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual float x();
virtual void slot17();
virtual float y();
};
class Posture {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual float lr();
};
class Class_1250 {
public:
virtual void fn0();
virtual void fn1();
virtual void fn2();
virtual void fn3();
virtual void fn4();
virtual void fn5();
virtual void fn6();
virtual void fn7();
virtual void fn8();
virtual void fn9();
virtual void fn10();
virtual void fn11();
virtual void fn12();
virtual void fn13();
virtual void fn14();
virtual void fn15();
virtual void fn16();
virtual void fn17();
virtual void fn18();
virtual void fn19();
virtual void fn20();
virtual void fn21();
virtual void fn22();
virtual float fn23();
virtual void fn24();
virtual void fn25(float);
virtual void fn26();
virtual void fn27();
virtual void fn28();
virtual void fn29();
virtual void fn30();
virtual void fn31();
virtual void fn32();
virtual void fn33();
virtual void fn34();
virtual void fn35(float);
virtual float fn36();
};
class Self {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2(soModuleAccesser*);
};
extern "C" void fn_27_169FA0(Self* self, soModuleAccesser* accesser) {
    const float* c = lbl_27_rodata_20F0;
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    Class_1250* motion = (Class_1250*)modules->m_motionModule;
    Work* work = (Work*)modules->m_workManageModule;
    float oldY = work->getFloat(0x21000005);
    Vec2f old(work->getFloat(0x21000004), oldY);
    float cy = ((Controller*)accesser->m_enumerationStart->m_controllerModule)->y();
    Vec2f stick(((Controller*)accesser->m_enumerationStart->m_controllerModule)->x(), cy);
    stick.m_x = old.m_x + (stick.m_x - old.m_x) * soValueAccesser::getConstantFloat(accesser, 0xcb2, 0);
    float newY = old.m_y + (stick.m_y - old.m_y) * soValueAccesser::getConstantFloat(accesser, 0xcb2, 0);
    stick.m_y = newY;
    float length = stick.lengthSq();
    if ((float)(double)nw4r::math::FAbs(length) <= c[1]) length = c[0];
    else length = length * rsqrtf(length);
    if (length > c[2]) length = c[2];
    motion->fn25((c[2] - length) - motion->fn23());
    float facing = ((Posture*)accesser->m_enumerationStart->m_postureModule)->lr();
    float horizontal = stick.m_x * facing;
    float vertical = stick.m_y;
    float angle = c[3] * (float)atan2(vertical, horizontal);
    if (angle > c[4]) angle -= c[4];
    else if (angle < c[0]) angle += c[4];
    motion->fn35(angle - motion->fn36());
    work->setFloat(stick.m_x, 0x21000004);
    work->setFloat(stick.m_y, 0x21000005);
    self->slot2(accesser);
}
