#pragma force_active on
struct VBase {
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
    virtual int v16();
};

struct FnOuter;

struct FnChild {
    char pad[0x70];
    VBase* obj;
};

struct FnOuter {
    char pad[0x60];
    FnOuter* fighter;
    char pad2[0xD8 - 0x64];
    FnChild* child;
};

extern "C" int fn_93_FEDC(FnOuter* self);

extern "C" int fn_93_A408(FnOuter* self) {
    FnOuter* f = self->fighter;
    int r = 0;
    if (f->child->obj->v16() == 0x116) {
        r = fn_93_FEDC(f);
    }
    return r;
}
