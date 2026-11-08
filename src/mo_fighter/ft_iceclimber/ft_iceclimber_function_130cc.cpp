#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/so_external_value_accesser.h>
#include <ft/fighter.h>
#include <ft/ft_owner.h>
#include <mt/mt_vector.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern char lbl_105_data_698[];
extern char lbl_105_data_3860[];
extern const float lbl_105_rodata_38;
extern const float lbl_105_rodata_3C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
int getStatusKind__23soExternalValueAccesserFP11StageObject(StageObject*);
Vec3f getPos__23soExternalValueAccesserFP11StageObject(StageObject*);
bool fn_105_C29C(int);
void fn_105_133E4(Vec2f*, const Vec3f*);
int fn_105_133F8(float);
float rsqrtf__Ff(float);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
}

namespace {
struct EventA : soLinkEventArgs {
    int value;

    EventA(int id, int v) : soLinkEventArgs(id), value(v) {}
};

struct EventB : soLinkEventArgs {
    int value;
    u8 flag2;

    EventB(int id, int v) : soLinkEventArgs(id), value(v), flag2(0) {}
};

struct PlanarPos : Vec2f {
    PlanarPos(const Vec3f& pos) { fn_105_133E4(this, &pos); }
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
    if ((float)fabs(sq) <= lbl_105_rodata_3C) {
        return lbl_105_rodata_38;
    }
    return sq * rsqrtf__Ff(sq);
}
}

extern "C" void fn_105_130CC(void*, soModuleAccesser* accesser) {
    accesser->getWorkManageModule().offFlag(0x22000010);
    accesser->getPostureModule().setStickLR(lbl_105_rodata_38);
    accesser->getPostureModule().updateRotYLr();
    if (accesser->getWorkManageModule().isFlag(0x1200003E) == false) {
        Fighter* fighter = (Fighter*)__dynamic_cast(
            &accesser->getStageObject(), 0x3c,
            lbl_105_data_698, lbl_105_data_3860, 0);
        if (fighter) {
            Fighter* partner = fighter->getPartner();
            if (partner) {
                if (fn_105_C29C(getStatusKind__23soExternalValueAccesserFP11StageObject(partner)) == true) {
                    Vec3f partnerPos3 = getPos__23soExternalValueAccesserFP11StageObject(partner);
                    Vec2f partnerPos;
                    fn_105_133E4(&partnerPos, &partnerPos3);
                    Vec3f myPos3 = accesser->getPostureModule().getPos();
                    Vec2f v;
                    Vec2f::copy(v, partnerPos - PlanarPos(myPos3));
                    if (!isValidVec(v)) {
                        return;
                    }
                    if (vecLength(v) < getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa7, 0)) {
                        accesser->getWorkManageModule().onFlag(0x22000010);
                        if (accesser->getLinkModule().isLink(6) == true) {
                            EventA ev(0x455, 0x117);
                            accesser->getLinkModule().sendEventNodes(6, ev, 0);
                            int kind = 0x1d6;
                            if (accesser->getSituationModule().getKind() != 0) {
                                kind = 0x1d7;
                            }
                            EventB param(0x456, kind);
                            accesser->getLinkModule().sendEventNodes(6, param, 0);
                            accesser->getLinkModule().setAttribute(6, (soLinkConnection::Attribute)0, true);
                        }
                    }
                }
            }
        }
    }
}
