#pragma opt_propagation off
#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_95_data_7A88[];
extern const unsigned char lbl_95_data_2C38[];
extern const float lbl_95_rodata_B8[];
extern unsigned char g_ftCommonDataAccesser[];

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_95_10570(soModuleAccesser*, int);
float fn_95_A8B4(float);
struct V2R {
    float x, y;
    V2R(const float& a, const float& b) : x(a), y(b) { }
};
void fn_95_DF08(Vec2f*, const V2R*);
}

class KineticView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Vec2f getSumSpeed(short*);
};

class PostureView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual float getFacing();
};

struct Params95 {
    char pad[0x5c];
    int interval;
    float threshold;
    float mul;
    float y;
};

static inline void setEnergySpeed(void* energy, const V2R& v) {
    fn_95_DF08(reinterpret_cast<Vec2f*>(static_cast<char*>(energy) + 8), &v);
}

static inline void reqEffect(const Vec3f& pos, soEffectModule*& effect,
                             const Vec3f& rot, const float& scale) {
    effect->req(static_cast<EfID>(10), const_cast<Vec3f*>(&pos), const_cast<Vec3f*>(&rot), scale, 0, -1);
}

extern "C" void fn_95_127E0(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_95_rodata_B8;
    int count;
    Vec2f speed;
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soWorkManageModule* work = modules->m_workManageModule;
    soSituationModule* situation = modules->m_situationModule;
    soGroundModule* ground = modules->m_groundModule;
    KineticView* kinetic = reinterpret_cast<KineticView*>(modules->m_kineticModule);
    soPostureModule* posture = modules->m_postureModule;
    soModelModule* model = modules->m_modelModule;
    soEffectModule* effect;
    Params95* params = *reinterpret_cast<Params95**>(
        static_cast<char*>(
            getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 4)
        ) + 0x7c
    );

    bool active = situation->getKind() == 0;
    short all = -1;
    Vec2f::copy(speed, kinetic->getSumSpeed(&all));

    bool touch;
    if (speed.m_x > constants[0]) {
        touch = ground->isTouch(static_cast<grCollStatus::TouchMask>(4), 0);
        if (touch) {
            fn_95_10570(accesser, 4);
        }
    } else {
        touch = ground->isTouch(static_cast<grCollStatus::TouchMask>(2), 0);
        if (touch) {
            fn_95_10570(accesser, 2);
        }
    }

    if (touch) {
        speed.m_x *= -params->mul;
        speed.m_y = params->y;
        void* energy = __dynamic_cast(
            kinetic->getEnergy(3), 0,
            lbl_95_data_7A88, lbl_95_data_2C38, 1
        );
        setEnergySpeed(energy, V2R(speed.m_x, constants[0]));
        situation->setKind(static_cast<SituationKind>(2), false);
        ground->setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(5), 0);
        work->setInt(0x11a, 0x20000008);
        active = false;
    } else if (!active) {
        situation->setKind(static_cast<SituationKind>(2), false);
        ground->setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(5), 0);
        work->setInt(0x119, 0x20000008);
        if (constants[0] != work->getFloat(0x21000008)) {
            reinterpret_cast<PostureView*>(posture)->getFacing();
            work->setFloat(fn_95_A8B4(speed.m_x), 0x21000006);
        }
        model->setNodeRotateY(3, constants[0]);
        model->setNodeRotateZ(2, constants[0]);
    }

    if (active) {
        if (fn_95_A8B4(speed.m_x) > params->threshold) {
            ground->setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(1), 0);
        } else {
            ground->setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(2), 0);
        }

        count = work->getInt(0x20000004);
        if (count % params->interval == 0) {
            Vec2f normal;
            Vec2f::copy(
                normal,
                ground->getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0)
            );
            float angle = speed.m_x < constants[0] ? constants[8] : constants[4];
            reqEffect(posture->getPos(),
                      (effect = accesser->m_enumerationStart->m_effectModule, effect),
                      Vec3f(constants[0], angle, atan2f(-normal.m_x, normal.m_y)),
                      constants[9]);
        }
        work->setInt(count + 1, 0x20000004);
    }
}
