#pragma force_active on
struct ObjBase {
    char pad0[0x3c];
};

struct Obj : ObjBase {
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
    virtual void v42(void* a);
    virtual void v43();
    virtual void v44(void* a);
    char pad1[0x168 - 0x40];
    float f168;
    char b16c;
    char b16d;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
extern "C" void fn_40_27800(Obj* obj, void* arg);
extern "C" char lbl_40_data_8E58[];
extern "C" const float lbl_40_rodata_438;

extern "C" Obj* fn_40_2A13C(void* a, void* b) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x174, 0xf);
    if (obj != 0) {
        fn_40_27800(obj, b);
        *(char**)((char*)obj + 0x3c) = lbl_40_data_8E58;
        obj->f168 = lbl_40_rodata_438;
        obj->b16c = 0;
        obj->b16d = 0;
    }
    if (obj != 0) {
        obj->v42(a);
    }
    return obj;
}
