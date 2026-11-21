#include <mt/mt_vector.h>
#include <mt/mt_matrix.h>
#include <ai/ai_mgr.h>

#pragma force_active on

struct Ground_base { char pad[0x3c]; };

class Ground : public Ground_base {
public:
    virtual void v0();  virtual void v1();  virtual void v2();  virtual void v3();  virtual void v4();
    virtual void v5();  virtual void v6();  virtual void v7();  virtual void v8();  virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
    virtual void v95(); virtual void v96(); virtual void v97();
    virtual void disableAttack(unsigned long);                       // 0x190
    virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108();
    virtual void v109(); virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113();
    virtual void v114(); virtual void v115(); virtual void v116();
    virtual void fn_57_9464();                                       // 0x1dc
    virtual void fn_57_9840();                                       // 0x1e0
    virtual void fn_57_9A44();                                       // 0x1e4

    char pad1[0x14c - 0x40];
    int f14c;
    char pad2[0x160 - 0x150];
    Matrix* m160;
    Vec3f* v164;
    unsigned char f168;
    char pad3[3];
    float f16c;
    float f170;
    unsigned char f174;
    unsigned char f175;
    char pad4[0x17c - 0x176];
    int f17c;
};

struct Consts {
    float c0, c4, c8, cC, c10, c14, c18;
};

extern "C" const Consts lbl_57_rodata_260;
extern "C" void fn_27_1F299C(aiMgr*, int);
extern "C" float rsqrtf__Ff(float);
extern "C" void mulPos__6MatrixFPC5Vec3fP5Vec3f(Matrix*, const Vec3f*, Vec3f*);
extern "C" int setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(aiMgr*, Vec2f*, Vec2f*, int, bool, bool);
extern aiMgr* g_aiMgr;

extern "C" void fn_57_8AD4(Ground* self) {
    const Consts& k = lbl_57_rodata_260;
    if (self->f174 == 1) {
        switch (self->f168) {
        case 1:
        float d = self->f170 - self->f16c;
        if (d > k.c4) {
            self->disableAttack(0);
            self->f175 = 0;
            if (self->f17c != -1) {
                fn_27_1F299C(g_aiMgr, self->f17c);
                self->f17c = -1;
            }
        } else if (d > k.c8) {
            self->disableAttack(0);
            self->f175 = 0;
            self->fn_57_9A44();
            return;
        } else if (d > k.cC) {
            self->fn_57_9840();
            Matrix* m = self->m160;
            float* mf = (float*)m;
            struct Locals { Vec3f diff; float padding; Vec2f a, b; Vec3f t; } loc;
            float z = mf[11];
            float y = mf[7];
            float x = mf[3];
            loc.t.m_z = z;
            loc.t.m_x = x;
            loc.t.m_y = y;
            Vec3fSub(&loc.diff, self->v164, &loc.t);
            loc.t = loc.diff;
            float sq = loc.t.m_z * loc.t.m_z + (loc.t.m_x * loc.t.m_x + loc.t.m_y * loc.t.m_y);
            float s;
            if ((float)fabs(sq) <= k.c10) {
                s = k.c0;
            } else {
                s = sq * rsqrtf__Ff(sq);
            }
            loc.t.m_x = k.c0 * s;
            loc.t.m_y = k.c0 * s;
            loc.t.m_z = k.c14 * s;
            self->m160->mulPos(&loc.t, &loc.t);
            float left, top, bottom, right;
            top = k.c18 + loc.t.m_y;
            left = loc.t.m_x - k.c18;
            bottom = loc.t.m_y - k.c18;
            right = k.c18 + loc.t.m_x;
            loc.a.m_x = left;
            loc.a.m_y = top;
            loc.b.m_x = right;
            loc.b.m_y = bottom;
            self->f17c = g_aiMgr->setDangerZone(&loc.a, &loc.b, self->f17c, false, false);
        }
        break;
        }
    } else {
        self->fn_57_9464();
        if (self->f14c != 0) {
            self->f174 = 1;
        }
    }
}
