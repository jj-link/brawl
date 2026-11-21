#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/damage/so_damage_module_impl.h>
#include <so/effect/so_effect_module_impl.h>
#include <so/collision/so_collision_hit_module_impl.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/link/so_link_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" const float lbl_120_rodata_8;
extern "C" void fn_27_12D904(void*, bool, bool, int);

namespace {

struct FtRobotLinkEvent : soLinkEventArgs {
    FtRobotLinkEvent(int eventKind) : soLinkEventArgs(eventKind) {}
};

struct FtRobotLinkEventWithFlag : soLinkEventArgs {
    int m_flag;
    FtRobotLinkEventWithFlag(int eventKind) : soLinkEventArgs(eventKind), m_flag(-1) {}
};

// soModuleEnumeration holds these as void* in the header, so the layouts are declared locally.
struct FtRobotArticle {
    virtual int get();
};

struct FtRobotArticleManager {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual FtRobotArticle* create(int, int, bool);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void release(FtRobotArticle*);
    virtual void slot14();
    virtual void slot15();
    virtual void notify(int, int);
};

struct FtRobotFighter {
    unsigned char pad[0x60];
    soModuleAccesser* accesser;
};

inline soDamageModule& ftRobotDamage(const soModuleEnumeration* mods) {
    return *mods->m_damageModule;
}

struct FtRobotEffectModule {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37();
    virtual void reqCommon(int, float);
};

}

extern "C" void fn_120_8B7C(void* self, soModuleAccesser* accesser) {
    const soModuleEnumeration* mods = accesser->m_enumerationStart;
    void* const articleRaw = mods->m_generateArticleManageModule;
    soDamageModule& damage = ftRobotDamage(mods);

    damage.setReactionMul(soValueAccesser::getConstantFloat(accesser, 0xFD4, 0));
    accesser->getCollisionHitModule().setWhole(2, 0);
    if (accesser->getWorkManageModule().isFlag(0x12000043)) {
        if (accesser->getWorkManageModule().getInt(0x10000042) > 0) {
            accesser->getWorkManageModule().subInt(1, 0x10000042);
            if (accesser->getWorkManageModule().getInt(0x10000042) <= soValueAccesser::getConstantInt(accesser, 0x5DCA, 0)) {
                if (!accesser->getWorkManageModule().isFlag(0x12000046)) {
                    accesser->getWorkManageModule().onFlag(0x12000046);
                    reinterpret_cast<FtRobotEffectModule*>(&accesser->getEffectModule())->reqCommon(0x25, lbl_120_rodata_8);
                }
            }
            if (accesser->getWorkManageModule().getInt(0x10000042) == 0) {
                accesser->getWorkManageModule().offFlag(0x12000042);
                accesser->getWorkManageModule().offFlag(0x12000043);
                accesser->getWorkManageModule().offFlag(0x12000045);
                reinterpret_cast<FtRobotArticleManager*>(articleRaw)->notify(3, 0);
                accesser->getCollisionHitModule().setWhole(0, 0);
                accesser->getEffectModule().removeCommon(0x26);
                accesser->getEffectModule().removeCommon(0x25);
                fn_27_12D904(self, true, true, 0);
                accesser->getControllerModule().stopRumbleKind(2, 8);
            } else if (accesser->getWorkManageModule().getInt(0x10000042) == 1) {
                FtRobotLinkEvent ev(0x838);
                accesser->getLinkModule().sendEventNodes(1, ev, 0);
            }
        }
    }
    if (accesser->getWorkManageModule().isFlag(0x12000044)) {
        FtRobotArticleManager* article = reinterpret_cast<FtRobotArticleManager*>(articleRaw);
        FtRobotArticle* obj = article->create(3, 0, false);
        if (obj->get() == 0) {
            article->release(obj);
        }
        accesser->getWorkManageModule().offFlag(0x12000044);
        accesser->getWorkManageModule().onFlag(0x12000045);
    }
    if (accesser->getWorkManageModule().isFlag(0x12000045) &&
        soValueAccesser::getConstantInt(accesser, 0x5DCB, 0) > 1) {
        accesser->getWorkManageModule().subInt(1, 0x10000043);
        if (accesser->getWorkManageModule().getInt(0x10000043) <= 0) {
            FtRobotLinkEventWithFlag ev(0x839);
            accesser->getLinkModule().sendEventNodes(1, ev, 0);
            accesser->getControllerModule().stopRumbleKind(2, 8);
            if (ev.m_flag != 1) {
                accesser->getControllerModule().setRumble(2, 0, false, 8);
            }
            soWorkManageModule& wm2 = reinterpret_cast<FtRobotFighter*>(self)->accesser->getWorkManageModule();
            wm2.setInt(soValueAccesser::getConstantInt(accesser, 0x5DCC, 0), 0x10000043);
        }
    }
}
