#pragma force_active on

typedef unsigned int u32;

struct Flags {
    u32 pad;
    u32 flags;
};

struct Anim {
    void* vtable;
    Flags* data;
};

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

    char pad40[0x90];
    Anim anim;
    char padD8[0x9c];
    unsigned char a174;
    char pad175[7];
    u32 a17c, a180, a184, a188;
    unsigned char a18c;
    char pad18d[3];
    char generator[8];
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_63_2B6C(Obj*, const char*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_63_data_5510[];

inline Obj* construct(Obj* p, const char* z) {
    fn_63_2B6C(p, z);
    *(void**)((char*)p + 0x3c) = lbl_63_data_5510;
    __ct__14snd3DGeneratorFv(p->generator);
    p->a17c = 0;
    p->a180 = 0;
    p->a184 = 0;
    p->a188 = 0;
    p->a174 = 0x10;
    p->a18c = 0xff;

    Anim* a = &p->anim;
    if (!a)
        return p;
    a->data->flags |= 1;
    return p;
}

extern "C" Obj* fn_63_13AE0(int x, const char* y, const char* z) {
    Obj* p = (Obj*)__nw__FUlQ25Heaps8HeapType(0x198, 15);
    if (p)
        p = construct(p, z);
    if (p) {
        p->v44(x);
        p->v80(y);
    }
    return p;
}
