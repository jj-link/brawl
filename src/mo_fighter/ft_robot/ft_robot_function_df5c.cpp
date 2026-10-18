#pragma force_active on
struct Obj {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
};

struct Mid {
    char pad[0xc];
    Obj *obj;
};

struct Top {
    char pad[0xd8];
    Mid *mid;
};

extern "C" int fn_120_DF5C(void *unused, Top *self)
{
    return self->mid->obj->v12();
}
