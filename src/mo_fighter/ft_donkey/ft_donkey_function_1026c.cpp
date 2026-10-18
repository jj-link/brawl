#pragma force_active on
struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int call(int a, unsigned short b);
};

extern "C" int fn_92_1026C(void *unused, char *self)
{
    char *a = *(char **)(self + 0xd8);
    Base *b = *(Base **)(a + 0x3c);
    unsigned short z = 0;
    return b->call(z, z);
}
