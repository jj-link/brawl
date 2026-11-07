#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

struct LucasSteeringSpeed {
    float x, y;
};

class LucasSteeringKinetic : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy();
    virtual void eraseEnergy();
    virtual void eraseEnergyAll();
    virtual void* getEnergy(int);
    virtual void isContain();
    virtual void updateEnergy();
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual LucasSteeringSpeed getSumSpeed(short*);
};

class Class_9054 {
public:
    virtual void fn_114_8BC0();
    virtual void fn_114_15064();
    virtual void fn_114_15CB4();
    virtual void fn_114_15CAC();
    virtual void fn_114_15CA4();
    virtual void fn_114_15C9C();
    virtual void fn_114_15C94();
    virtual void fn_114_15C8C();
    virtual void fn_114_15C84();
    virtual void fn_114_15C7C();
    virtual void fn_114_15C74();
    virtual void fn_114_15C6C();
    virtual void fn_114_15C64();
    virtual void fn_114_15C5C();
    virtual void fn_114_15C0C();
    virtual void fn_114_15C54();
    virtual float fn_114_15C44();
    virtual void fn_114_15C34();
    virtual float fn_114_15C24();
};

extern "C" {
extern const float lbl_114_rodata_110[];
extern const char lbl_114_data_7BC0[], lbl_114_data_3C7C[];
extern const char lbl_114_data_9140[], lbl_114_data_31DC[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_114_12B94(Vec3f*, float, float, float);
double fn_114_C4CC(double);
void fn_8003DE70(Vec3f*);
double fn_80400B30(double);

void fn_114_19BE8(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_114_rodata_110 + 1;
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    Class_9054* controller = reinterpret_cast<Class_9054*>(
        accesser->m_enumerationStart->m_controllerModule);
    LucasSteeringKinetic* kinetic = reinterpret_cast<LucasSteeringKinetic*>(
        accesser->m_enumerationStart->m_kineticModule);
    char* object = static_cast<char*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_114_data_7BC0, lbl_114_data_3C7C, 1));
    const float* parameters = *reinterpret_cast<const float**>(object + 0xddd0);

    float angle = work->getFloat(0x21000000);
    short attribute = 1;
    LucasSteeringSpeed sum = kinetic->getSumSpeed(&attribute);
    Vec3f speed;
    speed.m_x = sum.x;
    speed.m_y = sum.y;
    speed.m_z = constants[-1];

    float stickY = controller->fn_114_15C24();
    float stickX = controller->fn_114_15C44();
    Vec3f stick;
    fn_114_12B94(&stick, stickX, stickY, constants[-1]);

    if (fn_114_C4CC(stick.m_x) > parameters[3] ||
        fn_114_C4CC(stick.m_y) > parameters[3]) {
        fn_8003DE70(&stick);
        fn_8003DE70(&speed);

        float dot = speed.m_z * stick.m_z +
                    (speed.m_x * stick.m_x + speed.m_y * stick.m_y);
        float difference;
        if (dot >= constants[0] || dot <= constants[1])
            difference = constants[-1];
        else
            difference = fn_80400B30(dot);

        Vec3f cross;
        cross.m_x = speed.m_y * stick.m_z - speed.m_z * stick.m_y;
        cross.m_y = speed.m_z * stick.m_x - speed.m_x * stick.m_z;
        cross.m_z = speed.m_x * stick.m_y - speed.m_y * stick.m_x;

        if (difference >= constants[2]) {
            if (cross.m_z > constants[-1])
                angle += constants[3] * parameters[4];
            else
                angle -= constants[3] * parameters[4];
        } else {
            if (cross.m_z > constants[-1])
                angle += difference / (constants[4] / parameters[4]);
            else
                angle -= difference / (constants[4] / parameters[4]);
        }
    }

    while (angle < constants[6])
        angle += constants[5];
    while (angle > constants[5])
        angle -= constants[5];

    float cosine = cos(angle);
    speed.m_x = parameters[1] * cosine;
    float sine = sin(angle);
    speed.m_y = parameters[1] * sine;

    float* energy = static_cast<float*>(__dynamic_cast(
        kinetic->getEnergy(0), 0, lbl_114_data_9140, lbl_114_data_31DC, 1));
    Vec2f assigned(speed.m_x, speed.m_y);
    energy[2] = assigned.m_x;
    energy[3] = assigned.m_y;
    work->setFloat(angle, 0x21000000);
}
}
