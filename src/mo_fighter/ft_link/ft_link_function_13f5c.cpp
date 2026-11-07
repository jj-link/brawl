#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <math.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void fn_93_22F8();
    virtual s8 slot1();
    virtual s8 slot2();
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
};

class LinkEnergy {
public:
    virtual void fn_93_22F8();
    virtual void slot1();
    virtual Vec2f slot2();
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
};

class LinkWeapon : public StageObject {
public:
    u8 m_pad[0x20e4 - 0x64];
    float* m_params;
};

extern "C" {
extern const float lbl_93_rodata_78[];
extern const unsigned char lbl_93_data_8DD0[];
extern const unsigned char lbl_93_data_30FC[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_1DA24C(void*, void*, void*);
float fn_8003DDD0(const Vec2f*, const Vec2f*);
Vec2f fn_93_14450(const Vec2f*, float);
void fn_93_13DB8(Vec2f*, float, float);
Vec2f* fn_93_DAEC(Vec2f*, const Vec2f*);
}

struct LinkVec2 : public Vec2f {
    LinkVec2(const Vec2f& v) {
        fn_93_13DB8(this, v.m_x, v.m_y);
    }
};

static inline void reflectInner(Vec2f& v, const Vec2f& n, const float* c, float dot)
{
    v = v - fn_93_14450(&fn_93_14450(&n, c[6]), dot);
}

static inline void reflect(Vec2f& v, const Vec2f& n, const float* c, float dot)
{
    reflectInner(v, n, c, dot);
}

extern "C" int fn_93_13F5C(LinkWeapon* self, Object_vptr_0* cmd,
                             soModuleAccesser* accesser)
{
    const float* c = lbl_93_rodata_78;
    if (fn_27_1DA24C(self, cmd, accesser)) {
        return 1;
    }

    s8 group = cmd->slot1();
    if (!self->isObserv(group)) {
        return 0;
    }

    if (cmd->slot2() <= -1 || cmd->slot2() >= 11) {
        return 0;
    }

    switch (cmd->slot2()) {
    case 6: {
        float* params;
        unsigned char* energy = static_cast<unsigned char*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(0), 0,
            lbl_93_data_8DD0, lbl_93_data_30FC, 1));

        Vec2f speed;
        Vec2f::copy(speed, reinterpret_cast<LinkEnergy*>(energy)->slot2());
        params = self->m_params;

        if (!accesser->getGroundModule().isTouch(
                static_cast<grCollStatus::TouchMask>(9), 0)) {
            if (c[0] == accesser->getPostureModule().getLr()) {
                if (accesser->getGroundModule().isTouch(
                        static_cast<grCollStatus::TouchMask>(0xa4), 0) == true) {
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
                if (accesser->getGroundModule().isTouch(
                        static_cast<grCollStatus::TouchMask>(0x52), 0) == true) {
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
        fn_93_DAEC(reinterpret_cast<Vec2f*>(energy + 8), &LinkVec2(speed));

        float lengthSq = speed.lengthSq();
        float length;
        if (static_cast<float>(static_cast<double>(nw4r::math::FAbs(lengthSq))) <= c[7]) {
            length = c[2];
        } else {
            length = lengthSq * rsqrtf(lengthSq);
        }

        if (length > c[8]) {
            Vec2f accel;
            Vec2f::copy(accel, fn_93_14450(&speed, -(self->m_params[7] / length)));
            fn_93_DAEC(reinterpret_cast<Vec2f*>(energy + 0x10), &accel);
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
