#include <types.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

struct Obj;
class Module {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(s32, f32);
    virtual s32 v3();
    virtual void v4();
    virtual void v5(s32, s32);
    virtual void v6();
    virtual void v7();
    virtual void v8(u32, u32, f32*, f32*, f32*, f32*, u32, u32, f32);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(s32, f32);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(s32);
    virtual void v19(s32);
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26(f32);
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34(s32, Obj*);
};
class Sound {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(s32, s32, s32, s32);
};
class Switcher {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(s32);
};
struct Mods {
    char pad0[0xC];
    Module* m0C;
    char pad1[4];
    Module* m14;
    char pad2[0x38];
    Sound* m50;
    char pad3[0x10];
    Module* m64;
    char pad4[8];
    Module* m70;
    char pad5[0x10];
    Switcher* m84;
    Module* m88;
};
struct Obj {
    char pad[0xD8];
    Mods* mods;
};
class Self;
class SelfBase {
public:
    char pad0[0x3c];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual Self* v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void* v185();
    virtual s32 v186();
};
class Self : public SelfBase {
public:
    char pad1[0x20];
    Obj* m60;
};
extern "C" const float lbl_27_rodata_7C14;
extern "C" const float lbl_27_rodata_7C0C;
extern "C" float fn_27_111DB0(void*);
extern "C" void fn_27_387654(void*, void*, s32, s32, void*);

extern "C" void fn_27_38077C(Self* self, s32 a1, s32 a2, s32 mode, u32 flag, f32 farg) {
    Obj* obj = self->m60;
    void* first = self->v185();
    obj->mods->m0C->v2(a1, lbl_27_rodata_7C14);
    Module* m = obj->mods->m0C;
    m->v26(fn_27_111DB0(first));
    obj->mods->m84->v2(1);
    obj->mods->m64->v13(0x11000015, farg);
    obj->mods->m64->v13(0x11000018, lbl_27_rodata_7C14);
    obj->mods->m64->v13(0x11000016, lbl_27_rodata_7C14);
    obj->mods->m64->v13(0x11000017, lbl_27_rodata_7C14);
    obj->mods->m64->v5(mode, 0x10000040);
    obj->mods->m64->v19(0x1200003E);
    obj->mods->m64->v18(0x12000001);
    obj->mods->m64->v5(0, 0x10000042);
    obj->mods->m64->v5(0, 0x10000044);
    obj->mods->m64->v18(0x1200003D);
    fn_27_387654((char*)self + 0x7FAC, self, a1, a2, obj);

    switch (mode) {
    case 0:
    case 3:
        obj->mods->m70->v34(0x117, obj);
        break;
    case 1:
    case 2:
        if (flag == 1) {
            if (obj->mods->m14->v3() == 5) {
                obj->mods->m70->v34(0x11D, obj);
                break;
            }
            if (obj->mods->m14->v3() == 0)
                obj->mods->m70->v34(0x119, obj);
            else
                obj->mods->m70->v34(0x11A, obj);
            f32 vals[12];
            vals[0] = lbl_27_rodata_7C14;
            vals[1] = lbl_27_rodata_7C14;
            vals[2] = lbl_27_rodata_7C14;
            vals[3] = lbl_27_rodata_7C14;
            vals[4] = lbl_27_rodata_7C14;
            vals[5] = lbl_27_rodata_7C14;
            vals[6] = lbl_27_rodata_7C14;
            vals[7] = lbl_27_rodata_7C14;
            vals[8] = lbl_27_rodata_7C14;
            vals[9] = lbl_27_rodata_7C14;
            vals[10] = lbl_27_rodata_7C14;
            vals[11] = lbl_27_rodata_7C14;
            obj->mods->m88->v8(0x01030039, 0x12E, &vals[9], &vals[6], &vals[3], &vals[0], 0, 0, lbl_27_rodata_7C0C);
        } else if (mode == 2) {
            if (obj->mods->m14->v3() == 0)
                obj->mods->m70->v34(0x119, obj);
            else
                obj->mods->m70->v34(0x11A, obj);
        } else {
            obj->mods->m70->v34(0x117, obj);
        }
        break;
    case 4:
        {
            Module* mod = obj->mods->m64;
            mod->v5(soExternalValueAccesser::getWorkInt((StageObject*)self->v152(), 0x20000000), 0x10000047);
            switch (self->v152()->v186()) {
            case 29:
                obj->mods->m64->v5(0, 0x10000048);
                obj->mods->m50->v5(0x869, 0, 0, 0);
                break;
            case 30:
                obj->mods->m64->v5(1, 0x10000048);
                obj->mods->m50->v5(0x86D, 0, 0, 0);
                break;
            case 31:
                obj->mods->m64->v5(2, 0x10000048);
                obj->mods->m50->v5(0x871, 0, 0, 0);
                break;
            }
            obj->mods->m70->v34(0x128, obj);
        }
        break;
    case 5:
        obj->mods->m70->v34(0x129, obj);
        break;
    }
}
