#pragma force_active on
extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
extern "C" void __dl__FPv(void*);

struct G3dObjLike {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12(int);
    char pad[0xE4 - 4];
    int unkE4;
};

struct Wrap {
    void* unk0;
    G3dObjLike* unk4;
};

extern "C" void* fn_8000E82C(Wrap* p, int arg1) {
    if (p != 0) {
        G3dObjLike* o = p->unk4;
        while (o->unkE4 != 0) {
            if (o->unkE4 != 0) {
                o->f12(o->unkE4 - 1);
            }
        }
        Destroy__Q34nw4r3g3d6G3dObjFv(p->unk4);
        p->unk0 = 0;
        if (arg1 > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
