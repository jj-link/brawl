#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__8grMadeinFPCc(void*, const char*);
extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
extern "C" unsigned char lbl_82_data_8F0[];

struct Base {
    unsigned char padding[0x3C];
};

struct Madein : Base {
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
    virtual void v26(void*);
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
    virtual void v42(int);
    unsigned char pad2[0x30];
    unsigned int field_70;
};

extern "C" Madein* fn_82_4044(int arg0, int unused, const char* taskName) {
    Madein* obj = (Madein*)__nw__FUlQ25Heaps8HeapType(0x1A4, 15);
    if (obj) {
        __ct__8grMadeinFPCc(obj, taskName);
        *(void**)((unsigned char*)obj + 0x3C) = (void*)lbl_82_data_8F0;
        obj->v26(lbl_82_data_8F0);
    }
    if (obj) {
        obj->v42(arg0);
        obj->field_70 = 15;
        makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(obj, 1, 15);
        setCalcuCallbackRoot__9grGimmickFUl(obj, 7);
    }
    return obj;
}
