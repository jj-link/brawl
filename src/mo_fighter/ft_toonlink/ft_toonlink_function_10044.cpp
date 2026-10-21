#pragma force_active on

struct Fn121State {
    int a;
    unsigned char b;
    int c;
};

struct Fn121Event {
    int a;
    unsigned char b;
    int c;
    int d;
    int e;
};

extern "C" void fn_121_100DC(Fn121State *);

class soModuleAccesser;

class soValueAccesser {
public:
    static int getConstantInt(soModuleAccesser *, unsigned long, unsigned long);
};

class Fn121Link {
public:
    virtual int v0(int, void *, int);
    virtual int v1(int, void *, int);
    virtual int v2(int, void *, int);
    virtual int v3(int, void *, int);
    virtual int v4(int, void *, int);
    virtual int v5(int, void *, int);
    virtual int v6(int, void *, int);
    virtual int v7(int, void *, int);
    virtual int v8(int, void *, int);
    virtual int v9(int, void *, int);
    virtual int v10(int, void *, int);
    virtual int v11(int, void *, int);
    virtual int v12(int, void *, int);
    virtual int v13(int, void *, int);
    virtual int v14(int, void *, int);
    virtual int v15(int, void *, int);
    virtual int v16(int, Fn121Event *, int);
};

class Fn121Module {
public:
    virtual int v0(int, void *, int);
    virtual int v1(int, void *, int);
    virtual int v2(int, void *, int);
    virtual int v3(int, void *, int);
    virtual int v4(int, void *, int);
    virtual int v5(int, void *, int);
    virtual int v6(int);
};

#define FN121_FIELD(p, t, o) (*(t *)((char *)(p) + (o)))

extern "C" void fn_121_10044(void *, soModuleAccesser *accesser)
{
    Fn121Event local;
    soModuleAccesser *obj = accesser;
    fn_121_100DC((Fn121State *)&local);

    int value = soValueAccesser::getConstantInt(obj, 0x5dc2, 0);
    local.c = 1;
    local.d = value;

    Fn121Link *s = (Fn121Link *)FN121_FIELD(
        FN121_FIELD(obj, void *, 0xd8), void *, 0x54);
    s->v16(0, &local, 0);

    Fn121Module *q = (Fn121Module *)FN121_FIELD(
        FN121_FIELD(obj, void *, 0xd8), void *, 0x44);
    q->v6(value);
}
