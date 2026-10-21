#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_70_2C28(void*, int);
extern "C" char lbl_70_data_1CB0[];

struct Obj {
    char pad[0x3c];
    virtual void v0(int);
    virtual void v1(int);
    virtual void v2(int);
    virtual void v3(int);
    virtual void v4(int);
    virtual void v5(int);
    virtual void v6(int);
    virtual void v7(int);
    virtual void v8(int);
    virtual void v9(int);
    virtual void v10(int);
    virtual void v11(int);
    virtual void v12(int);
    virtual void v13(int);
    virtual void v14(int);
    virtual void v15(int);
    virtual void v16(int);
    virtual void v17(int);
    virtual void v18(int);
    virtual void v19(int);
    virtual void v20(int);
    virtual void v21(int);
    virtual void v22(int);
    virtual void v23(int);
    virtual void v24(int);
    virtual void v25(int);
    virtual void v26(int);
    virtual void v27(int);
    virtual void v28(int);
    virtual void v29(int);
    virtual void v30(int);
    virtual void v31(int);
    virtual void v32(int);
    virtual void v33(int);
    virtual void v34(int);
    virtual void v35(int);
    virtual void v36(int);
    virtual void v37(int);
    virtual void v38(int);
    virtual void v39(int);
    virtual void v40(int);
    virtual void v41(int);
    virtual void v42(int);
    virtual void v43(int);
    virtual void v44(int);
    virtual void v45(int);
    virtual void v46(int);
    virtual void v47(int);
    virtual void v48(int);
    virtual void v49(int);
    virtual void v50(int);
    virtual void v51(int);
    virtual void v52(int);
    virtual void v53(int);
    virtual void v54(int);
    virtual void v55(int);
    virtual void v56(int);
    virtual void v57(int);
    virtual void v58(int);
    virtual void v59(int);
    virtual void v60(int);
    virtual void v61(int);
    virtual void v62(int);
    virtual void v63(int);
    virtual void v64(int);
    virtual void v65(int);
    virtual void v66(int);
    virtual void v67(int);
    virtual void v68(int);
    virtual void v69(int);
    virtual void v70(int);
    virtual void v71(int);
    virtual void v72(int);
    virtual void v73(int);
    virtual void v74(int);
    virtual void v75(int);
    virtual void v76(int);
    virtual void v77(int);
    virtual void v78(int);
};

extern "C" void* fn_70_4FE0(int a, int b, int c)
{
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x1CC, 0xF);
    if (obj != 0) {
        fn_70_2C28(obj, c);
        *(void**)((char*)obj + 0x3c) = lbl_70_data_1CB0;
    }
    if (obj != 0) {
        obj->v42(a);
        obj->v78(b);
    }
    return obj;
}
