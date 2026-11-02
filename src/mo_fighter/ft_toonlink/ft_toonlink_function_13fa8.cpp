#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#include <math.h>
#pragma force_active on

class Class_8C9C {
public:
    virtual void fn_121_22F8();  // offset 0x8
    virtual s8 fn_121_12B00();  // offset 0xc
    virtual s8 fn_121_14684();  // offset 0x10
    virtual void fn_121_14680();  // offset 0x14
    virtual void fn_121_1467C();  // offset 0x18
    virtual void fn_121_14678();  // offset 0x1c
    virtual void fn_121_14670();  // offset 0x20
    virtual void fn_121_146B8();  // offset 0x24
    virtual void fn_121_146B0();  // offset 0x28
    virtual void fn_121_146A8();  // offset 0x2c
    virtual void fn_121_146A0();  // offset 0x30
    virtual void fn_121_14698();  // offset 0x34
    virtual void fn_121_14630();  // offset 0x38
    virtual void fn_121_14664();  // offset 0x3c
    virtual void fn_121_14658();  // offset 0x40
    virtual void fn_121_14650();  // offset 0x44
};

class Class_8E20 {
public:
    virtual void fn_121_22F8();  // offset 0x8
    virtual void fn_121_12B5C();  // offset 0xc
    virtual Vec2f fn_121_14840();  // offset 0x10
    virtual void fn_121_14838();  // offset 0x14
    virtual void fn_121_14830();  // offset 0x18
    virtual void fn_121_14828();  // offset 0x1c
    virtual void fn_121_14820();  // offset 0x20
    virtual void fn_121_14818();  // offset 0x24
    virtual void fn_121_14810();  // offset 0x28
    virtual void fn_121_14808();  // offset 0x2c
    virtual void fn_121_14800();  // offset 0x30
    virtual void fn_121_147F8();  // offset 0x34
    virtual void fn_121_147F0();  // offset 0x38
    virtual void fn_121_147E8();  // offset 0x3c
    virtual void fn_121_14798();  // offset 0x40
    virtual void fn_121_147E0();  // offset 0x44
};

class ToonLinkWeapon : public StageObject {
public:
    u8 m_pad[0x20e4 - 0x64];
    float* m_params;
};

extern "C" {
extern const float lbl_121_rodata_78[];
extern const unsigned char lbl_121_data_8EF0[];
extern const unsigned char lbl_121_data_31F4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_1DA24C(void*, void*, void*);
float fn_8003DDD0(const Vec2f*, const Vec2f*);
Vec2f fn_121_1449C(const Vec2f*, float);
void fn_121_13E04(Vec2f*, float, float);
Vec2f* fn_121_DAE8(Vec2f*, const Vec2f*);
}

struct ToonLinkVec2 : public Vec2f {
    ToonLinkVec2(const Vec2f& v) { fn_121_13E04(this, v.m_x, v.m_y); }
};

static inline void reflectInner(Vec2f& v, const Vec2f& n, const float* c, float dot)
{
    v = v - fn_121_1449C(&fn_121_1449C(&n, c[6]), dot);
}

static inline void reflect(Vec2f& v, const Vec2f& n, const float* c, float dot)
{
    reflectInner(v, n, c, dot);
}

extern "C" int fn_121_13FA8(ToonLinkWeapon* self, Class_8C9C* cmd, soModuleAccesser* accesser)
{
    const float* c = lbl_121_rodata_78;
    if (fn_27_1DA24C(self, cmd, accesser)) {
        return 1;
    }
    s8 group = cmd->fn_121_12B00();
    if (!self->isObserv(group)) {
        return 0;
    }
    if (cmd->fn_121_14684() <= -1 || cmd->fn_121_14684() >= 11) {
        return 0;
    }
    switch (cmd->fn_121_14684()) {
    case 6: {
        float* params;
        unsigned char* energy = static_cast<unsigned char*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(0), 0,
            lbl_121_data_8EF0, lbl_121_data_31F4, 1));
        Vec2f speed;
        Vec2f::copy(speed, reinterpret_cast<Class_8E20*>(energy)->fn_121_14840());
        params = self->m_params;
        if (!accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(9), 0)) {
            if (c[0] == accesser->getPostureModule().getLr()) {
                if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(0xa4), 0) == true) {
                    Vec2f normal;
                    Vec2f::copy(normal, accesser->getGroundModule().getTouchNormal(
                        static_cast<grCollStatus::TouchMask>(0xa4), 0));
                    if (fn_8003DDD0(&normal, &speed) >= c[5] + params[10]) {
                        soModuleAccesser* a = self->m_moduleAccesser;
                        a->getStatusModule().changeStatusRequest(3, a);
                        return 1;
                    }
                }
            } else {
                if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(0x52), 0) == true) {
                    Vec2f normal;
                    Vec2f::copy(normal, accesser->getGroundModule().getTouchNormal(
                        static_cast<grCollStatus::TouchMask>(0x52), 0));
                    if (fn_8003DDD0(&normal, &speed) >= c[5] + params[10]) {
                        soModuleAccesser* a = self->m_moduleAccesser;
                        a->getStatusModule().changeStatusRequest(3, a);
                        return 1;
                    }
                }
            }
        }
        Vec2f normal;
        Vec2f::copy(normal, accesser->getGroundModule().getTouchNormal(
            static_cast<grCollStatus::TouchMask>(0xff), 0));
        float dot = normal.m_x * speed.m_x + normal.m_y * speed.m_y;
        reflect(speed, normal, c, dot);
        fn_121_DAE8(reinterpret_cast<Vec2f*>(energy + 8), &ToonLinkVec2(speed));
        float lengthSq = speed.lengthSq();
        float length;
        if (static_cast<float>(fabs(lengthSq)) <= c[7]) {
            length = c[2];
        } else {
            length = lengthSq * rsqrtf(lengthSq);
        }
        if (length > c[8]) {
            Vec2f accel;
            Vec2f::copy(accel, fn_121_1449C(&speed, -(self->m_params[7] / length)));
            fn_121_DAE8(reinterpret_cast<Vec2f*>(energy + 0x10), &accel);
        }
        float angle = atan2f(speed.m_y, speed.m_x);
        self->m_moduleAccesser->getWorkManageModule().setFloat(angle, 0x11000001);
        Vec3f rot;
        rot.m_x = c[2];
        rot.m_y = c[2];
        rot.m_z = c[4] * angle;
        self->m_moduleAccesser->getPostureModule().setRot(&rot, 0);
        return 1;
    }
    }
    return 0;
}
