#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_40_2A584(void*, const char*);
extern const float lbl_40_rodata_468[];
extern char lbl_40_data_9750[];
}

struct Base {
    char pad0[0x3c];
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
    virtual void apply(int);

    char pad40[0xa4];
    int flags;
    char pade8[0x78];
    void* vtable160;
    int a164, a168, a16c, a170;
    float a174, a178, a17c;
    int a180, a184;
    bool a188;
    float a18c, a190, a194, a198;
};

extern "C" Obj* fn_40_2AF48(int arg, const char* name)
{
    const float* values = lbl_40_rodata_468;
    Obj* p = (Obj*)__nw__FUlQ25Heaps8HeapType(0x19c, 15);
    if (p) {
        fn_40_2A584(p, name);
        p->a164 = -1;
        p->a168 = 0;
        p->a16c = 0;
        *(void**)((char*)p + 0x3c) = lbl_40_data_9750;
        p->vtable160 = lbl_40_data_9750 + 0x1cc;
        p->a170 = 3;
        p->a174 = values[0];
        p->a178 = values[0];
        p->a17c = values[0];
        p->a180 = -1;
        p->a184 = -1;
        p->a188 = false;
        p->a18c = values[1];
        p->a190 = values[2];
        p->a194 = values[3];
        p->a198 = values[3];
        p->flags = 31;
    }
    if (p)
        p->apply(arg);
    return p;
}
