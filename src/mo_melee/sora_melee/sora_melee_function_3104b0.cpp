#pragma fp_contract off
#pragma force_active on

#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#include <math.h>

class Kinetic {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void* s6(int);
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual Vec2f s13(short*);
};

class Energy {
public:
    virtual void s0();
    virtual void s1();
    virtual Vec2f s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(int, Vec2f*, Vec3f*, soModuleAccesser*);
    unsigned char padding4;
    unsigned char enabled : 1;
};

class Posture {
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
    virtual float s9();
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
    virtual void s31(float);
};

class Situation {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
    virtual void s4();
    virtual void s5();
    virtual void s6(int, int);
};

struct GroundBase {
    char pad[8];
};

class Ground : public GroundBase {
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
    virtual void s19(int, int);
};

class Effect {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6(int, Vec3f*, Vec3f*, int, int, float);
};

class Work {
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
    virtual void s13(int, float);
};

struct Base {
    char pad[0x3c];
};

class Task : public Base {
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
extern char lbl_27_data_13690[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_7460[];

void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_89DAC(int, soModuleAccesser*);
void fn_27_193378(soModuleAccesser*, float);
int fn_27_195528(soModuleAccesser*, Vec2f*, Vec2f*);
float fn_8003DDD0(const Vec2f*, const Vec2f*);
}

extern "C" void fn_27_3104B0(void*, soModuleAccesser* a) {
            Vec2f speed;
        const float* c = lbl_27_rodata_7460;
    Vec2f velocity;

    switch (a->getStatusModule().getStatusKind()) {
    case 0x114: {
        Energy* e = (Energy*)__dynamic_cast(
            ((Kinetic*)&a->getKineticModule())->s6(3), 0,
            lbl_27_data_13690, lbl_27_data_CDF8, 1);

        short one = 1;
        Vec2f::copy(speed, ((Kinetic*)&a->getKineticModule())->s13(&one));
        speed.m_x /= soValueAccesser::getConstantFloat(a, 0xfaf, 0);

        Vec3f zero;
        zero.m_x = c[0];
        zero.m_y = c[0];
        zero.m_z = c[0];
        e->s5(6, &Vec2f(speed.m_x, c[0]), &zero, a);
        *((unsigned char*)e + 5) |= 0x80;

        void* g = __dynamic_cast(
            ((Kinetic*)&a->getKineticModule())->s6(1), 0,
            lbl_27_data_2E430, lbl_27_data_CDF8, 1);
        *(float*)((char*)g + 0xc) = c[0];
        *((unsigned char*)g + 5) |= 0x80;

        fn_27_89DAC(2, a);
        fn_27_89DAC(0, a);
        break;
    }

    case 0x117: {
        Vec2f normal;
        float x = a->getControllerModule().getStickX();
        float y = a->getControllerModule().getStickY();
        float angle = c[1];
        float scale = soValueAccesser::getConstantFloat(a, 0xfb4, 0);
        float threshold = soValueAccesser::getConstantFloat(a, 0xfb3, 0);
        float absx = (float)(double)nw4r::ut::Abs(x);

        if (absx > soValueAccesser::getConstantFloat(a, 0xfb2, 0)) {
            ((Posture*)&a->getPostureModule())->s31(c[0]);
            ((Posture*)&a->getPostureModule())->s19();
        }

        float lr = ((Posture*)&a->getPostureModule())->s9();

        if (((Situation*)&a->getSituationModule())->s3() == 0) {
            Vec2f::copy(
                normal,
                a->getGroundModule().getTouchNormal(
                    (grCollStatus::TouchMask)8, 0));

            bool keep = true;
            float absY = (float)(double)nw4r::ut::Abs(y);
            float absX = (float)(double)nw4r::ut::Abs(x);
            if (!(absX + absY < threshold)) {
                if (fn_8003DDD0(&normal, &Vec2f(x, y)) >= c[1])
                    keep = false;
            }

            if (!keep) {
                velocity.m_x = scale * lr;
                velocity.m_y = c[0];
                angle = (float)atan2(-normal.m_x * lr, normal.m_y);
            } else {
                ((Situation*)&a->getSituationModule())->s6(2, 0);
                ((Ground*)&a->getGroundModule())->s19(5, 0);
            }
        }

        if (((Situation*)&a->getSituationModule())->s3() == 2) {
            double absY = nw4r::ut::Abs(y);
            double absX = nw4r::ut::Abs(x);
            if ((float)absX + (float)absY >= threshold)
                angle = (float)atan2(y, x * lr);

            velocity.m_x = lr * (scale * (float)cos(angle));
            velocity.m_y = scale * (float)sin(angle);

            void* g = __dynamic_cast(
                ((Kinetic*)&a->getKineticModule())->s6(1), 0,
                lbl_27_data_2E430, lbl_27_data_CDF8, 1);
            *(float*)((char*)g + 0x10) = c[0];
            ((Energy*)g)->enabled = 0;
        }

        void* e = __dynamic_cast(
            ((Kinetic*)&a->getKineticModule())->s6(3), 0,
            lbl_27_data_13690, lbl_27_data_CDF8, 1);
        *(Vec2f*)((char*)e + 8) = velocity;
        *((unsigned char*)e + 5) |= 0x80;

        fn_27_193378(a, c[2] - c[3] * angle);
        ((Task*)*(void**)((char*)a + 8))->s43();
        ((Work*)&a->getWorkManageModule())->s13(0x21000004, angle);
        break;
    }

    case 0x118:
        if (((Situation*)&a->getSituationModule())->s3() != 2) {
            void* e = __dynamic_cast(
                ((Kinetic*)&a->getKineticModule())->s6(3), 0,
                lbl_27_data_13690, lbl_27_data_CDF8, 1);
            float brake = soValueAccesser::getConstantFloat(a, 0xfb6, 0);
            *(Vec2f*)((char*)e + 0x20) = Vec2f(brake, c[0]);
        }
        break;

    case 0x119: {
        Energy* e = (Energy*)__dynamic_cast(
            ((Kinetic*)&a->getKineticModule())->s6(3), 0,
            lbl_27_data_13690, lbl_27_data_CDF8, 1);
        float lengthSq = e->s2().lengthSq();
        float length = (float)(double)nw4r::ut::Abs(lengthSq) <= c[4]
                           ? c[0]
                           : lengthSq * rsqrtf(lengthSq);
        float value = length * ((Posture*)&a->getPostureModule())->s9();
        float scaledValue = value * soValueAccesser::getConstantFloat(a, 0xfb8, 0);
        *(Vec2f*)((char*)e + 8) = Vec2f(scaledValue, c[0]);

        Vec2f pos, normal;
        if (fn_27_195528(a, &pos, &normal)) {
            double angleDouble = atan2(-normal.m_x, normal.m_y);
            Vec3f p;
            Vec3f rot;
            float x, y;
            y = pos.m_y;
            x = pos.m_x;
            float angle = (float)angleDouble;
            rot.m_x = c[0];
            rot.m_y = c[0];
            rot.m_z = angle;
            p.m_x = x;
            p.m_y = y;
            p.m_z = c[0];
            ((Effect*)&a->getEffectModule())->s6(9, &p, &rot, 0, -1, c[5]);
        }
        break;
    }
    }
}
