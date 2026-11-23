#include <ft/ft_manager.h>
#include <mt/mt_common.h>
#include <nw4r/math/math_arithmetic.h>
#include <so/so_value_accesser.h>

#pragma force_active on
#pragma fp_contract off

#define SLOT(n) virtual void slot##n()
#define SLOTS_8(a, b, c, d, e, f, g, h) \
    SLOT(a); SLOT(b); SLOT(c); SLOT(d); \
    SLOT(e); SLOT(f); SLOT(g); SLOT(h)

class StatusModule {
public:
    SLOTS_8(00, 01, 02, 03, 04, 05, 06, 07);
    SLOTS_8(08, 09, 10, 11, 12, 13, 14, 15);
    virtual int getStatus();
};

class WorkModule {
public:
    SLOTS_8(00, 01, 02, 03, 04, 05, 06, 07);
    SLOTS_8(08, 09, 10, 11, 12, 13, 14, 15);
    SLOT(16);
    virtual unsigned int isFlag(unsigned int);
};

class SituationModule {
public:
    SLOT(00);
    SLOT(01);
    SLOT(02);
    virtual int getSituation();
};

class VectorModule {
public:
    SLOTS_8(00, 01, 02, 03, 04, 05, 06, 07);
    SLOT(08);
    SLOT(09);
    SLOT(10);
    SLOT(11);
    SLOT(12);
    virtual unsigned long long getVector(short*);
};

class ControllerModule {
public:
    SLOTS_8(00, 01, 02, 03, 04, 05, 06, 07);
    SLOTS_8(08, 09, 10, 11, 12, 13, 14, 15);
    virtual float getStickX();
    SLOT(17);
    virtual float getStickY();
    SLOTS_8(19, 20, 21, 22, 23, 24, 25, 26);
    SLOTS_8(27, 28, 29, 30, 31, 32, 33, 34);
    SLOTS_8(35, 36, 37, 38, 39, 40, 41, 42);
    SLOTS_8(43, 44, 45, 46, 47, 48, 49, 50);
    SLOTS_8(51, 52, 53, 54, 55, 56, 57, 58);
    SLOT(59);
    SLOT(60);
    virtual float getSubStickX();
    virtual unsigned char getFlickStick();
    virtual unsigned char getFlickSubStick();
    virtual void resetFlickStick();
    virtual void resetFlickSubStick();
};

struct CollisionLog {
    char pad00[0x10];
    unsigned char category;
    char pad11[3];
    int taskId;
    char pad18[8];
    int entryId;
};

struct CollisionModuleBase {
    char pad[8];
};

class CollisionModule : public CollisionModuleBase {
public:
    SLOTS_8(00, 01, 02, 03, 04, 05, 06, 07);
    SLOTS_8(08, 09, 10, 11, 12, 13, 14, 15);
    SLOTS_8(16, 17, 18, 19, 20, 21, 22, 23);
    SLOTS_8(24, 25, 26, 27, 28, 29, 30, 31);
    SLOT(32);
    SLOT(33);
    virtual void getLog(CollisionLog*);
};

struct TaskBase {
    char pad[0x3c];
};

class FighterTask : public TaskBase {
public:
    SLOTS_8(00, 01, 02, 03, 04, 05, 06, 07);
    SLOTS_8(08, 09, 10, 11, 12, 13, 14, 15);
    SLOTS_8(16, 17, 18, 19, 20, 21, 22, 23);
    SLOTS_8(24, 25, 26, 27, 28, 29, 30, 31);
    SLOTS_8(32, 33, 34, 35, 36, 37, 38, 39);
    virtual unsigned int getKind();
};

struct OwnerBase {
    void* data;
    char pad[8];
};

class Owner : public OwnerBase {
public:
    SLOTS_8(00, 01, 02, 03, 04, 05, 06, 07);
    SLOT(08);
    SLOT(09);
    virtual void setFloat(float, int, int);
    virtual void addFloat(float, int, int);
    virtual void setInt(int, int, int);
    virtual void setFlag(int, int, int);
};

struct Modules {
    char pad00[0x14];
    SituationModule* situation;
    char pad18[0x20];
    CollisionModule* collision;
    char pad3c[0x20];
    ControllerModule* controller;
    char pad60[4];
    WorkModule* work;
    char pad68[8];
    StatusModule* status;
    char pad74[8];
    VectorModule* vector;
};

struct Accesser {
    char pad00[8];
    FighterTask* fighter;
    char pad0c[0xcc];
    Modules* modules;
};

struct Selector {
    short value;
};

struct VectorWords {
    unsigned int x;
    unsigned int y;
};

extern "C" {
    unsigned int* fn_27_14554C(void*, unsigned int, unsigned int);
    float fn_27_1D53A0(void*, int, int);
    int fn_27_1D53E4(void*, int, int);

    extern float lbl_27_rodata_2724;
    extern float lbl_27_rodata_2728;
}

extern "C" void fn_27_1D66B4(Accesser* accesser, Owner* owner) {
    CollisionLog log;
    int status = accesser->modules->status->getStatus();
    if (status == 0x10b || accesser->modules->work->isFlag(0x12000018) == 1)
        return;
    {
        unsigned int flags = *fn_27_14554C(
            &g_ftCommonDataAccesser, accesser->fighter->getKind(), status);
        int kind = (flags >> 19) & 7;
        Selector selector;
        selector.value = 2;
        VectorWords words[2];
        unsigned long long bits[2];
        bits[1] = accesser->modules->vector->getVector(&selector.value);
        words[1] = *reinterpret_cast<VectorWords*>(&bits[1]);
        Vec2f& velocity = *reinterpret_cast<Vec2f*>(&words[1]);
        float squared = velocity.lengthSq();
        float magnitude;
        if ((float)(double)nw4r::math::FAbs(squared) <= lbl_27_rodata_2728)
            magnitude = lbl_27_rodata_2724;
        else
            magnitude = squared * rsqrtf(squared);

        if (lbl_27_rodata_2724 != magnitude) {
            owner->addFloat(magnitude, 0x0f, 0);
            if (magnitude > fn_27_1D53A0((char*)owner->data + 0x9e8, 0x10, 0))
                owner->setFloat(magnitude, 0x10, 0);

            accesser->modules->collision->getLog(&log);
            if (log.category == 10 && g_ftManager->isValidEntryId(log.entryId) == 1) {
                int entry = g_ftManager->getEntryIdFromTaskId(log.taskId, 0);
                if (entry != -1) {
                    Owner* other = reinterpret_cast<Owner*>(g_ftManager->getOwner(entry));
                    if (magnitude > fn_27_1D53A0(
                                        (char*)other->data + 0x9e8, 0x11, 0))
                        other->setFloat(magnitude, 0x11, 0);
                }
            }
        }

        Selector selector2;
        selector2.value = 1;
        bits[0] = accesser->modules->vector->getVector(&selector2.value);
        words[0] = *reinterpret_cast<VectorWords*>(&bits[0]);
        Vec2f& movement = *reinterpret_cast<Vec2f*>(&words[0]);
        squared = movement.lengthSq();

        if (lbl_27_rodata_2724 != squared) {
            if (kind == 1) {
                float length;
                if ((float)(double)nw4r::math::FAbs(squared) <= lbl_27_rodata_2728)
                    length = lbl_27_rodata_2724;
                else
                    length = squared * rsqrtf(squared);
                owner->addFloat(length, 0x14, 0);
            } else if (accesser->modules->situation->getSituation() == 0) {
                squared = movement.m_x * movement.m_x + movement.m_y * movement.m_y;
                float length;
                if ((float)(double)nw4r::math::FAbs(squared) <= lbl_27_rodata_2728)
                    length = lbl_27_rodata_2724;
                else
                    length = squared * rsqrtf(squared);
                owner->addFloat(length, 0x0c, 0);
            } else if (accesser->modules->situation->getSituation() == 2) {
                if (movement.m_y < lbl_27_rodata_2724)
                    owner->addFloat((float)(double)nw4r::math::FAbs(movement.m_y),
                                    0x0e, 0);
                else if (movement.m_y > lbl_27_rodata_2724)
                    owner->addFloat((float)(double)nw4r::math::FAbs(movement.m_y),
                                    0x0d, 0);
            }
        }

        switch (accesser->modules->situation->getSituation()) {
        case 3:
            owner->setFlag(1, 0x29, 0);
            break;
        case 0:
        case 6:
            owner->setFlag(1, 0x28, 0);
            break;
        case 1:
        case 2:
            owner->setFlag(1, 0x27, 0);
            break;
        }

        int previousCount = fn_27_1D53E4((char*)owner->data + 0x9e8, 0x21, 0);
        int maximumCount = fn_27_1D53E4((char*)owner->data + 0x9e8, 0x20, 0);
        int count = previousCount + 1;
        if (count > maximumCount)
            owner->setInt(count, 0x20, 0);
        owner->setInt(count, 0x21, 0);

        if (accesser->modules->work->isFlag(0x12000014) ||
            accesser->modules->work->isFlag(0x12000015) ||
            accesser->modules->work->isFlag(0x12000012) ||
            accesser->modules->work->isFlag(0x12000013))
            owner->setFlag(1, 0x3a, 0);

        float stickThreshold = soValueAccesser::getConstantFloat(
            reinterpret_cast<soModuleAccesser*>(accesser), 0xda5, 0);
        float subThreshold = soValueAccesser::getConstantFloat(
            reinterpret_cast<soModuleAccesser*>(accesser), 0xda6, 0);
        float flickThreshold = soValueAccesser::getConstantFloat(
            reinterpret_cast<soModuleAccesser*>(accesser), 0xda7, 0);

        previousCount = (int)accesser->modules->controller;
            float x = ((ControllerModule*)previousCount)->getStickX();
            float y = ((ControllerModule*)previousCount)->getStickY();
            if (mtSqrtf(x * x + y * y) >= stickThreshold &&
                (float)((ControllerModule*)previousCount)->getFlickStick() < flickThreshold) {
                owner->setFlag(1, 0x1f, 0);
                ((ControllerModule*)previousCount)->resetFlickStick();
            }

            if (nw4r::math::FAbs(((ControllerModule*)previousCount)->getSubStickX()) >= subThreshold &&
                (float)((ControllerModule*)previousCount)->getFlickSubStick() < flickThreshold) {
                owner->setFlag(1, 0x1f, 0);
                ((ControllerModule*)previousCount)->resetFlickSubStick();
            }
    }
done:
    return;
}
