#pragma force_active on
typedef struct {
    unsigned char a;
    short b;
    short c;
} Rec;

struct Ent {
    int unk0;
    int unk4;
    int unk8;
    short unkC;
    short unkE;
};

struct ObjA {
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
    virtual Ent* get();
};

struct ObjB {
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
    virtual Ent* get(Ent* dst);
};

extern "C" void fn_27_77588(Rec* dst, const Rec* src);

extern "C" void fn_27_DE770(void* self, int unused, Ent* dst) {
    Ent* src = ((ObjA*)self)->get();
    Ent* d = ((ObjB*)self)->get(dst);
    fn_27_77588((Rec*)d, (Rec*)src);
    d->unk8 = src->unk8;
    d->unkC = src->unkC;
    d->unkE = src->unkE;
}
