#pragma force_active on
struct Pad { char p[0x3c]; };
struct Ground : Pad {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36();
    virtual void f38(void*, int, int);
    virtual void v39();
    virtual void f40(void*);
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
    virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70();
    virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80();
    virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85();
    virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90();
    virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
    virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100();
    virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105();
    virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110();
    virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
    virtual void f116(void*);
    virtual void f117(int);
    virtual void v118(); virtual void v119(); virtual void v120();
    virtual void f121(void*);
    virtual void f122(int);
};
struct Stage {
    char pad0[0x9c];
    void* f9c;
    char pad_a0[0x100];
    void* f1a0;
};

extern "C" {
extern char lbl_63_data_0[];

Ground* fn_63_10BB4(int, const char*, const char*);
Ground* fn_63_1244C(int, const char*, const char*);
Ground* fn_63_13148(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_63_1D88(Stage* stage, int kind) {
    Ground* ground;
    int id;
    char* ptr;
    char* data = lbl_63_data_0;

    switch (kind) {
    case 29:
        ground = fn_63_10BB4(0x34, data + 0x4f0, data + 0x4fc);
        ptr = (char*)stage + 0x394;
        id = 0;
        break;
    case 30:
        ground = fn_63_1244C(0x35, data + 0x508, data + 0x518);
        ptr = (char*)stage + 0x394;
        id = 1;
        break;
    case 31:
        ground = fn_63_10BB4(0x36, data + 0x528, data + 0x534);
        ptr = (char*)stage + 0x3f8;
        id = 2;
        break;
    case 32:
        ground = fn_63_13148(0x37, data + 0x544, data + 0x554);
        ptr = (char*)stage + 0x3f8;
        id = 3;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->f38(stage->f1a0, 0, 0);
        ground->f40(stage->f9c);
        ground->f116((char*)stage + 0x1e0);
        ground->f117(3);
        ground->f121(ptr);
        ground->f122(id);
    }
}
}
