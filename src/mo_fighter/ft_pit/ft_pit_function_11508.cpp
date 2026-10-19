#pragma force_active on
struct Foo {
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3();
    virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7();
    virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11();
    virtual int v12(); virtual int v13(); virtual int v14();
};

extern "C" int fn_112_11508(Foo *fp)
{
    return fp->v14();
}
