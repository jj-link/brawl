#pragma force_active on
struct GroundBase {
    char pad[0x3c];
};

struct Ground : GroundBase {
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
    virtual void startup(void*, int, int);
    virtual void v38();
    virtual void setNode(void*);
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
    virtual void v113(void*);
    virtual void v114();
    virtual void v115(void*);
    virtual void v116(void*);
    virtual void v117(void*);
    virtual void v118(void*);
    virtual void v119(void*);
    virtual void v120(void*);
    virtual void v121(int);
    virtual void v122(void*);
};

struct Stage {
    char pad0[0x9c];
    void* data9C;
    char pad1[0x100];
    void* data1A0;
};

extern "C" {
extern char lbl_88_data_0[];

Ground* fn_88_5568(int, const char*, const char*);
Ground* fn_88_5E30(int, const char*, const char*);
Ground* fn_88_4DD0(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_88_B5C(Stage* stage, int kind) {
    Ground* ground;
    int id;
    const char* data = lbl_88_data_0;

    switch (kind) {
    case 1:
        ground = fn_88_5568(10, data + 0x30, data + 0x3C);
        id = 11;
        break;
    case 2:
        ground = fn_88_5E30(11, data + 0x50, data + 0x5C);
        id = 2;
        break;
    case 3:
        ground = fn_88_5E30(11, data + 0x50, data + 0x70);
        id = 3;
        break;
    case 4:
        ground = fn_88_5E30(11, data + 0x50, data + 0x84);
        id = 4;
        break;
    case 5:
        ground = fn_88_5E30(11, data + 0x50, data + 0x98);
        id = 5;
        break;
    case 6:
        ground = fn_88_4DD0(12, data + 0xAC, data + 0xBC);
        id = 6;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->startup(stage->data1A0, 0, 0);
        ground->setNode(stage->data9C);
        ground->v113((char*)stage + 0x2A8);
        ground->v115((char*)stage + 0x3C8);
        ground->v116((char*)stage + 0x3F8);
        ground->v117((char*)stage + 0x560);
        ground->v118((char*)stage + 0x594);
        ground->v119((char*)stage + 0x584);
        ground->v120((char*)stage + 0x590);
        ground->v121(id);
        ground->v122((char*)stage + 0x1E4);
    }
}
}
