#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct SpeedPair {
    float x, y;
};

class KineticView : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(soKineticEnergy*, int, soKineticEnergy::AttributeFlag, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int);
    virtual bool isContain(int);
    virtual void updateEnergy(soModuleAccesser*, soKineticEnergy::AttributeFlag);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual SpeedPair getSumSpeed(const unsigned short&);
};

extern "C" {
extern const float lbl_27_rodata_8080[];
extern char lbl_27_data_2E5F8[], lbl_27_data_2E430[], lbl_27_data_CDF8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_27_192278(void*, unsigned long);
void fn_27_89DAC(int, soModuleAccesser*);
}

static inline void enable(soKineticEnergy* e) {
    ((unsigned char*)e)[5] |= 0x80;
}

static inline void setSpeed(soKineticEnergy* e, const Vec2f& v) {
    *(float*)((char*)e + 0x18) = v.m_x;
    *(float*)((char*)e + 0x1c) = v.m_y;
    e->onConsiderGroundFriction();
}

static inline int rotationNode(soModuleAccesser* a) {
    int kind = a->getStageObject().soGetSubKind();
    int id;
    if (kind == 5)
        id = 0x197;
    else
        id = 4;
    return id;
}

static inline soKineticEnergy* stopEnergy(soModuleAccesser* a) {
    soKineticEnergy* energy = (soKineticEnergy*)__dynamic_cast(
        a->getKineticModule().getEnergy(3), 0,
        lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    return energy;
}

static inline soKineticEnergy* gravityEnergy(soModuleAccesser* a) {
    soKineticEnergy* energy = (soKineticEnergy*)__dynamic_cast(
        a->getKineticModule().getEnergy(1), 0,
        lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    return energy;
}

static inline void updateGravity(soKineticEnergy* gravity, Vec2f& gv, Vec3f& grot, soModuleAccesser* a) {
    gravity->resetEnergy(0, &gv, &grot, a);
    *(float*)((char*)gravity + 0x10) = -fn_27_192278(a, 0xfa0);
    *(float*)((char*)gravity + 0x1c) = fn_27_192278(a, 0xfa1);
    *(float*)((char*)gravity + 0x14) = fn_27_192278(a, 0xfa1);
    enable(gravity);
}

extern "C" void fn_27_3BF6D0(void*, soModuleAccesser* a) {
    const float* c = lbl_27_rodata_8080;
    int situation = a->getSituationModule().getKind();
    soKineticEnergy* previous = (soKineticEnergy*)a->getWorkManageModule().getInt(0x20000008);
    a->getWorkManageModule().setFloat(c[1], 0x21000009);
    a->getWorkManageModule().addFloat(fn_27_192278(a, 0xfb9), 0x21000005);

    if (a->getWorkManageModule().getFloat(0x21000005) >= fn_27_192278(a, 0xfb8)) {
        a->getWorkManageModule().setFloat(fn_27_192278(a, 0xfb8), 0x21000005);
        a->getWorkManageModule().onFlag(0x22000010);
        if ((int)a->getStageObject().soGetSubKind() == 5)
            a->getStatusModule().changeStatusRequest(0x186, a);
        else
            a->getStatusModule().changeStatusRequest(0x118, a);
    }

    float angle = a->getWorkManageModule().getFloat(0x21000006);
    float speed = a->getWorkManageModule().getFloat(0x21000005);
    float delta = c[5] * fn_27_192278(a, 0xfba);
    angle = angle + (speed * delta) * a->getWorkManageModule().getFloat(0x2100000a);
    while (angle < c[1])
        angle += c[6];
    while (angle > c[6])
        angle -= c[6];

    a->getWorkManageModule().setFloat(angle, 0x21000006);
    angle = a->getWorkManageModule().getFloat(0x21000006);
    int kind = a->getStageObject().soGetSubKind();
    int id;
    if (kind == 5)
        id = 0x197;
    else
        id = 4;

    Vec3f r = a->getModelModule().getNodeRotate(id);
    r.m_x = c[7] * angle;
    a->getModelModule().setNodeRotate(id, &r);

    id = rotationNode(a);
    Vec3f r2 = a->getModelModule().getNodeRotate(id);
    if (c[3] == a->getPostureModule().getLr())
        r2.m_y = c[4];
    else
        r2.m_y = c[1];
    a->getModelModule().setNodeRotate(id, &r2);

    if (situation != (int)previous) {
        if (situation == 0) {
            soKineticEnergy* stop = stopEnergy(a);
            float x = c[0] * a->getWorkManageModule().getFloat(0x21000011);
            Vec3f rot;
            rot.m_x = c[1];
            rot.m_y = c[1];
            rot.m_z = c[1];
            Vec2f v;
            v.m_x = x;
            v.m_y = c[1];
            stop->resetEnergy(0x16, &v, &rot, a);
            Vec2f newSpeed(x, c[1]);
            setSpeed(stop, newSpeed);
            enable(stop);
            a->getWorkManageModule().setFloat(fn_27_192278(a, 0xfa2), 0x21000008);
            fn_27_89DAC(1, a);
        } else {
            soKineticEnergy* stop = stopEnergy(a);
            previous = gravityEnergy(a);
            unsigned short flags = 1;
            Vec2f sum;
            SpeedPair pair = ((KineticView*)&a->getKineticModule())->getSumSpeed(flags);
            __memcpy(&sum, &pair, 8);
            Vec3f rot(c[1], c[1], c[1]);
            Vec2f v(sum.m_x, c[1]);
            stop->resetEnergy(6, &v, &rot, a);
            enable(stop);
            Vec3f grot(c[1], c[1], c[1]);
            Vec2f gv(c[1], sum.m_y);
            previous->resetEnergy(0, &gv, &grot, a);
            *(float*)((char*)previous + 0x10) = -fn_27_192278(a, 0xfa0);
            *(float*)((char*)previous + 0x1c) = fn_27_192278(a, 0xfa1);
            *(float*)((char*)previous + 0x14) = fn_27_192278(a, 0xfa1);
            enable(previous);
        }
    }

    a->getWorkManageModule().setInt(situation, 0x20000008);
}
