#include <so/so_module_accesser.h>
#include <math.h>

// The common enumeration keeps the physics module opaque. Preserve its
// dispatch layout and describe only the operations used by this update.
class NessFinalMovementPhysics : private soNull, public soNullable {
public:
    virtual ~NessFinalMovementPhysics();
private:
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2C() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3C() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4C() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5C() = 0;
    virtual void slot_60() = 0;
public:
    virtual void setMode(int) = 0;
    virtual void updatePosition(const Vec3f*, const Vec3f*) = 0;
private:
    virtual void slot_6C() = 0;
    virtual void slot_70() = 0;
    virtual void slot_74() = 0;
    virtual void slot_78() = 0;
    virtual void slot_7C() = 0;
    virtual void slot_80() = 0;
    virtual void slot_84() = 0;
    virtual void slot_88() = 0;
public:
    virtual void setNode(int) = 0;
private:
    virtual void slot_90() = 0;
    virtual void slot_94() = 0;
    virtual void slot_98() = 0;
    virtual void slot_9C() = 0;
    virtual void slot_A0() = 0;
    virtual void slot_A4() = 0;
    virtual void slot_A8() = 0;
    virtual void slot_AC() = 0;
    virtual void slot_B0() = 0;
    virtual void slot_B4() = 0;
    virtual void slot_B8() = 0;
    virtual void slot_BC() = 0;
    virtual void slot_C0() = 0;
    virtual void slot_C4() = 0;
    virtual void slot_C8() = 0;
    virtual void slot_CC() = 0;
    virtual void slot_D0() = 0;
public:
    virtual bool isReady() = 0;
};
struct NessFinalMovementEvent : soLinkEventArgs {
    float step;
    Vec2f speed, acceleration, limit;
    NessFinalMovementEvent(float value) : soLinkEventArgs(0x838), step(value) {}
};
extern "C" {
extern const float lbl_101_rodata_158[4] = { 0.0f, 0.001f, 1.1754944e-38f, 0.0f };
extern const unsigned char lbl_101_data_80F8[], lbl_101_data_4330[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_101_CA34(float);
void fn_101_2163C(const Vec3f*, const Vec3f*, Vec3f*);
void fn_101_21660(Vec3f*, const Vec3f*, const Vec3f*);
void fn_101_21684(Vec3f*, const Vec3f*, float);
Vec3f* fn_101_1C628(Vec3f*, const Vec3f*);
void fn_8003DE70(Vec3f*);
float rsqrtf(float);

void fn_101_20F6C(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_101_rodata_158;
    __dynamic_cast(accesser->m_stageObject, 0x3c, lbl_101_data_80F8, lbl_101_data_4330, 1);
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
    NessFinalMovementPhysics* physics = static_cast<NessFinalMovementPhysics*>(accesser->m_enumerationStart->m_physicsModule);
    if (work->isFlag(0x22000001)) {
        physics->setMode(1);
        work->onFlag(0x22000002);
        work->offFlag(0x22000001);
    }
    float step = work->getFloat(0x21000000);
    Vec3f current = link->getModelConstraintTargetNodePosition();
    Vec3f destination(constants[0], constants[0], constants[0]);
    Vec3f direction, returnDirection;
    Vec3f advanced, scaled;
    if (work->isFlag(0x22000002)) {
        destination.m_x = work->getFloat(0x21000002);
        destination.m_y = work->getFloat(0x21000003);
        if (physics->isReady()) {
            physics->setMode(2);
            accesser->m_enumerationStart->m_statusModule->changeStatusRequest(-1, accesser);
        } else if (link->getParentSituationKind(5)) {
            Vec2f speed, acceleration, limit;
            speed.m_x = work->getFloat(0x21000004);
            speed.m_y = work->getFloat(0x21000005);
            acceleration.m_x = work->getFloat(0x21000006);
            acceleration.m_y = work->getFloat(0x21000007);
            limit.m_x = work->getFloat(0x21000008);
            limit.m_y = work->getFloat(0x21000009);
            destination.m_y += speed.m_y;
            speed.m_x += acceleration.m_x;
            speed.m_y += acceleration.m_y;
            if (fn_101_CA34(speed.m_x) > limit.m_x) {
                if (speed.m_x > constants[0]) speed.m_x = limit.m_x;
                else if (speed.m_x < constants[0]) speed.m_x = -limit.m_x;
            }
            if (fn_101_CA34(speed.m_y) > limit.m_y) {
                if (speed.m_y > constants[0]) speed.m_y = limit.m_y;
                else if (speed.m_y < constants[0]) speed.m_y = -limit.m_y;
            }
            work->setFloat(destination.m_x, 0x21000002);
            work->setFloat(destination.m_y, 0x21000003);
            work->setFloat(speed.m_x, 0x21000004);
            work->setFloat(speed.m_y, 0x21000005);
        }
        fn_101_2163C(&destination, &current, &direction);
        fn_8003DE70(&direction);
        fn_101_21684(&scaled, &direction, step);
        fn_101_21660(&advanced, &scaled, &current);
        fn_101_1C628(&destination, &advanced);
        step -= constants[1];
        work->setFloat(step, 0x21000000);
    } else {
        Vec3f parent = link->getParentModelNodeGlobalPosition(5, work->getInt(0x20000000), false);
        Vec3f returnAdvanced, returnScaled, difference;
        fn_101_1C628(&destination, &parent);
        fn_101_2163C(&current, &destination, &difference);
        float square = difference.m_z * difference.m_z + (difference.m_x * difference.m_x + difference.m_y * difference.m_y);
        float distance;
        if (static_cast<float>(fabs(square)) <= constants[2]) distance = constants[0];
        else distance = square * rsqrtf(square);
        if (distance > step) {
            fn_101_2163C(&destination, &current, &returnDirection);
            fn_8003DE70(&returnDirection);
            fn_101_21684(&returnScaled, &returnDirection, step);
            fn_101_21660(&returnAdvanced, &returnScaled, &current);
            fn_101_1C628(&destination, &returnAdvanced);
            work->onFlag(0x22000001);
            NessFinalMovementEvent event(work->getFloat(0x21000000));
            link->sendEventParents(5, event);
            work->setFloat(event.speed.m_x, 0x21000004);
            work->setFloat(event.speed.m_y, 0x21000005);
            work->setFloat(event.acceleration.m_x, 0x21000006);
            work->setFloat(event.acceleration.m_y, 0x21000007);
            work->setFloat(fn_101_CA34(event.limit.m_x), 0x21000008);
            work->setFloat(fn_101_CA34(event.limit.m_y), 0x21000009);
        }
        work->setFloat(destination.m_x, 0x21000002);
        work->setFloat(destination.m_y, 0x21000003);
    }
    physics->updatePosition(&current, &destination);
    physics->setNode(work->getInt(0x20000001));
}
}
