#include <types.h>
#include <gr/collision/gr_collision_joint.h>
#pragma force_active on

extern "C" {
extern const float lbl_57_rodata_198[];
extern const char lbl_57_data_E78[];
unsigned char* getInstance__16CameraControllerFv();
void fn_8009CEA8(void*, void*);
float fn_8016232C(float);
float fn_801622C4(float);
}

struct Vec3 { float x, y, z; };
struct Rect { int a, b, c; float d; };
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_57_590C();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_57_5894();
    virtual void fn_57_5968();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_57_3A9C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_57_638();
    virtual void fn_57_3A94();
    virtual void fn_57_3A90();
    virtual void fn_57_3978();
    virtual void fn_57_3A88();
    virtual void fn_57_3A7C();
    virtual void fn_57_3A6C();
    virtual void fn_57_3A5C();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2(Vec3*, u32, const char*);
};

struct Obj : Ground {
    char pad0[0x118];
    float* p158;
    u8* p15c;
    char pad1[0x14];
    grCollisionJoint* p174;
    grCollisionJoint* p178;
};

inline void setJoint(grCollisionJoint* p, bool active) {
    if (active) {
        p->m_0x54_4 = true;
        p->m_0x54_6 = p->m_0x54_4;
    } else {
        p->m_0x54_7 = false;
        p->m_0x54_4 = p->m_0x54_7;
        p->m_0x54_6 = p->m_0x54_4;
    }
}

extern "C" void fn_57_5D0C(Obj* self) {
    const float* rod = lbl_57_rodata_198;
    u8* p15c;
    float* p158;
    grCollisionJoint* p174;
    if ((p158 = self->p158) && (p15c = self->p15c) &&
        (p174 = self->p174) && self->p178) {
        switch (*p15c) {
        case 2: {
            if (*p158 > rod[2]) {
                setJoint(p174, false);
                setJoint(self->p178, false);
            } else if (*p158 > rod[4]) {
                setJoint(p174, true);
                setJoint(self->p178, true);
            } else if (*p158 > rod[3]) {
                setJoint(p174, true);
                setJoint(self->p178, false);
                self->p174->m_0x55_3 = true;
                self->p178->m_0x55_3 = true;
            } else {
                setJoint(p174, true);
                setJoint(self->p178, true);
                self->p174->m_0x55_3 = false;
                self->p178->m_0x55_3 = false;
            }
            if (*self->p158 > rod[2]) {
                Rect rect = *(Rect*)(getInstance__16CameraControllerFv() + 0x148);
                fn_8009CEA8(getInstance__16CameraControllerFv(), &rect);
                u8* controller = getInstance__16CameraControllerFv();
                *(float*)(controller + 0x18c) = rod[0];
                return;
            }
            float offset = rod[0];
            Vec3 pos;
            self->getNodePosition_2(&pos, 0, lbl_57_data_E78);
            Rect rect = *(Rect*)(getInstance__16CameraControllerFv() + 0x148);
            if (rect.d < pos.y) {
                rect.d = pos.y;
                u8* camera = getInstance__16CameraControllerFv() + 0x84;
                if (camera) {
                    float s = fn_8016232C(rod[5]);
                    float c = fn_801622C4(rod[5]);
                    rect.d -= rod[6] * (*(float*)(camera + 0x10) * (c / s));
                }
                offset = pos.y - rect.d;
            }
            fn_8009CEA8(getInstance__16CameraControllerFv(), &rect);
            *(float*)(getInstance__16CameraControllerFv() + 0x18c) = offset;
            return;
        }
        case 3:
            setJoint(p174, false);
            setJoint(self->p178, false);
            return;
        case 4:
            setJoint(p174, false);
            setJoint(self->p178, false);
            break;
        }
    }
}
