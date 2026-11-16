#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <mt/mt_vector.h>
#include <math.h>
#pragma force_active on

struct Argument {
    virtual void unused0();
    virtual signed char getKind();
    virtual signed char getIndex();
};

class EnergyView {
public:
    virtual void unused0();
    virtual void unused1();
    virtual Vec2f getSpeed();
};

class StatusView {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual bool changeStatusRequest(int, soModuleAccesser*);
};

class PokeSelf {
public:
    unsigned char pad0[0x3C];
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual bool isObserv(signed char group);
    unsigned char pad1[0x60 - 0x40];
    soModuleAccesser* m_accesser;
};

extern "C" {
extern const float lbl_116_rodata_A0[];
extern const char lbl_116_data_7710[], lbl_116_data_2260[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_1DA24C(void*, void*, void*);
float fn_8003DDD0(const Vec2f*, const Vec2f*);
void fn_116_23A24(const float*, float, float*);
void fn_116_CB3C(Vec2f*, const Vec2f*);
}

static inline Vec2f scaleVec(const Vec2f& v, float s) {
    Vec2f r;
    fn_116_23A24(reinterpret_cast<const float*>(&v), s, reinterpret_cast<float*>(&r));
    return r;
}

static inline Vec2f scaleNormal(const Vec2f& v, const float* c) {
    Vec2f r;
    fn_116_23A24(reinterpret_cast<const float*>(&v), c[7], reinterpret_cast<float*>(&r));
    return r;
}

static inline float velocityAngle(const Vec2f& v, float lr) {
    float x = v.m_x * lr;
    return static_cast<float>(atan2(v.m_y, x));
}

extern "C" int fn_116_236D4(PokeSelf* self, Argument* cmd, soModuleAccesser* accesser) {
    const float* c = lbl_116_rodata_A0;
    if (fn_27_1DA24C(self, cmd, accesser)) {
        return 1;
    }
    signed char group = cmd->getKind();
    if (!self->isObserv(group)) {
        return 0;
    }
    if (cmd->getIndex() <= -1 || cmd->getIndex() >= 11) {
        return 0;
    }
    switch (cmd->getIndex()) {
    case 6: {
        EnergyView* energy = static_cast<EnergyView*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(0), 0,
            lbl_116_data_7710, lbl_116_data_2260, 1));
        Vec2f speed;
        Vec2f::copy(speed, energy->getSpeed());
        Vec2f normal;
        Vec2f::copy(normal, accesser->getGroundModule().getTouchNormal(
            static_cast<grCollStatus::TouchMask>(0xFF), 0));
        float lr;
        float angle;
        float scale;
        angle = c[6] * fn_8003DDD0(&normal, &speed);
        if (angle - c[5] < soValueAccesser::getConstantFloat(self->m_accesser, 0xFA4, 0)) {
            scale = soValueAccesser::getConstantFloat(self->m_accesser, 0xFA5, 0);
            lr = self->m_accesser->getPostureModule().getLr();
            angle = normal.m_x * speed.m_x + normal.m_y * speed.m_y;
            speed = speed - scaleVec(scaleNormal(normal, c), angle);
            fn_116_23A24(reinterpret_cast<const float*>(&speed),
                         scale, reinterpret_cast<float*>(&speed));
            fn_116_CB3C(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 8),
                        &speed);
            float result = c[6] * velocityAngle(speed, lr);
            self->m_accesser->getWorkManageModule().setFloat(result, 0x11000004);
        } else {
            reinterpret_cast<StatusView*>(&self->m_accesser->getStatusModule())->changeStatusRequest(1, self->m_accesser);
        }
        return 1;
    }
    }
    return 0;
}