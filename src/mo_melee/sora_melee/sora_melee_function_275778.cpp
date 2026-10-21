#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __ct__8grMadeinFPCc(void*, const char*);
extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);

struct Obj {
    char pad[0x3c];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(int);
    char pad2[0x30];
    int field70;
};

extern "C" void* create__8grMadeinFiPCcPCcQ25Heaps8HeapType(int a, const char* b, const char* c, int d) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x1a4, d);
    if (obj != 0) {
        obj = (Obj*)__ct__8grMadeinFPCc(obj, c);
    }
    if (obj != 0) {
        obj->v42(a);
        obj->field70 = d;
        makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(obj, 1, d);
        setCalcuCallbackRoot__9grGimmickFUl(obj, 7);
        obj->v26();
    }
    return obj;
}
