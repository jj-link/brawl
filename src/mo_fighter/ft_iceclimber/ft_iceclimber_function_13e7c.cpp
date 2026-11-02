#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <ft/fighter.h>
#include <ft/ft_owner.h>
#include <mt/mt_vector.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern char lbl_105_data_698[];
extern char lbl_105_data_3860[];
extern const float lbl_105_rodata_50;
extern const float lbl_105_rodata_54;
void* __dynamic_cast(void*, long, const void*, const void*, short);
int getStatusKind__23soExternalValueAccesserFP11StageObject(StageObject*);
Vec3f getPos__23soExternalValueAccesserFP11StageObject(StageObject*);
bool fn_105_C29C(int);
void fn_105_133E4(Vec2f*, const Vec3f*);
int fn_105_133F8(float);
float rsqrtf__Ff(float);
}

namespace {
struct StatusEvent : soLinkEventArgs {
    int status;

    StatusEvent(int value) : soLinkEventArgs(0x455), status(value) {}
};

struct ParamEvent : soLinkEventArgs {
    int value;
    bool flag;

    ParamEvent(int v) : soLinkEventArgs(0x456), value(v), flag(false) {}
};

struct PositionEvent : soLinkEventArgs {
    Vec3f pos;

    PositionEvent(const Vec3f& value) : soLinkEventArgs(0x459), pos(value) {}
};

struct ActionInfo {
    int kind;
    int id;

    ActionInfo(int k, int i) : kind(k), id(i) {}
};

// Vec2f built from the x/y of a Vec3f through fn_105_133E4.
struct PlanarPos : Vec2f {
    PlanarPos(const Vec3f& pos) { fn_105_133E4(this, &pos); }
};

// ftOwner as seen by this call: setLogActionInfo receives the info by address.
class ftOwnerView {
    void* m_data;
    void* m_input;
    short _8;
    u8 _10;
    u8 _11;

public:
    virtual ~ftOwnerView();
    virtual bool isSubOwner();
    virtual void setDamage(float damage, bool);
    virtual float getDamage();
    virtual void setStartDamage(float startDamage);
    virtual float getStartDamage();
    virtual float getHitPoint();
    virtual void setBeatCount(int playerIndex, int beatCount);
    virtual u32 getCheerDefeatFrame();
    virtual void setSuicideCount(short suicideCount);
    virtual void setLogFloat(float, u32 index1, u32 index2);
    virtual void addLogFloat(float, u32 index1, u32 index2);
    virtual void setLogInt(int, u32 index1, u32 index2);
    virtual void addLogInt(int, u32 index1, u32 index2);
    virtual void setLogFlag(bool, u32 index1, u32 index2);
    virtual void onLogFlag(u32 index1, u32 index2);
    virtual void offLogFlag(u32 index1, u32 index2);
    virtual void setLogActionInfo(const ActionInfo&);
};

inline int isValidVec(const Vec2f& v) {
    int ok = fn_105_133F8(v.m_x);
    if (ok) {
        ok = fn_105_133F8(v.m_y);
    }
    return ok;
}

inline float vecLength(const Vec2f& v) {
    float sq = v.m_x * v.m_x + v.m_y * v.m_y;
    if ((float)fabs(sq) <= lbl_105_rodata_54) {
        return lbl_105_rodata_50;
    }
    return sq * rsqrtf__Ff(sq);
}
}

extern "C" void fn_105_13E7C(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000012) == true) {
        accesser->getWorkManageModule().offFlag(0x22000012);
        Fighter* fighter = (Fighter*)__dynamic_cast(
            &accesser->getStageObject(), 0x3c,
            lbl_105_data_698, lbl_105_data_3860, 0);
        if (!fighter) {
            return;
        }
        Fighter* partner = fighter->getPartner();
        if (partner &&
            fn_105_C29C(getStatusKind__23soExternalValueAccesserFP11StageObject(partner)) == true) {
            Vec3f partnerPos3 = getPos__23soExternalValueAccesserFP11StageObject(partner);
            Vec2f partnerPos;
            fn_105_133E4(&partnerPos, &partnerPos3);
            Vec3f myPos3 = accesser->getPostureModule().getPos();
            Vec2f v;
            Vec2f::copy(v, partnerPos - PlanarPos(myPos3));
            if (!isValidVec(v)) {
                return;
            }
            if (vecLength(v) < soValueAccesser::getConstantFloat(accesser, 0xfbb, 0)) {
                accesser->getWorkManageModule().onFlag(0x22000010);
                if (accesser->getLinkModule().isLink(6) == true) {
                    StatusEvent status(0x11a);
                    accesser->getLinkModule().sendEventNodes(6, status, 0);
                    int kind = 0x1de;
                    if (accesser->getSituationModule().getKind() != 0) {
                        kind = 0x1df;
                    }
                    ParamEvent param(kind);
                    accesser->getLinkModule().sendEventNodes(6, param, 0);
                }
            }
        }
    }
    if (accesser->getWorkManageModule().isFlag(0x22000013) == true) {
        accesser->getWorkManageModule().offFlag(0x22000013);
        Fighter* fighter = (Fighter*)__dynamic_cast(
            &accesser->getStageObject(), 0x3c,
            lbl_105_data_698, lbl_105_data_3860, 0);
        if (fighter) {
            Fighter* partner = fighter->getPartner();
            if (partner &&
                getStatusKind__23soExternalValueAccesserFP11StageObject(partner) == 0x11a) {
                int status = 0x11b;
                if (accesser->getGroundModule().isStCliff(0) == true) {
                    status = 0x11d;
                }
                reinterpret_cast<ftOwnerView*>(fighter->getOwner())->setLogActionInfo(
                    ActionInfo(2, 0x3b));
                if (accesser->getLinkModule().isLink(6) == true) {
                    StatusEvent ev(status);
                    accesser->getLinkModule().sendEventNodes(6, ev, 0);
                    if (status == 0x11d) {
                        PositionEvent position(accesser->getGroundModule().getCliffPos(0));
                        accesser->getLinkModule().sendEventNodes(6, position, 0);
                    }
                }
            }
        }
    }
}
