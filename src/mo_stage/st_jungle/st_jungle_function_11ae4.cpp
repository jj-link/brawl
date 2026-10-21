#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_51_3BAC(void*, void*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_51_data_8200[];
extern "C" float lbl_51_rodata_1D0;

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
    virtual void v80(void*);
};

extern "C" {
void* fn_51_11AE4(void* a, void* b, void* c)
{
    void* obj = __nw__FUlQ25Heaps8HeapType(0x1a8, 0x0f);
    Obj* result = (Obj*)obj;
    if (obj != 0) {
        fn_51_3BAC(obj, c);
        *(void**)((char*)obj + 0x3c) = lbl_51_data_8200;
        __ct__14snd3DGeneratorFv((char*)obj + 0x1a0);
        float tmp = lbl_51_rodata_1D0;
        *(float*)((char*)obj + 0x194) = tmp;
        *(float*)((char*)obj + 0x198) = tmp;
        *(float*)((char*)obj + 0x19c) = tmp;
    }
    if (result != 0) {
        result->v42(a);
        result->v78(b);
    }
    return result;
}
}
