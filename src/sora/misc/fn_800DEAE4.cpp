#pragma force_active on
extern "C" void setUpdateRate__16gfModelAnimationFf(void*, float);
extern "C" void fn_800B753C(void*, float);
extern const float lbl_805A2368;
extern const float lbl_805A2374;

struct Obj2 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v13(void*, void*);
    virtual void v14();
    virtual void v15(void*);
    char pad[0xE4 - 4];
    void* e4;
};
struct S { char pad[8]; Obj2* o; };
struct T { char pad[0x10]; void* p10; void* anim; };
struct E { char pad[0x10]; void* p10; };

extern "C" void fn_800DEAE4(S* self) {
    int i;
    T* t = *(T**)((char*)self + 0x50);
    setUpdateRate__16gfModelAnimationFf(t->anim, lbl_805A2368);
    fn_800B753C(t, lbl_805A2374);
    E** p = (E**)((char*)self + 0x34);
    for (i = 13; i < 24; i++) {
        E* e = p[4];
        if (e) {
            self->o->v15(e->p10);
        }
        p++;
    }
    Obj2* o = self->o;
    o->v13(o->e4, t->p10);
}
