#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_40_24D88(void*, void*);

extern "C" {
extern char lbl_40_data_15428[];
extern const float lbl_40_rodata_818;
extern const float lbl_40_rodata_81C;
}

struct Raw {
    char pad[0x3c];
    void* vtable;
    char d1[0xA4];
    int e4;
    char d2[0xBC];
    int a4;
    float a8;
    float ac;
    char b0;
    char b1;
    char pad2[2];
    float b4;
    char end[0xC];
};

struct Pad {
    char p[0x3c];
};

struct Obj : Pad {
    virtual void v0(void*); virtual void v1(void*); virtual void v2(void*); virtual void v3(void*);
    virtual void v4(void*); virtual void v5(void*); virtual void v6(void*); virtual void v7(void*);
    virtual void v8(void*); virtual void v9(void*); virtual void v10(void*); virtual void v11(void*);
    virtual void v12(void*); virtual void v13(void*); virtual void v14(void*); virtual void v15(void*);
    virtual void v16(void*); virtual void v17(void*); virtual void v18(void*); virtual void v19(void*);
    virtual void v20(void*); virtual void v21(void*); virtual void v22(void*); virtual void v23(void*);
    virtual void v24(void*); virtual void v25(void*); virtual void v26(void*); virtual void v27(void*);
    virtual void v28(void*); virtual void v29(void*); virtual void v30(void*); virtual void v31(void*);
    virtual void v32(void*); virtual void v33(void*); virtual void v34(void*); virtual void v35(void*);
    virtual void v36(void*); virtual void v37(void*); virtual void v38(void*); virtual void v39(void*);
    virtual void v40(void*); virtual void v41(void*); virtual void v42(void*); virtual void v43(void*);
    virtual void v44(void*); virtual void v45(void*); virtual void v46(void*); virtual void v47(void*);
    virtual void v48(void*); virtual void v49(void*); virtual void v50(void*); virtual void v51(void*);
    virtual void v52(void*); virtual void v53(void*); virtual void v54(void*); virtual void v55(void*);
    virtual void v56(void*); virtual void v57(void*); virtual void v58(void*); virtual void v59(void*);
    virtual void v60(void*); virtual void v61(void*); virtual void v62(void*); virtual void v63(void*);
    virtual void v64(void*); virtual void v65(void*); virtual void v66(void*); virtual void v67(void*);
    virtual void v68(void*); virtual void v69(void*); virtual void v70(void*); virtual void v71(void*);
    virtual void v72(void*); virtual void v73(void*); virtual void v74(void*); virtual void v75(void*);
    virtual void v76(void*); virtual void v77(void*); virtual void v78(void*); virtual void v79(void*);
    virtual void v80(void*); virtual void v81(void*); virtual void v82(void*); virtual void v83(void*);
    virtual void v84(void*); virtual void v85(void*); virtual void v86(void*); virtual void v87(void*);
    virtual void v88(void*); virtual void v89(void*); virtual void v90(void*); virtual void v91(void*);
    virtual void v92(void*); virtual void v93(void*); virtual void v94(void*); virtual void v95(void*);
    virtual void v96(void*); virtual void v97(void*); virtual void v98(void*); virtual void v99(void*);
    virtual void v100(void*); virtual void v101(void*); virtual void v102(void*); virtual void v103(void*);
    virtual void v104(void*); virtual void v105(void*); virtual void v106(void*); virtual void v107(void*);
    virtual void v108(void*); virtual void v109(void*); virtual void v110(void*); virtual void v111(void*);
    virtual void v112(void*);
};

extern "C" void* fn_40_3B538(void* arg0, void* arg1, void* arg2) {
    Raw* raw = (Raw*)__nw__FUlQ25Heaps8HeapType(0x1C4, 0xF);
    Obj* obj = (Obj*)raw;
    if (obj) {
        fn_40_24D88(obj, arg2);
        raw->vtable = &lbl_40_data_15428;
        raw->a4 = 0;
        raw->a8 = lbl_40_rodata_818;
        raw->ac = lbl_40_rodata_818;
        raw->b0 = 0;
        raw->b1 = 0;
        raw->b4 = lbl_40_rodata_81C;
        raw->e4 = 0;
    }
    if (obj) {
        obj->v112(arg1);
        obj->v42(arg0);
    }
    return obj;
}