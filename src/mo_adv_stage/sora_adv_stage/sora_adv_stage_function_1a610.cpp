#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct Obj {
    char pad[0x3c];
    virtual void v0(void*);
    virtual void v1(void*);
    virtual void v2(void*);
    virtual void v3(void*);
    virtual void v4(void*);
    virtual void v5(void*);
    virtual void v6(void*);
    virtual void v7(void*);
    virtual void v8(void*);
    virtual void v9(void*);
    virtual void v10(void*);
    virtual void v11(void*);
    virtual void v12(void*);
    virtual void v13(void*);
    virtual void v14(void*);
    virtual void v15(void*);
    virtual void v16(void*);
    virtual void v17(void*);
    virtual void v18(void*);
    virtual void v19(void*);
    virtual void v20(void*);
    virtual void v21(void*);
    virtual void v22(void*);
    virtual void v23(void*);
    virtual void v24(void*);
    virtual void v25(void*);
    virtual void v26(void*);
    virtual void v27(void*);
    virtual void v28(void*);
    virtual void v29(void*);
    virtual void v30(void*);
    virtual void v31(void*);
    virtual void v32(void*);
    virtual void v33(void*);
    virtual void v34(void*);
    virtual void v35(void*);
    virtual void v36(void*);
    virtual void v37(void*);
    virtual void v38(void*);
    virtual void v39(void*);
    virtual void v40(void*);
    virtual void v41(void*);
    virtual void v42(int);
    virtual void v43(void*);
    virtual void v44(void*);
    char d[0x124];
    char flag;
    char d2[0x87];
};

extern "C" Obj* fn_40_1A69C(Obj*, const char*);

extern "C" void* fn_40_1A610(int a, int b, const char* c)
{
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x1ec, 0xf);
    if (obj != 0) {
        obj = fn_40_1A69C(obj, c);
    }
    obj->v42(a);
    obj->flag = (char)b;
    return obj;
}
