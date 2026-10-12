#include <so/so_module_accesser.h>
#include <math.h>

struct NessSteeringSpeed { float x, y; };
// The kinetic interface returns two raw float words in r3/r4.
class NessSteeringKinetic : public soNullable {
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
    virtual NessSteeringSpeed getSumSpeed(short*);
};
struct NessSteeringConstants {
    float zero, upperDot, lowerDot, turnLimit, radiansPerDegree, turnDegrees, fullTurn, negativeTurn;
};
extern "C" {
extern const NessSteeringConstants lbl_101_rodata_F0;
extern const char lbl_101_data_83D0[], lbl_101_data_4330[];
extern const char lbl_101_data_9840[], lbl_101_data_3890[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_101_1303C(Vec3f*, float, float, float);
float fn_101_CA34(float);
void fn_8003DE70(Vec3f*);
double fn_80400B30(double);

void fn_101_1A078(void*, soModuleAccesser* accesser) {
    const NessSteeringConstants* constants = &lbl_101_rodata_F0;
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    soControllerModule* controller = accesser->m_enumerationStart->m_controllerModule;
    NessSteeringKinetic* kinetic = reinterpret_cast<NessSteeringKinetic*>(accesser->m_enumerationStart->m_kineticModule);
    char* object = static_cast<char*>(__dynamic_cast(accesser->m_stageObject, 0x3c,
        lbl_101_data_83D0, lbl_101_data_4330, 1));
    const float* parameters = *reinterpret_cast<const float**>(object + 0xddd0);
    float angle = work->getFloat(0x21000000);
    short attribute = 1;
    NessSteeringSpeed sum = kinetic->getSumSpeed(&attribute);
    Vec3f speed;
    speed.m_x = sum.x;
    speed.m_y = sum.y;
    speed.m_z = constants->zero;
    float stickY = controller->getStickY();
    float stickX = controller->getStickX();
    Vec3f stick;
    fn_101_1303C(&stick, stickX, stickY, constants->zero);
    if (fn_101_CA34(stick.m_x) > parameters[3] || fn_101_CA34(stick.m_y) > parameters[3]) {
        fn_8003DE70(&stick);
        fn_8003DE70(&speed);
        float dot = speed.m_z * stick.m_z + (speed.m_x * stick.m_x + speed.m_y * stick.m_y);
        float difference;
        if (dot >= constants->upperDot || dot <= constants->lowerDot) difference = constants->zero;
        else difference = fn_80400B30(dot);
        Vec3f cross;
        cross.m_x = speed.m_y * stick.m_z - speed.m_z * stick.m_y;
        cross.m_y = speed.m_z * stick.m_x - speed.m_x * stick.m_z;
        cross.m_z = speed.m_x * stick.m_y - speed.m_y * stick.m_x;
        if (difference >= constants->turnLimit) {
            if (cross.m_z > constants->zero) angle += constants->radiansPerDegree * parameters[4];
            else angle -= constants->radiansPerDegree * parameters[4];
        } else {
            if (cross.m_z > constants->zero) angle += difference / (constants->turnDegrees / parameters[4]);
            else angle -= difference / (constants->turnDegrees / parameters[4]);
        }
    }
    while (angle < constants->negativeTurn) angle += constants->fullTurn;
    while (angle > constants->fullTurn) angle -= constants->fullTurn;
    float cosine = cos(angle);
    speed.m_x = parameters[1] * cosine;
    float sine = sin(angle);
    speed.m_y = parameters[1] * sine;
    float* energy = static_cast<float*>(__dynamic_cast(kinetic->getEnergy(0), 0,
        lbl_101_data_9840, lbl_101_data_3890, 1));
    Vec2f assigned(speed.m_x, speed.m_y);
    energy[2] = assigned.m_x;
    energy[3] = assigned.m_y;
    work->setFloat(angle, 0x21000000);
}
}
