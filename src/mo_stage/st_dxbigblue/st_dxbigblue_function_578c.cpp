#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_81_4E8C(void*, const char*);
extern "C" void* memset(void*, int, unsigned long);

extern char lbl_81_data_1348;
extern char lbl_81_data_1108;
extern const float lbl_81_rodata_C0;

struct Pad {
    char p[0x3c];
};

struct Obj : Pad {
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
    virtual void v40(); virtual void v41(); virtual void v42(int); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(const char*);

    char p1[0x168 - 0x40];
    unsigned char f168;
    char p2[0x16c - 0x169];
    float f16c;
    float f170;
    float f174;
    unsigned char f178;
    char p3[0x17c - 0x179];
    int f17c;
    char p4[4];
    char member180[0x10];
};

extern "C" void* fn_81_578C(int a, const char* b, const char* c)
{
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x190, 0xf);
    if (obj != 0) {
        fn_81_4E8C(obj, c);
        *(char**)((char*)obj + 0x3c) = &lbl_81_data_1348;
        unsigned char z = 0;
        float f = lbl_81_rodata_C0;
        *(unsigned char*)((char*)obj + 0x168) = z;
        *(float*)((char*)obj + 0x16c) = f;
        *(float*)((char*)obj + 0x170) = f;
        *(float*)((char*)obj + 0x174) = f;
        *(unsigned char*)((char*)obj + 0x178) = z;
        *(char**)((char*)obj + 0x3c) = &lbl_81_data_1108;
        *(int*)((char*)obj + 0x17c) = 0;
        memset((char*)obj + 0x180, 0, 0x10);
    }
    if (obj != 0) {
        obj->v42(a);
        obj->v78(b);
    }
    return obj;
}
