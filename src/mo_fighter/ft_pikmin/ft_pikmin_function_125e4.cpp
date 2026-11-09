#pragma force_active on

struct Mod64 {
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
    virtual int f17(int);
    virtual void f18();
    virtual void f19(int);
};

struct Mod54 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int f4(int, int);
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
    virtual void f99(int, int, int);
};

struct Mod8 {
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
    virtual int f21();
};

struct ModC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float f9();
};

struct FTBase {
    unsigned char pad0[0x28];
    int attr28;
    unsigned char pad1[0x10];
};

struct FTActor : FTBase {
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
    virtual void f106(int, int);
    virtual void v107();
    virtual void v108();
    virtual void f109(int);
};

struct Modules {
    unsigned char pad0[8];
    Mod8* mod8;
    ModC* modC;
    unsigned char pad1[0x54 - 0x10];
    Mod54* mod54;
    unsigned char pad2[0x64 - 0x58];
    Mod64* mod64;
};

struct Accesser {
    unsigned char pad[0xd8];
    Modules* modules;
};

struct Fighter {
    unsigned char pad[4];
    void* manager;
};

extern "C" void fn_113_243DC(void*, int);
extern "C" int fn_113_243CC(void*);
extern "C" void* fn_113_244FC(void*);
extern "C" void fn_113_24D34(void*, void*, float);
extern "C" void fn_113_12954(void*, void*);

extern "C" void fn_113_125E4(Fighter* fighter, Accesser* accesser) {
    if (accesser->modules->mod64->f17(0x22000010) != 0) {
        accesser->modules->mod64->f19(0x22000010);
        fn_113_243DC(fighter->manager, 1);
        if (fn_113_243CC(fighter->manager) > 0) {
            int attr = ((FTActor*)fn_113_244FC(fighter->manager))->attr28;
            if (accesser->modules->mod54->f4(7, attr) != 0) {
                accesser->modules->mod54->f99(7, 0, 1);
                int val = 0x1e;
                if (accesser->modules->mod8->f21() == 0x64) {
                    val = 0x1f;
                }
                if (accesser->modules->mod8->f21() == 0x65) {
                    val = 0x20;
                }
                if (accesser->modules->mod8->f21() == 0x66) {
                    val = 0x21;
                }
                ((FTActor*)fn_113_244FC(fighter->manager))->f106(val, 0);
                ((FTActor*)fn_113_244FC(fighter->manager))->f109(0xe);
                void* mgr = fighter->manager;
                fn_113_24D34(mgr, fn_113_244FC(mgr), accesser->modules->modC->f9());
            }
        }
    } else {
        if (accesser->modules->mod64->f17(0x22000011) != 0) {
            fn_113_12954(fighter, accesser);
            accesser->modules->mod64->f19(0x22000011);
        }
    }
}