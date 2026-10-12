#include <mo_fighter/ft_dedede/ft_dedede_reflect.h>

namespace {
// Partial interfaces for the team and reflection modules, whose full types
// are not yet represented by soModuleEnumeration.
class DededeReflectModule {
    unsigned char prefix[8];
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual void reserved10();
    virtual void reserved14();
    virtual void reserved18();
    virtual void reserved1C();
    virtual void reserved20();
    virtual void reserved24();
    virtual int getTeam();
    virtual int getLrTeam();
    virtual void reserved30();
    virtual void reserved34();
    virtual void reserved38();
    virtual bool isReflect();
};
class DededeTeamModule {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual void reserved10();
    virtual void setTeam(int, bool);
    virtual void reserved18();
    virtual void reserved1C();
    virtual void setLrTeam(int);
    virtual void setOwnerTeam(int);
};
inline DededeReflectModule* reflectModule(DededeReflectFighter* fighter) {
    return static_cast<DededeReflectModule*>(fighter->m_moduleAccesser->m_enumerationStart->m_reflectModule);
}
inline DededeTeamModule* teamModule(DededeReflectFighter* fighter) {
    return static_cast<DededeTeamModule*>(fighter->m_moduleAccesser->m_enumerationStart->m_teamModule);
}
}

extern "C" {
extern const float lbl_117_rodata_110;
extern const float lbl_117_rodata_108;
void fn_27_1DB174(DededeReflectFighter*, int, float, float);
}

extern "C" int fn_117_20610(DededeReflectFighter* fighter, u32 flags) {
    int result = 0;
    int update = 1;
    if (fighter->m_moduleAccesser->getWorkManageModule().getInt(0x20000004) == 2) {
        if (flags & 2) {
            fighter->resetReflect(0);
            result = 1;
        } else if (flags & 1) {
            result = 0;
        } else if (flags & 0x10) {
            result = 0;
        } else if (flags & 4) {
            if (fighter->reflectEnabled == 1) {
                result = fighter->onReflectHit();
                update = 0;
            } else {
                fighter->resetReflect(0);
                result = 1;
            }
        } else if (flags & 8) {
            if (reflectModule(fighter)->isReflect() == true) {
                fighter->m_moduleAccesser->getPostureModule().reverseLr();
                fighter->m_moduleAccesser->getPostureModule().updateRotYLr();
                int team = reflectModule(fighter)->getLrTeam();
                teamModule(fighter)->setTeam(team, true);
                teamModule(fighter)->setLrTeam(team);
                teamModule(fighter)->setOwnerTeam(reflectModule(fighter)->getTeam());
                result = fighter->onReflect();
                update = 0;
            }
        }
    } else {
        result = 0;
    }
    if (update && fighter->m_moduleAccesser->getWorkManageModule().getFloat(0x11000001) > lbl_117_rodata_110) {
        fn_27_1DB174(fighter, 0, fighter->m_moduleAccesser->getWorkManageModule().getFloat(0x11000001), lbl_117_rodata_108);
    }
    return result;
}
