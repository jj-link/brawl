#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__9grGimmickFPCc(void*, const char*);
extern "C" unsigned char lbl_40_data_3CD8[];

struct ObjBase {
    unsigned char pad[0x3C];
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
    virtual void setup(void*);
};

extern "C" void* fn_40_19AAC(void* arg0, const char* name)
{
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x150, 15);
    if (obj) {
        __ct__9grGimmickFPCc(obj, name);
        *(unsigned int*)((char*)obj + 0x3C) =
            (unsigned int)lbl_40_data_3CD8;
        *(unsigned int*)((char*)obj + 0x14C) = 0;
        *(unsigned int*)((char*)obj + 0xE4) = 0;
    }
    if (obj) {
        obj->setup(arg0);
    }
    return obj;
}
