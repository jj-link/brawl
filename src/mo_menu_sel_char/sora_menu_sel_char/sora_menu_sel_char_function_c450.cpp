#pragma force_active on
struct Mgr {
    virtual ~Mgr();
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
    virtual void* v12(void* x);
};

struct Elem {
    char pad[0x10];
    void* p;
};

struct Self {
    char pad[0x6c];
    Mgr* mgr;
    char pad2[0x13c - 0x70];
    Elem* arr[1];
};

extern "C" void* fn_10_C450(Self* self, int idx)
{
    return self->mgr->v12(self->arr[idx]->p);
}
