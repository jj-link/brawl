#pragma force_active on
struct A {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void call(int, void*);
};
struct B {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24();
    virtual void call(int);
};
struct Acc {
    char pad[0x20];
    B* b;
    char pad2[0x54 - 0x24];
    A* a;
};
struct Owner {
    char pad[0xD8];
    Acc* acc;
};
struct Self {
    char pad[0x21B6];
    unsigned char f21b6;
    char pad1;
    unsigned char f21b8;
    unsigned char f21b9;
    char pad2[1];
    unsigned char f21bb;
    char pad3[0x21CC - 0x21BC];
    int f21cc;
    char pad4[0x2214 - 0x21D0];
    unsigned char f2214;
};
struct Args {
    int a;
    unsigned char b;
    int c;
};
extern "C" void fn_41_45C28(Self* s, Owner* o) {
    unsigned char t = s->f2214;
    s->f2214 = 0;
    if (t) {
        s->f21b6 = 1;
        s->f21b8 = 0;
        s->f21bb = 0;
        s->f21b9 = 0;
        int v = s->f21cc;
        Args args;
        args.a = 0x13ff;
        args.b = 0;
        args.c = v;
        o->acc->a->call(3, &args);
        if (args.b == 1) {
            o->acc->b->call(0);
        }
    }
}