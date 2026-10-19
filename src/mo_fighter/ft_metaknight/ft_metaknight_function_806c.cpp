#pragma force_active on
struct Mod {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int a, int b, int c);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10(int a);
};
struct Inner { char pad[0x58]; Mod* m; };
struct Acc { char pad[0xd8]; Inner* i; };
extern "C" void fn_27_13138C(void*);
extern "C" void fn_111_806C(void* a, int status, int c, int d, Acc* acc) {
    fn_27_13138C(a);
    switch (status) {
    case 0x1a: case 0x1b: case 0x1c:
    case 0x1e: case 0x1f: case 0x20:
    case 0x10c: case 0x10e: case 0x10f:
    case 0x115: case 0x11b: case 0x11c:
    case 0x11f: case 0x121:
        break;
    default:
        if (acc->i->m->v10(2) == 2) {
            acc->i->m->v3(2, 0, 1);
        }
    }
}
