#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __ct__10grYakumonoFPCc(void*, const char*);
void fn_27_262210(void*, void*);
extern unsigned char lbl_40_data_16068[];
extern const float lbl_40_rodata_848[];
}

struct Base {
    unsigned char pad0[0x3C];
};

struct Object : Base {
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42(int);
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
    virtual void v78(const char*);

    unsigned char pad1[0x110];
    unsigned int f150;
    unsigned char pad3[0x28];
    unsigned int f17C;
    unsigned int f180;
    unsigned int f184;
    unsigned int f188;
    unsigned int f18C;
    unsigned char pad4[0x10];
    unsigned int f1A0;
    unsigned int f1A4;
    unsigned int f1A8;
    float f1AC;
    float f1B0;
    unsigned char f1B4;
};

extern "C" Object* fn_40_3C590(int arg0, const char* name) {
    Object* p = (Object*)__nw__FUlQ25Heaps8HeapType(0x1B8, 15);
    if (p) {
        __ct__10grYakumonoFPCc(p, name);
        *(void**)((char*)p + 0x3C) = (void*)lbl_40_data_16068;
        p->f150 = 0;
        p->f17C = 0;
        p->f180 = 0;
        p->f184 = 0;
        p->f188 = 0;
        p->f18C = 0;
        fn_27_262210((void*)((char*)p + 0x190), (void*)lbl_40_data_16068);
        p->f1A0 = 0;
        p->f1A4 = 0;
        p->f1A8 = 0;
        p->f1AC = lbl_40_rodata_848[0];
        p->f1B0 = lbl_40_rodata_848[0];
        p->f1B4 = 0;
    }
    if (p) {
        p->v42(arg0);
    }
    return p;
}
