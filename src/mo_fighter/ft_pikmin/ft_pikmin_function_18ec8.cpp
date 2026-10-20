#pragma force_active on
struct Target {
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
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
};

extern "C" {
int fn_113_18EC8(char *self)
{
    char *a = *(char **)(self + 0x60);
    char *b = *(char **)(a + 0xd8);
    Target *t = *(Target **)(b + 0x64);
    return t->v18();
}
}
