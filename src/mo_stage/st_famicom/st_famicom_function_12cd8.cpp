#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Vec3 {
    float x, y, z;
};

extern const float lbl_68_rodata_208;
extern const float lbl_68_rodata_20C;

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_68_12CD8();
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
    virtual void fn_68_12C80();
    virtual void fn_68_131D8();
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
    virtual void fn_68_249C();
    virtual void startup();
    virtual void fn_68_136FC();
    virtual void fn_68_97C();
    virtual void fn_68_2494();
    virtual void fn_68_2490();
    virtual void fn_68_2390();
    virtual void fn_68_2488();
    virtual void fn_68_247C();
    virtual void fn_68_246C();
    virtual void fn_68_B50();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3* pos, unsigned int a, unsigned int node);

    char pad1[0x118];
    Vec3* m_a;
    Vec3* m_b;
    Vec3* m_c;
    Vec3* m_d;
    char pad2[0x10];
    unsigned int m_nodesA[7];
    unsigned int m_nodesB[1];
    unsigned int m_nodesC[4];
    unsigned int m_nodesD[4];
};

extern "C" void processAnim__6GroundFv(void*);

static inline int isZeroF(float f) {
    int r = 0;
    if ((float)__fabs(f) < lbl_68_rodata_208) {
        r = 1;
    }
    return r;
}

static inline bool isZeroVec(const Vec3* v) {
    bool r = false;
    if (isZeroF(v->x) && isZeroF(v->y) && isZeroF(v->z)) {
        r = true;
    }
    return r;
}

extern "C" void fn_68_12CD8(Ground* self) {
    processAnim__6GroundFv(self);

    if (self->m_a) {
        if (isZeroVec(self->m_a) == true) {
            self->getNodePosition(&self->m_a[0], 0, self->m_nodesA[0]);
            self->getNodePosition(&self->m_a[1], 0, self->m_nodesA[1]);
            self->m_a[1].x -= lbl_68_rodata_20C;
            self->getNodePosition(&self->m_a[2], 0, self->m_nodesA[2]);
            self->m_a[2].x += lbl_68_rodata_20C;
            self->getNodePosition(&self->m_a[3], 0, self->m_nodesA[3]);
            self->getNodePosition(&self->m_a[4], 0, self->m_nodesA[4]);
            self->getNodePosition(&self->m_a[5], 0, self->m_nodesA[5]);
            self->getNodePosition(&self->m_a[6], 0, self->m_nodesA[6]);
        }
    }

    if (self->m_b) {
        if (isZeroVec(self->m_b) == true) {
            self->getNodePosition(&self->m_b[0], 0, self->m_nodesB[0]);
        }
    }

    if (self->m_c) {
        if (isZeroVec(self->m_c) == true) {
            self->getNodePosition(&self->m_c[0], 0, self->m_nodesC[0]);
            self->getNodePosition(&self->m_c[1], 0, self->m_nodesC[1]);
            self->getNodePosition(&self->m_c[2], 0, self->m_nodesC[2]);
            self->getNodePosition(&self->m_c[3], 0, self->m_nodesC[3]);
        }
    }

    if (self->m_d) {
        if (isZeroVec(self->m_d) == true) {
            self->getNodePosition(&self->m_d[0], 0, self->m_nodesD[0]);
            self->getNodePosition(&self->m_d[1], 0, self->m_nodesD[1]);
            self->getNodePosition(&self->m_d[2], 0, self->m_nodesD[2]);
            self->getNodePosition(&self->m_d[3], 0, self->m_nodesD[3]);
        }
    }
}
