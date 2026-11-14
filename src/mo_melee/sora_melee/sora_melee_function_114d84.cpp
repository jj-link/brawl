#include <types.h>
#include <ft/ft_manager.h>
#include <ec/ec_mgr.h>
#include <so/event/so_event_system.h>
#pragma force_active on

struct Obj3cBase { char pad[0x3c]; };
class Obj3c : public Obj3cBase {
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
    virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
    virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
    virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
    virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124();
    virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128(); virtual void v129();
    virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134();
    virtual void v135(); virtual void v136(); virtual void v137(); virtual void v138(); virtual void v139();
    virtual void v140(); virtual void v141(); virtual void v142(); virtual void v143(); virtual void v144();
    virtual void v145(); virtual void v146(); virtual void v147(); virtual void v148(); virtual void v149();
    virtual void v150(); virtual void v151(); virtual void v152(); virtual void v153(); virtual void v154();
    virtual void v155(); virtual void v156(); virtual void v157(); virtual void v158(); virtual void v159();
    virtual void v160(); virtual void v161(); virtual void v162(); virtual void v163(); virtual void v164();
    virtual void v165(); virtual void v166(); virtual void v167(); virtual void v168(); virtual void v169();
    virtual void v170(); virtual void v171(); virtual void v172(); virtual void v173(); virtual void v174();
    virtual void v175(); virtual void v176(); virtual void v177(); virtual void v178(); virtual void v179();
    virtual void v180(); virtual void v181(); virtual void v182(); virtual void v183(); virtual void v184();
    virtual void v185(); virtual void v186(); virtual void v187(); virtual void v188(); virtual void v189();
    virtual void v190(); virtual void v191(); virtual void v192(); virtual void v193(); virtual void v194();
    virtual void v195(); virtual void v196(); virtual void v197(); virtual void v198(); virtual void v199();
    virtual void v200(); virtual void v201(); virtual void v202(); virtual void v203(); virtual void v204();
    virtual void v205(); virtual void v206(); virtual void v207(); virtual void v208(); virtual void v209();
    virtual void v210(); virtual void v211(); virtual void v212(); virtual void v213(); virtual void v214();
    virtual void v215(); virtual void v216(); virtual void v217(); virtual void v218(); virtual void v219();
    virtual void v220(); virtual void v221(); virtual void v222(); virtual void v223(); virtual void v224();
    virtual void v225(); virtual void v226(); virtual void v227();
    virtual void v228(void* p, s32 a, s32 b, f32 f);
};

struct VtCBase { char pad[0xc]; };
class VtC : public VtCBase {
public:
    virtual void s0(); virtual void s1(); virtual void s2();
    virtual f32 s3();
};
class VtCPair : public VtCBase {
public:
    virtual void s0(); virtual void s1(); virtual void s2();
    virtual f32 s3();
};

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual int slot7(); virtual void slot8();
};
struct FtSub {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18();
    virtual int f21();
};
struct Pack {
    void* vt;
    short a, b;
    int c;
    unsigned long d;
};
struct Pair { void* a; void* b; };
struct FlagBits { unsigned char pre : 3; unsigned char f10 : 1; unsigned char post : 4; };
struct EffObj { char pad[8]; unsigned int unk8 : 3; unsigned int rest : 29; };
struct Self {
    unsigned int unk0;
    unsigned int unk4;
    char pad8;
    unsigned char unk9;
    unsigned char unkA;
    char padB[3];
    unsigned char unkE;
    char padF[2];
    FlagBits unk11;
    char pad12[0x16];
    void* unk28;
    void* unk2C;
    Pair pairs[2];
    char pad40[0xC];
    void* unk4C;
    char pad50[8];
    void* unk58;
    char pad5C[0x1C];
    char sub78[0xFC];
    int unk174;
    char pad178[0x18];
    EffObj* unk190;
    int unk194;
};

extern "C" {
extern char lbl_27_data_261F0[], lbl_27_data_261B0[], lbl_27_data_26440[], __RTTI__11soEventUnit[];
void fn_27_111B7C(Vec3f*, void*);
float fn_27_111B44(void*);
int fn_27_1125B0(void*);
int fn_27_112E20(void*);
void fn_27_1244CC(void*);
void fn_27_12B9F0(void*, Vec3f*, int, float, float);
void fn_27_13FE4C(void*);
void fn_27_13F49C(void*);
void fn_27_158104(void*, void*, unsigned char, void*);
void fn_8009EFCC(void*);
void fn_8009EF38(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

inline bool hasFlag10(Self* s) {
    return s->unk11.f10;
}

inline int getUnit(soEventManager* m, short id) {
    Object_vptr_0* u = (Object_vptr_0*)__dynamic_cast(
        m->getEventUnit(id), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
    if (u == 0)
        return 0;
    return u->slot7();
}

inline void flagBlock(Self* self) {
    short unitId;
    unsigned long id;
    short n = (short)((FtSub*)((char*)g_ftManager + 0xb4))->f21();
    id = self->unk4;
    Pack pk;
    pk.vt = lbl_27_data_261F0;
    pk.a = n;
    pk.b = 0;
    pk.c = 0;
    if (n > 0 && n > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(n)) {
            if (soEventSystem::getInstance()->getManager(pk.a)->getObserverCapacity(pk.b) == 0) {
                pk.c = 0;
            } else {
                unitId = pk.b;
                soEventManager* m = soEventSystem::getInstance()->getManager(pk.a);
                int res;
                if (m->getObserverCapacity(unitId) == 0)
                    res = 0;
                else
                    res = getUnit(m, unitId);
                pk.c = res;
            }
        }
    }
    pk.d = id;
    pk.vt = lbl_27_data_261B0;
    fn_27_158104(&pk, self->unk58, self->unkA, self->pairs[self->unkA].a);
    fn_27_1244CC(self->unk2C);
}

inline void flagBlock2(Self* self) {
    short n = (short)((FtSub*)((char*)g_ftManager + 0xb4))->f21();
    unsigned long id = self->unk4;
    soEventManager* m;
    int res = 0;
    Pack pk;
    pk.vt = lbl_27_data_261F0;
    pk.a = n;
    pk.b = 0;
    pk.c = 0;
    if (n > 0 && n > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(n)) {
            if (soEventSystem::getInstance()->getManager(pk.a)->getObserverCapacity(pk.b) == 0) {
                pk.c = res;
            } else {
                short unitId = pk.b;
                m = soEventSystem::getInstance()->getManager(pk.a);
                if (m->getObserverCapacity(unitId) == 0)
                    res = 0;
                else
                    res = getUnit(m, unitId);
                pk.c = res;
            }
        }
    }
    pk.d = id;
    pk.vt = lbl_27_data_261B0;
    fn_27_158104(&pk, self->unk58, self->unkA, self->pairs[self->unkA].a);
    fn_27_1244CC(self->unk2C);
}

inline void cleanup(Self* self) {
    EffObj* p = self->unk190;
    if (p != 0) {
        p->unk8 = 1;
        fn_8009EFCC(self->unk190);
        fn_8009EF38(self->unk190);
    }
    int t = self->unk174;
    self->unk194 = -1;
    if (t != 0) {
        g_ecMgr->endEffect(t);
        self->unk174 = 0;
    }
    fn_27_13FE4C(self->sub78);
    fn_27_13F49C(self->sub78);
    self->unk11.f10 = 0;
}

extern "C" void fn_27_114D84(Self* self) {
    Vec3f sp28;
    fn_27_111B7C(&sp28, self->unk28);
    float f31 = fn_27_111B44(self->unk28);
    int r31 = 0;
    if (((unsigned char*)g_ftManager)[0x68] == 1 && fn_27_1125B0(self->unk28) == 1) {
        r31 = 1;
    }
    if (self->unkE & 1) {
        if (r31 == 0) {
            ((Obj3c*)self->unk4C)->v228(&sp28, 0, 0, f31);
            return;
        }
        if ((unsigned int)hasFlag10(self) == 1 && self->unk9 != 0xFF) {
            flagBlock(self);
        }
        void* r26 = self->pairs[self->unkA].b;
        float f2 = ((VtCPair*)self->unk28)->s3();
        fn_27_12B9F0(r26, &sp28, r31, f31, f2);
        if ((unsigned int)hasFlag10(self) == 1) {
            cleanup(self);
        }
        return;
    }
    if ((unsigned int)hasFlag10(self) == 1 && self->unk9 != 0xFF) {
        flagBlock2(self);
    }
    if (self->unkE & 2) {
        void* r26 = self->pairs[0].b;
        float f2 = ((VtC*)self->unk28)->s3();
        fn_27_12B9F0(r26, &sp28, r31, f31, f2);
        if (fn_27_112E20(self->unk28) == 0) {
            void* r26b = self->pairs[1].b;
            float f2b = ((VtC*)self->unk28)->s3();
            fn_27_12B9F0(r26b, &sp28, r31, f31, f2b);
        }
    } else {
        void* r26 = self->pairs[self->unkA].b;
        float f2 = ((VtCPair*)self->unk28)->s3();
        fn_27_12B9F0(r26, &sp28, r31, f31, f2);
    }
    if ((unsigned int)hasFlag10(self) == 1) {
        cleanup(self);
    }
}
