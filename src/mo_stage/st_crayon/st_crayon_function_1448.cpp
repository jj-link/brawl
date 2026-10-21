#pragma force_active on
struct CrayonBase {
    unsigned char padding[0x3C];
};

struct Crayon : CrayonBase {
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
    virtual void setId(int);
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_56_F90(Crayon*, const char*);
extern "C" unsigned char lbl_56_data_668[];

extern "C" Crayon* create__14grCrayonStaticFiPCc(int id, const char* name) {
    Crayon* object = (Crayon*)__nw__FUlQ25Heaps8HeapType(0x170, 15);
    if (object) {
        fn_56_F90(object, name);
        *(void**)((unsigned char*)object + 0x3C) = lbl_56_data_668;
    }
    if (object) {
        object->setId(id);
    }
    return object;
}
