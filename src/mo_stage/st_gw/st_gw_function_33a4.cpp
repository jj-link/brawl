#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_63_2B6C(void*, void*);
extern "C" char lbl_63_data_BA8[];
extern "C" const float lbl_63_rodata_48;

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
    virtual void v40(); virtual void v41();
    virtual void f1(void*);
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62();
    virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
    virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70();
    virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77();
    virtual void f2(void*);

    char pad40[0x174 - 0x40];
    unsigned char field174;
    float field178;
    int field17C;
    int field180;
    int field184;
    int field188;
    unsigned char field18C;
    unsigned char field18D;
    int field190;
};

extern "C" void* fn_63_33A4(void* a, void* b, void* c) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x194, 0xF);
    if (obj) {
        fn_63_2B6C(obj, c);
        *(void**)((char*)obj + 0x3C) = lbl_63_data_BA8;
        obj->field174 = 0;
        obj->field178 = lbl_63_rodata_48;
        obj->field17C = 0;
        obj->field180 = 0;
        obj->field184 = 0;
        obj->field188 = 0;
        obj->field18C = 1;
        obj->field18D = 0;
        obj->field190 = 0;
    }
    if (obj) {
        obj->f1(a);
        obj->f2(b);
    }
    return obj;
}
