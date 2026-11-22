#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <types.h>

#pragma force_active on

#define GAME_KIN(a) ((GameKineticModule*)(a)->m_enumerationStart->m_kineticModule)
#define GAME_POST(a) ((GamePostureModule*)(a)->m_enumerationStart->m_postureModule)

extern "C" void fn_27_1DCC10(int kind, unsigned char* arg1, soModuleAccesser* accesser);

extern "C" const float lbl_27_rodata_78F0;
extern "C" const float lbl_27_rodata_78F4;

class GameNullableBase {
public:
    virtual bool isNull() const;
};

class GameKineticModule : public GameNullableBase {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy();
    virtual void eraseEnergy();
    virtual void eraseEnergyAll();
    virtual void getEnergy();
    virtual void isContain();
    virtual void updateEnergy();
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual void getSumSpeed();
    virtual void getSumSpeed3f();
    virtual void getSumRotation();
    virtual void setConsiderGroundFriction();
    virtual void mulSpeed();
    virtual void mulAccel();
    virtual void reflectSpeed();
    virtual void reflectAccel();
    virtual void changeKinetic();
    virtual int getKineticType();
};

class GamePostureModule : public GameNullableBase {
public:
    virtual void slot0();
    virtual void init();
    virtual void initPos();
    virtual void getPos();
    virtual void setPos();
    virtual void getPrevPos();
    virtual void getPrevRoughPos();
    virtual void setPrevRoughPos();
    virtual float getLr();
    virtual void setLr();
    virtual void reverseLr();
    virtual void initRot();
    virtual void initRotIdx();
    virtual void getRot();
    virtual void setRot();
    virtual void initRotYLr();
    virtual void isRotYLrDiff();
    virtual void getRotYLr();
    virtual void updateRotYLr();
    virtual void reverseRotYLr();
    virtual void getBaseScale();
    virtual float getScale();
};

struct Speed { float x, y; };
class GameKineticEnergyNormal {
public:
    GameKineticEnergyNormal() { m_isNull = false; }
    virtual bool isNull() const;
    virtual void slot1();
    virtual Speed slot2();

    unsigned char m_isNull;
    unsigned char m_flags;
    unsigned char m_b6;
    Vec2f m_v[5];
    unsigned char m_b30;
    unsigned char m_b31;
    unsigned char m_b32;
};

extern "C" const unsigned char lbl_27_data_13608[];
struct Range { unsigned long x, y; };
struct Config {
    const void* vtable;
    unsigned char state;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    unsigned char state2;
    Range ranges[5];
    bool firstFlag, secondFlag, initialized;
};
#pragma always_inline on
inline void setup(Config* self, const Vec2f& a, const Vec2f& b,
                  const Vec2f& c, const Vec2f& d, const Vec2f& e) {
    self->state = 0;
    self->enabled = true;
    self->state2 = 0;
    self->vtable = lbl_27_data_13608;
    self->ranges[0] = *(const Range*)&a;
    self->ranges[1] = *(const Range*)&b;
    self->ranges[2] = *(const Range*)&c;
    self->ranges[3] = *(const Range*)&d;
    self->ranges[4] = *(const Range*)&e;
    self->firstFlag = false;
    self->secondFlag = false;
    self->initialized = true;
}
struct GameOwner {
    unsigned char pad[0x10];
    GameKineticEnergyNormal energy;
};

extern "C" void fn_27_34CF20(int kind, GameOwner* arg1, soModuleAccesser* accesser) {
    if (kind <= 0x1f) {
        fn_27_1DCC10(kind, (unsigned char*)arg1, accesser);
        return;
    }
    switch (kind) {
    case 0x20: {
        GAME_KIN(accesser)->unableEnergyAll();
        Vec2f vc, vb, va;
        Vec2f v4(lbl_27_rodata_78F0, lbl_27_rodata_78F0);
        Vec2f v3(lbl_27_rodata_78F4, lbl_27_rodata_78F4);
        Vec2f v2(lbl_27_rodata_78F0, lbl_27_rodata_78F0);
        Vec2f v1(lbl_27_rodata_78F4, lbl_27_rodata_78F4);
        Vec2f v0(lbl_27_rodata_78F4, lbl_27_rodata_78F4);
        Config tmp;
        setup(&tmp, v0, v1, v2, v3, v4);
        arg1->energy.m_isNull = tmp.state;
        arg1->energy.m_flags = *(unsigned char*)((char*)&tmp + 5);
        arg1->energy.m_b6 = tmp.state2;
        *(Range*)&arg1->energy.m_v[0] = tmp.ranges[0];
        *(Range*)&arg1->energy.m_v[1] = tmp.ranges[1];
        *(Range*)&arg1->energy.m_v[2] = tmp.ranges[2];
        *(Range*)&arg1->energy.m_v[3] = tmp.ranges[3];
        *(Range*)&arg1->energy.m_v[4] = tmp.ranges[4];
        arg1->energy.m_b30 = tmp.firstFlag;
        arg1->energy.m_b31 = tmp.secondFlag;
        arg1->energy.m_b32 = tmp.initialized;
        float a = soValueAccesser::getConstantFloat(accesser, 0xfa2, 0);
        float b = soValueAccesser::getConstantFloat(accesser, 0xfa3, 0);
        a = a * GAME_POST(accesser)->getScale();
        b = b * GAME_POST(accesser)->getScale();
        va.m_x = lbl_27_rodata_78F4; va.m_y = a;
        arg1->energy.m_v[0] = va;
        vb.m_x = lbl_27_rodata_78F4; vb.m_y = b;
        arg1->energy.m_v[1] = vb;
        float c = soValueAccesser::getConstantFloat(accesser, 0xfa4, 0);
        vc.m_x = lbl_27_rodata_78F0; vc.m_y = c;
        arg1->energy.m_v[4] = vc;
        arg1->energy.m_flags = arg1->energy.m_flags | 0x80;
        break;
    }
    case 0x21: {
        Vec2f vf, vh, vg;
        GAME_KIN(accesser)->unableEnergyAll();
        if (GAME_KIN(accesser)->getKineticType() != 0x21 && GAME_KIN(accesser)->getKineticType() != 0x22) {
            float f = soValueAccesser::getConstantFloat(accesser, 0xfa0, 0);
            if (GAME_POST(accesser)->getLr() < lbl_27_rodata_78F4) {
                f = -f;
            }
            f *= GAME_POST(accesser)->getScale();
            vf.m_x = f; vf.m_y = lbl_27_rodata_78F4;
            arg1->energy.m_v[0] = vf;
        }
        arg1->energy.m_flags = arg1->energy.m_flags | 0x80;
        float g = soValueAccesser::getConstantFloat(accesser, 0xfa3, 0);
        vg.m_x = lbl_27_rodata_78F4; vg.m_y = g;
        arg1->energy.m_v[1] = vg;
        float h = soValueAccesser::getConstantFloat(accesser, 0xfa4, 0);
        vh.m_x = lbl_27_rodata_78F0; vh.m_y = h;
        arg1->energy.m_v[4] = vh;
        break;
    }
    case 0x22: {
        Vec2f vf, vq, vv1;
        GAME_KIN(accesser)->unableEnergyAll();
        if (GAME_KIN(accesser)->getKineticType() != 0x21 && GAME_KIN(accesser)->getKineticType() != 0x22) {
            float f = soValueAccesser::getConstantFloat(accesser, 0xfa0, 0);
            if (GAME_POST(accesser)->getLr() < lbl_27_rodata_78F4) {
                f = -f;
            }
            f *= GAME_POST(accesser)->getScale();
            vf.m_x = f; vf.m_y = lbl_27_rodata_78F4;
            arg1->energy.m_v[0] = vf;
        }
        arg1->energy.m_flags = arg1->energy.m_flags | 0x80;
        GameKineticEnergyNormal* energy = &arg1->energy;
        Speed speed = energy->slot2();
        Vec2f vv0(speed.x, lbl_27_rodata_78F4);
        energy->m_v[0] = vv0;
        vv1.m_x = lbl_27_rodata_78F4; vv1.m_y = lbl_27_rodata_78F4;
        energy->m_v[1] = vv1;
        float q = soValueAccesser::getConstantFloat(accesser, 0xfa1, 0);
        vq.m_x = q; vq.m_y = lbl_27_rodata_78F0;
        energy->m_v[4] = vq;
        break;
    }
    }
}
