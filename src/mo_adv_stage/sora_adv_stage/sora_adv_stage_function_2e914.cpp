#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_40_22ED0(void*, const char*);
extern "C" unsigned char lbl_40_data_BE68[];
extern "C" const float lbl_40_rodata_550;

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
    virtual void v42(int);
};

extern "C" void* fn_40_2E914(int arg0, const char* arg1) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x170, 15);
    if (obj) {
        fn_40_22ED0(obj, arg1);
        *(void**)((char*)obj + 0x3C) = lbl_40_data_BE68;
        *(int*)((char*)obj + 0x15C) = 0;
        *(unsigned char*)((char*)obj + 0x160) = 0;
        *(int*)((char*)obj + 0x164) = 1;
        *(float*)((char*)obj + 0x168) = lbl_40_rodata_550;
        *(unsigned char*)((char*)obj + 0x16C) = 0;
    }
    if (obj) {
        obj->v42(arg0);
    }
    return obj;
}
