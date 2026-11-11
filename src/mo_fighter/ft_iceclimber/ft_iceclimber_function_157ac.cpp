#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/so_external_value_accesser.h>
#include <ft/fighter.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern char lbl_105_data_698[];
extern char lbl_105_data_3860[];
extern const float lbl_105_rodata_70;
extern const float lbl_105_rodata_74;
void* __dynamic_cast(void*, long, const void*, const void*, short);
int getSituationKind__23soExternalValueAccesserFP11StageObject(StageObject*);
int getStatusKind__23soExternalValueAccesserFP11StageObject(StageObject*);
Vec3f getPos__23soExternalValueAccesserFP11StageObject(StageObject*);
float getLr__23soExternalValueAccesserFP11StageObject(StageObject*);
void fn_105_133E4(Vec2f*, const Vec3f*);
int fn_105_133F8(float);
float rsqrtf__Ff(float);
}

namespace {
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
    if ((float)(double)nw4r::math::FAbs(sq) <= lbl_105_rodata_74) {
        return lbl_105_rodata_70;
    }
    return sq * rsqrtf__Ff(sq);
}
}

extern "C" void fn_105_157AC(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x1200003e) == true) {
        Fighter* fighter = (Fighter*)__dynamic_cast(
            &accesser->getStageObject(), 0x3c,
            lbl_105_data_698, lbl_105_data_3860, 0);
        if (fighter) {
            Fighter* partner = fighter->getPartner();
            if (accesser->getSituationModule().getKind() == 0) {
                if (getSituationKind__23soExternalValueAccesserFP11StageObject(partner) == 0 &&
                    partner != 0 &&
                    getStatusKind__23soExternalValueAccesserFP11StageObject(partner) == 0x115) {
                    Vec3f partnerPos3 = getPos__23soExternalValueAccesserFP11StageObject(partner);
                    Vec2f partnerPos;
                    fn_105_133E4(&partnerPos, &partnerPos3);
                    Vec3f myPos3 = accesser->getPostureModule().getPos();
                    Vec2f v;
                    Vec2f::copy(v, partnerPos - PlanarPos(myPos3));
                    if (isValidVec(v)) {
                        float length = vecLength(v);
                        if (length < soValueAccesser::getConstantFloat(accesser, 0xfa6, 0)) {
                            accesser->getWorkManageModule().onFlag(0x22000010);
                            soPostureModule* posture = &accesser->getPostureModule();
                            posture->setLr(-getLr__23soExternalValueAccesserFP11StageObject(partner));
                            accesser->getPostureModule().updateRotYLr();
                        }
                    }
                }
            }
        }
    }
}