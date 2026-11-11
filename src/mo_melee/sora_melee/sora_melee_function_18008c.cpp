#include <types.h>
#pragma force_active on

struct II {
    s32 a;
    s32 b;
};

class Obj64 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(u32);
};

class Obj88 {
public:
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
    virtual void v22(void*, u32, u32, void*);
};

class ModC {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(float*);
};

struct Mod10Base {
    s32 pad0;
    s32 pad1;
};

class Mod10 : public Mod10Base {
public:
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
    virtual s32 v55(u32, u32);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual II v63(u32, u32);
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
    virtual II v86(u32);
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
    virtual void v104(u32, float);
    virtual void v105();
    virtual void v106();
    virtual void v107(II*, u32);
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual float v111();
};

struct Modules {
    char pad[0x0c];
    ModC* mod_c;
    Mod10* mod_10;
    char pad2[0x50];
    Obj64* obj_64;
    char pad3[0x20];
    Obj88* obj_88;
};

struct Self {
    char pad[0xd8];
    Modules* modules;
};

extern "C" const float lbl_27_rodata_2418;

extern "C" void fn_27_18008C(void* arg0, Self* self) {
    void* r = self->modules->obj_64->v4(0x20000001);
    self->modules->obj_88->v22(r, 1, 1, self->modules);
    Mod10* mod10 = self->modules->mod_10;
    s32 check = mod10->v55(8, 0);
    if (check != 0) {
        float f31 = mod10->v111();
        II res = mod10->v63(8, 0);
        float f3[3];
        f3[0] = *(float*)&res.a;
        f3[1] = *(float*)&res.b;
        f3[2] = f31;
        self->modules->mod_c->v5(f3);
        II ii = mod10->v86(0);
        mod10->v107(&ii, 0);
    }
    mod10->v104(0, lbl_27_rodata_2418);
}
