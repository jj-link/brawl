#include <types.h>
#pragma force_active on
struct Ground_base { char pad[0x3c]; };
struct V { float x, y, z; };
struct Line { char pad[0x10]; unsigned char f; };
struct V2 { float x, y; };
struct Joint {
    char pad[0x38]; V2* pts;
    char pad3c[0xc];
    unsigned long a48 : 8;
    unsigned long b48 : 8;
    unsigned long c48 : 16;
    unsigned short cnt;
    char pad4e[7];
    unsigned char f55;
};
struct Coll { Joint* getJoint(unsigned short); };
extern "C" Joint* getJoint__11grCollisionFUs(Coll*, unsigned short);
extern "C" Line* getLine__16grCollisionJointFUs(Joint*, unsigned short);
class Ground : public Ground_base {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47();
    virtual void getNodePosition(V*, unsigned long, unsigned long);
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
    virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70();
    virtual void updateG3dProcCalcWorld();
    char pad40[0xc];
    Coll* collision;
    char pad50[0x1c];
    unsigned char flags;
    char pad6d[0xe3];
    unsigned char kind;
    char pad151[0x4b];
    unsigned long ids[1];
};
extern "C" void fn_66_48A0(Ground* self) {
    self->updateG3dProcCalcWorld();
    self->flags &= ~2;
    if (!self->collision) return;
    unsigned short n;
    Joint* j = getJoint__11grCollisionFUs(self->collision, 0);
    if (!j) return;
    V2* pts = j->pts;
    if (!pts) return;
    V2* p;
    unsigned short i;
    j->b48 = 3;
    j->f55 |= 8;
    for (i = 0, n = j->cnt; i != n; ++i) {
        V v;
        p = &pts[i];
        self->getNodePosition(&v, 0, self->ids[i]);
        p->x = v.x;
        p->y = v.y;
    }
    Line* l = getLine__16grCollisionJointFUs(j, 7);
    if (l) {
        switch ((int)self->kind) {
        case 6: l->f |= 0x20; break;
        default: l->f &= ~0x20; break;
        }
    }
}
