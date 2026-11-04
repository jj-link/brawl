#pragma force_active on
#include <math.h>
#include <mt/mt_common.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>

extern const float lbl_122_rodata_40[];
extern "C" void fn_122_145AC(Vec2f*, float, float);

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(unsigned long);
    virtual void setFloat(float, unsigned long);
};
struct Control {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual float getX();
    virtual void v17();
    virtual float getY();
};
struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float getLR();
};
struct Motion {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual float getWeight();
    virtual void v24();
    virtual void addWeight(float);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void addAngle(float);
    virtual float getAngle();
};
struct Modules {
    char pad0[8];
    Motion* motion;
    Posture* posture;
    char pad10[0x4c];
    Control* control;
    char pad60[4];
    Work* work;
};
struct Fighter {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_122_14314(void*, Fighter* self) {
    const float* constants = lbl_122_rodata_40;
    Vec2f old;
    Vec2f current;
    Work* work = self->modules->work;
    float y = work->getFloat(0x21000005);
    float x = work->getFloat(0x21000004);
    fn_122_145AC(&old, x, y);
    Control* control = self->modules->control;
    y = control->getY();
    x = control->getX();
    fn_122_145AC(&current, x, y);
    current.m_x = old.m_x + (current.m_x - old.m_x) * self->modules->work->getFloat(0x21000006);
    current.m_y = old.m_y + (current.m_y - old.m_y) * self->modules->work->getFloat(0x21000006);
    float length = current.m_x * current.m_x + current.m_y * current.m_y;
    if ((float)(double)nw4r::ut::Abs(length) <= constants[1])
        length = constants[0];
    else
        length *= rsqrtf(length);
    if (length > constants[2])
        length = constants[2];
    self->modules->motion->addWeight((constants[2] - length) - self->modules->motion->getWeight());
    float angle = constants[3] * (float)atan2(current.m_y, current.m_x * self->modules->posture->getLR());
    if (angle > constants[4])
        angle -= constants[4];
    else if (angle < constants[0])
        angle += constants[4];
    Motion* motion = self->modules->motion;
    motion->addAngle(angle - motion->getAngle());
    self->modules->work->setFloat(current.m_x, 0x21000004);
    self->modules->work->setFloat(current.m_y, 0x21000005);
}
