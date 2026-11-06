#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#include <math.h>
#pragma force_active on

extern "C" void fn_27_492C(void);
extern "C" const float lbl_113_rodata_140[];

class StatusLike {
public:
    virtual bool isNull() const;
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3();
    virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7();
    virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11();
    virtual void u12(); virtual void u13(); virtual void u14();
    virtual int getStatusKind();
};

class KineticLike {
public:
    virtual bool isNull() const;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual Vec2f getSumSpeed(const short&);
};

class WorkLike {
public:
    virtual bool isNull() const;
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3();
    virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7();
    virtual void w8(); virtual void w9(); virtual void w10();
    virtual float getFloat(int);
    virtual void setFloat(float, int);
};

struct EnumLike {
    char pad0[4];
    soModelModule* model;
    char pad1[0x5C];
    WorkLike* work;
    char pad2[8];
    StatusLike* status;
    char pad3[8];
    KineticLike* kinetic;
};

struct AccesserLike {
    char pad0[0xD8];
    const EnumLike* enumStart;
};

struct FighterLike {
    char pad0[0x60];
    AccesserLike* accesser;
};

extern "C" void fn_113_29724(FighterLike* self) {
    const float* c = lbl_113_rodata_140;
    fn_27_492C();
    if (self->accesser->enumStart->status->getStatusKind() == 1 ||
        self->accesser->enumStart->status->getStatusKind() == 2) {
        short flag = -1;
        Vec2f speed;
        Vec2f::copy(speed, self->accesser->enumStart->kinetic->getSumSpeed(flag));
        float value = self->accesser->enumStart->work->getFloat(0x21000000);
        float y = speed.m_y;
        float angle = (float)atan2(speed.m_x, y);
        float target = value + c[8] * ((c[3] * (c[7] * angle)) - value);
        self->accesser->enumStart->work->setFloat(target, 0x21000000);
        self->accesser->enumStart->model->setNodeRotateZ(1, target);
    }
}
