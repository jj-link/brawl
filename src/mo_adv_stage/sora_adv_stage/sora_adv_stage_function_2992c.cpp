#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__9grGimmickFPCc(void*, const char*);
extern "C" unsigned char lbl_40_data_891C[];

struct Base {
    unsigned char padding[0x3C];
};

struct Obj : Base {
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
    virtual void setIndex(int);
};

extern "C" Obj* fn_40_2992C(int arg0, const char* arg1) {
    Obj* p = (Obj*)__nw__FUlQ25Heaps8HeapType(0x16c, 15);
    if (p) {
        __ct__9grGimmickFPCc(p, arg1);
        *(unsigned char*)((char*)p + 0x150) = 0;
        *(unsigned char*)((char*)p + 0x151) = 0;
        *(int*)((char*)p + 0x158) = -1;
        *(int*)((char*)p + 0x15c) = 0;
        *(int*)((char*)p + 0x160) = 0;
        *(void**)((char*)p + 0x3c) = lbl_40_data_891C;
        *(void**)((char*)p + 0x14c) = lbl_40_data_891C + 0x170;
        *(void**)((char*)p + 0x154) = lbl_40_data_891C + 0x180;
        *(int*)((char*)p + 0x164) = 0;
        *(int*)((char*)p + 0x168) = 0;
    }
    p->setIndex(arg0);
    return p;
}
