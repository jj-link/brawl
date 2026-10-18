#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_46_44B4(void*, const char*);
extern "C" void* memset(void*, int, unsigned long);
extern "C" char lbl_46_data_15D4[];
extern "C" const float lbl_46_rodata_E0;

struct Base {
    char pad0[0x3c];
};

struct Obj : Base {
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44(int);
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
    virtual void v80(const char*);

    char pad40[0x124];
    unsigned char a;
    char pad165[3];
    float b;
    int c, d, e, f;
    unsigned char g;
    char pad17d[3];
    char h[0x90];
    char i[0x3c];
};

extern "C" Obj* fn_46_4894(int x, const char* y, const char* z) {
    Obj* p = (Obj*)__nw__FUlQ25Heaps8HeapType(0x24c, 15);
    if (p) {
        fn_46_44B4(p, z);
        *(void**)((char*)p + 0x3c) = lbl_46_data_15D4;
        p->a = 16;
        p->b = lbl_46_rodata_E0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->f = 0;
        p->g = 1;
        memset(p->h, 0, 0x90);
        memset(p->i, 0, 0x3c);
    }
    if (p) {
        p->v44(x);
        p->v80(y);
    }
    return p;
}
