#pragma force_active on
extern "C" void setUpdateRate__16gfModelAnimationFf(void*, float);
extern "C" void fn_800B753C(void*, float);
extern const float lbl_805A2368;
extern const float lbl_805A2374;

struct V {
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
    virtual void v11(int, void*);
    virtual void v12();
    virtual void v13(void*);
    char pad[0xe0];
    int e4;
};

struct Ent { char p[0x10]; void* v10; };
struct Obj { char p[0x10]; void* v10; void* v14; };

extern "C" void fn_800DED0C(void* s) {
    char* self = (char*)s;
    int i;
    Obj* o = *(Obj**)(self + 0x58);
    setUpdateRate__16gfModelAnimationFf(o->v14, lbl_805A2368);
    fn_800B753C(o, lbl_805A2374);
    Ent** p = (Ent**)(self + 0x34);
    for (i = 13; i < 24; i++, p++) {
        Ent* e = p[4];
        if (e) {
            (*(V**)(self + 8))->v13(e->v10);
        }
    }
    V* b = *(V**)(self + 8);
    b->v11(b->e4, o->v10);
    *(unsigned char*)(self + 0x174) = 0;
}
