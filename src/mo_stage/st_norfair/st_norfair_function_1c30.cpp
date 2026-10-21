#pragma force_active on

struct Pad {
    char p[0x3c];
};

class Ground : public Pad {
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
    virtual void v37(void*, int, int);
    virtual void v38();
    virtual void v39(void*);
    virtual void v40();
    virtual void v41(void*);
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
    virtual void v112(void*);
};

struct Stage {
    char pad0[0x9c];
    void* at9c;
    char padA0[0x100];
    void* at1a0;
    char pad1A4[0x798 - 0x1a4];
    char at798[1];
};

extern "C" {
extern char lbl_54_data_1B0[];
extern char lbl_54_data_1BC[];
Ground* fn_54_E57C(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_54_1C30(Stage* arg0, int arg1) {
    Ground* g;
    switch (arg1) {
    case 9:
        g = fn_54_E57C(8, lbl_54_data_1B0, lbl_54_data_1BC);
        break;
    default:
        g = 0;
        break;
    }
    if (g) {
        addGround__5StageFP6Ground(arg0, g);
        g->v37(arg0->at1a0, 0, 0);
        g->v39(arg0->at9c);
        g->v112(&arg0->at798);
    }
}
}
