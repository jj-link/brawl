#pragma fp_contract off
#pragma force_active on

#include <so/so_value_accesser.h>
#include <nw4r/ut/ut_algorithm.h>
#include <math.h>

struct Speed {
    float x;
    float y;
};

struct Attribute {
    unsigned short value;
    unsigned short padding;
};

class KineticView {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual Speed sum(const unsigned short&);
};

struct OwnerBase {
    char pad[0x3c];
};

class Owner : public OwnerBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
};

extern "C" {
extern const float lbl_27_rodata_21D0[];

void fn_27_16C98C(void*, soModuleAccesser*);
float randf__Fv();
void fn_27_19397C(soModuleAccesser*, float, float, float, int);
void fn_27_193C20(soModuleAccesser*, float, int);
int fn_27_195528(soModuleAccesser*, Vec2f*, Vec2f*);
}

extern "C" void fn_27_16DA84(void* self, soModuleAccesser* a) {
    const float* c = lbl_27_rodata_21D0;
    int status = a->getStatusModule().getStatusKind();

    fn_27_16C98C(self, a);

    switch (status) {
    case 0x47: {
        Attribute attr;
        attr.value = 2;
        Vec2f speed;
        Vec2f::copy(speed, reinterpret_cast<const Vec2f&>(
            reinterpret_cast<KineticView*>(&a->getKineticModule())->sum(attr.value)));
        float lr = c[0];

        if (a->getGroundModule().isTouch((grCollStatus::TouchMask)4, 0)) {
            lr = c[1];
        } else if (a->getGroundModule().isTouch((grCollStatus::TouchMask)2, 0)) {
            lr = c[2];
        }

        if (lr * a->getPostureModule().getLr() > c[0]) {
            int kind = 0xd0;
            if ((float)(double)nw4r::ut::Abs(speed.m_x) > c[3] &&
                randf__Fv() < c[4]) {
                kind = 0x29;
            }

            soMotionChangeParam p;
            p.m_kind = kind;
            p.m_frame = c[0];
            p.m_rate = c[2];
            p._12 = 0;
            p._13 = 0;
            p._14 = 0;
            p._15 = 0;
            a->getMotionModule().changeMotionRequest(&p);

            if (kind == 0xd0) {
                fn_27_19397C(a, lr, lr, c[2], 0);
            } else {
                a->getPostureModule().setLr(lr);
                a->getPostureModule().updateRotYLr();
                reinterpret_cast<Owner*>(*(void**)((char*)a + 8))->s43();
            }
        } else {
            a->getGroundModule().setShapeFlag(
                (soGroundShapeImpl::ShapeFlagId)6, true, 0);

            soMotionChangeParam p;
            p.m_kind = 0xa5;
            p.m_frame = c[0];
            p.m_rate = c[2];
            p._12 = 0;
            p._13 = 0;
            p._14 = 0;
            p._15 = 0;
            a->getMotionModule().changeMotionRequest(&p);
        }

        float value = soValueAccesser::getConstantFloat(a, 0xcd6, 0);
        a->getWorkManageModule().setFloat(value, 0x21000008);
        a->getWorkManageModule().setInt(c[1] == lr ? 1 : 2, 0x20000001);
        int frames = soValueAccesser::getConstantInt(a, 0x5a34, 0);
        a->getCollisionHitModule().setXluFrameGlobal(frames, 0);

        Vec2f pos, normal;
        if (fn_27_195528(a, &pos, &normal)) {
            double angleDouble = atan2(-normal.m_x, normal.m_y);
            Vec3f point;
            Vec3f rot;
            float x, y;
            y = pos.m_y;
            x = pos.m_x;
            float angle = (float)angleDouble;
            rot.m_x = c[0];
            rot.m_y = c[0];
            rot.m_z = angle;
            point.m_x = x;
            point.m_y = y;
            point.m_z = c[0];
            a->getEffectModule().req((EfID)9, &point, &rot, c[2], 0, -1);

            Vec3f quake;
            quake.m_x = pos.m_x;
            quake.m_y = pos.m_y;
            quake.m_z = c[0];
            a->getCameraModule().reqQuake(
                (soCameraModule::QuakeKind)0, &quake);
        }

        a->getControllerModule().setRumble(8, 0, true, -1);
        break;
    }

    case 0x48: {
        Attribute attr;
        attr.value = 2;
        Vec2f speed;
        Vec2f::copy(speed, reinterpret_cast<const Vec2f&>(
            reinterpret_cast<KineticView*>(&a->getKineticModule())->sum(attr.value)));

        soMotionChangeParam p;
        p.m_kind = 0xd1;
        p.m_frame = c[0];
        p.m_rate = c[2];
        p._12 = 0;
        p._13 = 0;
        p._14 = 0;
        p._15 = 0;
        a->getMotionModule().changeMotionRequest(&p);

        fn_27_193C20(a, speed.m_x < c[0] ? c[1] : c[2], 0);
        float value = soValueAccesser::getConstantFloat(a, 0xcd6, 0);
        a->getWorkManageModule().setFloat(value, 0x21000008);
        a->getWorkManageModule().setInt(3, 0x20000001);
        a->getWorkManageModule().setInt(0, 0x1000003d);
        int frames = soValueAccesser::getConstantInt(a, 0x5a34, 0);
        a->getCollisionHitModule().setXluFrameGlobal(frames, 0);

        Vec2f pos, normal;
        if (fn_27_195528(a, &pos, &normal)) {
            double angleDouble = atan2(-normal.m_x, normal.m_y);
            Vec3f point;
            Vec3f rot;
            float x, y;
            y = pos.m_y;
            x = pos.m_x;
            float angle = (float)angleDouble;
            rot.m_x = c[0];
            rot.m_y = c[0];
            rot.m_z = angle;
            point.m_x = x;
            point.m_y = y;
            point.m_z = c[0];
            a->getEffectModule().req((EfID)9, &point, &rot, c[2], 0, -1);

            Vec3f quake;
            quake.m_x = pos.m_x;
            quake.m_y = pos.m_y;
            quake.m_z = c[0];
            a->getCameraModule().reqQuake(
                (soCameraModule::QuakeKind)0, &quake);
        }

        a->getControllerModule().setRumble(8, 0, true, -1);
        break;
    }
    }
}
