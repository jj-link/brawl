#include <so/so_module_accesser.h>
#include <so/link/so_link_event_presenter.h>
#pragma force_active on

struct SnakeObj {
    char pad[0x60];
    soModuleAccesser* accesser;
};

namespace {
struct SnakeLinkEvent : soLinkEventArgs {
    SnakeLinkEvent(int kind) : soLinkEventArgs(kind) {}
};

class SnakeReflectModule {
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
};

class SnakeTeamModule {
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

inline SnakeReflectModule* reflectModule(SnakeObj* self) {
    return static_cast<SnakeReflectModule*>(self->accesser->m_enumerationStart->m_reflectModule);
}
inline SnakeTeamModule* teamModule(SnakeObj* self) {
    return static_cast<SnakeTeamModule*>(self->accesser->m_enumerationStart->m_teamModule);
}
}

extern "C" {
extern const float lbl_122_rodata_130[];
extern const unsigned char lbl_122_data_10750[], lbl_122_data_81AC[];
void fn_122_27124(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" int fn_122_26C28(SnakeObj* self) {
    const float* constants = lbl_122_rodata_130;
    SnakeTeamModule* owner;
    u32 changed = 0;

    if (self->accesser->getStatusModule().getStatusKind() == 0 &&
        self->accesser->getWorkManageModule().isFlag(0x22000002)) {
        self->accesser->getWorkManageModule().offFlag(0x22000002);
        changed = 1;
    } else if (self->accesser->getStatusModule().getStatusKind() == 1) {
        if (self->accesser->getWorkManageModule().isFlag(0x22000001)) {
            self->accesser->getWorkManageModule().offFlag(0x22000001);
            changed = 1;
        }
    }

    if (changed != 0) {
        fn_122_27124(self);
        SnakeLinkEvent event(0x839);
        self->accesser->getLinkModule().sendEventParents(3, event);
        int team = reflectModule(self)->getLrTeam();
        teamModule(self)->setTeam(team, true);
        teamModule(self)->setLrTeam(team);
        SnakeReflectModule* reflect = reflectModule(self);
        owner = teamModule(self);
        owner->setOwnerTeam(reflect->getTeam());
        char* energy = (char*)__dynamic_cast(self->accesser->getKineticModule().getEnergy(2), 0, lbl_122_data_10750, lbl_122_data_81AC, 0);
        if (energy != NULL) {
            float f = *(float*)(energy + 0x34) - constants[14];
            if (f < constants[3]) {
                f += constants[10];
            }
            *(float*)(energy + 0x34) = f;
            Vec3f rot;
            rot.m_x = -f;
            rot.m_y = constants[9];
            rot.m_z = constants[3];
            self->accesser->getPostureModule().setRot(&rot, 1);
        }
        return 0;
    }

    owner = (SnakeTeamModule*)0;
    if (self->accesser->getStatusModule().getStatusKind() == 0) {
        if (self->accesser->getWorkManageModule().isFlag(0x22000001)) {
            owner = (SnakeTeamModule*)1;
        }
    }
    constants = (const float*)1;
    if (owner == 0) {
        owner = (SnakeTeamModule*)0;
        if (self->accesser->getStatusModule().getStatusKind() == 1) {
            if (self->accesser->getWorkManageModule().isFlag(0x22000000)) {
                owner = (SnakeTeamModule*)1;
            }
        }
        if (owner == 0) {
            constants = (const float*)0;
        }
    }
    if (constants == (const float*)1) {
        self->accesser->getStatusModule().changeStatusRequest(2, self->accesser);
        return 1;
    }
    return 0;
}
