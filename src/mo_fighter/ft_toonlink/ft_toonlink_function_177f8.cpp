#include <so/stageobject.h>
#include <so/so_module_accesser.h>

#pragma force_active on

struct InitFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct Init {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    InitFlags flags;
};

struct PhysicsPrefix { unsigned char prefix[8]; };
class Physics : public PhysicsPrefix {
public:
    virtual void slot_8() = 0;
    virtual void slot_c() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void initialize(u32, int, int, int, int, int, bool, int) = 0;
    virtual void slot_1c() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2c() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3c() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4c() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5c() = 0;
    virtual void slot_60() = 0;
    virtual void slot_64() = 0;
    virtual void slot_68() = 0;
    virtual void slot_6c() = 0;
    virtual void slot_70() = 0;
    virtual void slot_74() = 0;
    virtual void slot_78() = 0;
    virtual void slot_7c() = 0;
    virtual void slot_80() = 0;
    virtual void slot_84() = 0;
    virtual void slot_88() = 0;
    virtual void slot_8c() = 0;
    virtual void slot_90() = 0;
    virtual void slot_94() = 0;
    virtual void slot_98() = 0;
    virtual void slot_9c() = 0;
    virtual void slot_a0() = 0;
    virtual void setMode(int) = 0;
    virtual void slot_a8() = 0;
    virtual void slot_ac() = 0;
    virtual void slot_b0() = 0;
    virtual void slot_b4() = 0;
    virtual void slot_b8() = 0;
    virtual void slot_bc() = 0;
    virtual void slot_c0() = 0;
    virtual void slot_c4() = 0;
    virtual void slot_c8() = 0;
    virtual void slot_cc() = 0;
    virtual void slot_d0() = 0;
    virtual void slot_d4() = 0;
    virtual void slot_d8() = 0;
    virtual void setScale(float) = 0;
};

class ArticleManager {
public:
    virtual void slot_8() = 0;
    virtual void slot_c() = 0;
    virtual void slot_10() = 0;
    virtual soNullableInterface* getArticle(int, int, bool) = 0;
    virtual void slot_18() = 0;
    virtual void slot_1c() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2c() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void activate(soNullableInterface*) = 0;
};

inline soPostureModule& postureModuleFor(const soModuleEnumeration* modules) {
    return *modules->m_postureModule;
}

inline soResourceModule& resourceModuleFor(const soModuleEnumeration* modules) {
    return *modules->m_resourceModule;
}

extern "C" {
void fn_27_1D8370(void*, const Init*);
extern int lbl_121_data_9108;

void fn_121_177F8(StageObject* object, int resource, int team, int parameter,
                  Vec3f* position, bool mode, float facing)
{
    Init initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, position, sizeof(Vec3f));
    initialize.facing = facing;
    initialize.parameter = parameter;
    initialize.variant = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved2 = 0;
    initialize.motion = 0x35f;
    initialize.reserved3 = 0;
    initialize.flags.first = 1;
    initialize.flags.second = 1;
    initialize.flags.third = 0;
    initialize.flags.fourth = 0;
    initialize.flags.fifth = 1;
    initialize.flags.sixth = 0;
    initialize.flags.seventh = 0;
    initialize.flags.eighth = 0;
    initialize.flags.ninth = 0;
    initialize.flags.tenth = 0;
    fn_27_1D8370(object, &initialize);

    const soModuleEnumeration* initialModules = object->m_moduleAccesser->m_enumerationStart;
    soResourceModule* resourceModule = &resourceModuleFor(initialModules);
    Physics* selected = static_cast<Physics*>(initialModules->m_physicsModule);
    int resourceName = lbl_121_data_9108;
    soResourceIdAccesser* loaded = resourceModule->getResourceIdAccesser();
    u32 resourceObject = loaded->getBinResId();

    selected->initialize(resourceObject, 0, resourceName, resourceName,
                         1, 0, false, -1);

    object->m_moduleAccesser->getWorkManageModule().setFlag(mode, 0x22000000);
    object->m_moduleAccesser->getWorkManageModule().setInt(0x17, 0x10000005);

    ArticleManager* generate = static_cast<ArticleManager*>(
        object->m_moduleAccesser->m_enumerationStart->m_generateArticleManageModule);
    soNullableInterface* article = generate->getArticle(0, 0, false);
    if (!article->isNull()) {
        generate = static_cast<ArticleManager*>(
            object->m_moduleAccesser->m_enumerationStart->m_generateArticleManageModule);
        generate->activate(article);
    }

    object->m_moduleAccesser->getStatusModule().changeStatusForce(
        0, object->m_moduleAccesser);

    const soModuleEnumeration* modules = object->m_moduleAccesser->m_enumerationStart;
    soPostureModule* posture = &postureModuleFor(modules);
    selected = static_cast<Physics*>(modules->m_physicsModule);
    float scale = posture->getScale();
    selected->setScale(scale);

    Physics* physics = static_cast<Physics*>(
        object->m_moduleAccesser->m_enumerationStart->m_physicsModule);
    physics->setMode(6);
}
}
