#include <math.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
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
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48(float, float, float, unsigned char, signed char, unsigned long, bool);
};

static inline void requestMotion(soModuleAccesser* accesser, int kind) {
    soMotionChangeParam param;
    param.m_kind = kind;
    param.m_frame = 0.0f;
    param.m_rate = 0.0f;
    param._12 = 0;
    param._13 = 0;
    param._14 = 0;
    param._15 = 0;
    accesser->getMotionModule().changeMotionRequest(&param);
}

static inline Vec3f makePosition(float y, float x, float z) {
    Vec3f position;
    position.m_x = x;
    position.m_y = y;
    position.m_z = z;
    return position;
}

static inline void requestEffect(soModuleAccesser* accesser, float angle, const Vec2f& point) {
    Vec3f rotation(0.0f, 0.0f, -angle);
    Vec3f position = makePosition(point.m_y, point.m_x, 0.0f);
    int effect = accesser->getEffectModule().req(static_cast<EfID>(0x45), &position, &rotation, 1.0f, 0, -1);
    accesser->getWorkManageModule().setInt(effect, 0x20000001);
}

extern "C" void fn_27_17F608(void*, soModuleAccesser* accesser) {
    soDamageModule* damage = &accesser->getDamageModule();
    int motionKinds[4][3] = {
        {0x9e, 0x9b, 0x98},
        {0x9f, 0x9c, 0x99},
        {0xa0, 0x9d, 0x9a},
        {0, 0, 0},
    };
    soDamageLog* log = damage->getDamageLog();
    int motionVariant = soValueAccesser::getConstantInt(accesser, 0x59f3, 0);
    requestMotion(accesser, motionKinds[log->m_level][motionVariant]);

    soDamageModule* damageModule = &accesser->getDamageModule();
    float time = soValueAccesser::getConstantFloat(accesser, 0xd03, 0) * damageModule->getDamage(0)
                 + (log->m_reaction * soValueAccesser::getConstantFloat(accesser, 0xd02, 0)
                    + ((soValueAccesser::getConstantFloat(accesser, 0xcff, 0)
                        + soValueAccesser::getConstantFloat(accesser, 0xd01, 0)
                          * soValueAccesser::getConstantFloat(accesser, 0xdb2, 0))
                       + soValueAccesser::getConstantFloat(accesser, 0xd00, 0)
                         * (3 - soValueAccesser::getConstantInt(accesser, 0x5a88, 0))));

    soControllerModule* controller = &accesser->getControllerModule();
    float threshold = soValueAccesser::getConstantFloat(accesser, 0xd05, 0);
    float clatterRate = soValueAccesser::getConstantFloat(accesser, 0xd04, 0);
    reinterpret_cast<Object_vptr_0*>(controller)->slot48(time, clatterRate, threshold, 0, -1, 0, false);

    int node = accesser->getModelModule().getCorrectNodeId(0x12d);
    Vec3f rootPosition = accesser->getModelModule().getNodeGlobalPosition(0, false);
    Vec3f nodePosition = accesser->getModelModule().getNodeGlobalPosition(node, false);
    int frames = soValueAccesser::getConstantInt(accesser, 0x5a40, 0);
    float duration = static_cast<float>(frames - 1);
    accesser->getWorkManageModule().setFloat((nodePosition.m_y - rootPosition.m_y) / duration, 0x21000004);

    Vec2f normal;
    Vec2f::copy(normal, accesser->getGroundModule().getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0));
    float angle = atan2f(normal.m_x, normal.m_y);
    Vec2f point;
    Vec2f::copy(point, accesser->getGroundModule().getTouchPos(static_cast<grCollStatus::TouchMask>(8), 0));
    requestEffect(accesser, angle, point);
}