// 99.9% match; 3 lines differ. Test: f80=0 first (its zero constant reused), unkD=0 last.
#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on

struct Pack {
    void* vt;
    short a, b;
    int c;
    unsigned int d;
};

struct Ent {
    void* a;
    void* b;
};

struct Flags11 {
    unsigned char f80 : 1;
    unsigned char f40 : 1;
    unsigned char f20 : 1;
    unsigned char f10 : 1;
    unsigned char f08 : 1;
    unsigned char f04 : 1;
    unsigned char f02 : 1;
    unsigned char f01 : 1;
};

struct Self {
    unsigned int unk0;
    unsigned int unk4;
    char pad8[2];
    unsigned char unkA;
    signed char unkB;
    unsigned char unkC;
    unsigned char unkD;
    unsigned char unkE;
    unsigned char unkF;
    char pad10;
    Flags11 flags11;
    char pad12[0x1a];
    void* unk2C;
    Ent ent[5];
    int unk58;
    char pad5c[0x28];
    float unk84;
};

struct FtSub {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual int f21();
};

struct FtMgr {
    char pad[0xb4];
    FtSub sub;
};

struct SysView {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual int f8(int);
};

struct UnitView {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual int f9();
};

struct Pad3c {
    char pad[0x3c];
};

struct ObjV : Pad3c {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
    virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128(); virtual void v129();
    virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135(); virtual void v136(); virtual void v137(); virtual void v138(); virtual void v139();
    virtual void v140(); virtual void v141(); virtual void v142(); virtual void v143(); virtual void v144(); virtual void v145(); virtual void v146(); virtual void v147(); virtual void v148(); virtual void v149();
    virtual void v150(); virtual void v151(); virtual void v152(); virtual void v153(); virtual void v154(); virtual void v155(); virtual void v156(); virtual void v157(); virtual void v158(); virtual void v159();
    virtual void v160(); virtual void v161(); virtual void v162(); virtual void v163(); virtual void v164(); virtual void v165(); virtual void v166(); virtual void v167(); virtual void v168(); virtual void v169();
    virtual void v170(); virtual void v171(); virtual void v172(); virtual void v173(void*);
};

extern "C" {
extern char lbl_27_data_261F0[];
extern char lbl_27_data_261B0[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
extern char lbl_27_data_272E8[];
extern FtMgr* g_ftManager;
extern void* g_GameGlobal;
void fn_27_157EE8(void*, int, unsigned char, void*);
void fn_27_12AA4C(void*);
void fn_27_113C0C(void*, void*, void*, int, float);
void fn_27_1241D8(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void OSReport(const char*, ...);
float getGameFrame__10GameGlobalCFv(void*);
}

inline void callObj(void* obj, void* arg) {
    ((ObjV*)obj)->v173(arg);
}

inline int getUnit(soEventManager* m, short id) {
    UnitView* u = (UnitView*)__dynamic_cast(m->getEventUnit(id), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
    if (u == 0)
        return 0;
    return u->f9();
}

extern "C" void fn_27_115B94(Self* self, signed char arg1, unsigned int arg2, unsigned int arg3) {
    Pack pk;
    unsigned int unk4;
    short n;
    int res;

    self->unkB = arg1;
    n = (short)g_ftManager->sub.f21();
    unk4 = self->unk4;
    res = 0;
    pk.vt = lbl_27_data_261F0;
    pk.a = n;
    pk.b = 0;
    pk.c = 0;
    if (n > 0 && n > -1) {
        if (((SysView*)soEventSystem::getInstance())->f8(n) != 0) {
            soEventManager* m1 = soEventSystem::getInstance()->getManager(pk.a);
            if (m1->getObserverCapacity(pk.b) == 0) {
                pk.c = res;
            } else {
                soEventManager* m2;
                short id = pk.b;
                m2 = soEventSystem::getInstance()->getManager(pk.a);
                if (m2->getObserverCapacity(id) == 0) {
                    res = 0;
                } else {
                    res = getUnit(m2, id);
                }
                pk.c = res;
            }
        }
    }
    pk.d = unk4;
    pk.vt = lbl_27_data_261B0;
    fn_27_157EE8(&pk, self->unk58, self->unkA, self->ent[self->unkA].a);
    callObj(self->ent[self->unkA].b, (char*)self + 0x78);
    fn_27_12AA4C(self->ent[self->unkA].b);
    if (arg2 == 1) {
        fn_27_113C0C(self, (char*)self + 0x154, (char*)self + 0x164, -1, self->unk84);
    }
    fn_27_1241D8(self->unk2C, 0);
    self->flags11.f80 = 0;
    self->unkC = 7;
    self->unkF = 3;
    self->flags11.f40 = arg2;
    self->flags11.f10 = 1;
    self->flags11.f08 = arg3;
    self->flags11.f20 = !(self->unkE & 1);
    self->unkD = 0;
    OSReport(lbl_27_data_272E8, (int)getGameFrame__10GameGlobalCFv(g_GameGlobal));
}
