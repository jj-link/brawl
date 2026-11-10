#pragma force_active on

struct Pair {
    unsigned int a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};
struct Skip {
    unsigned int a, b;
    Skip& operator=(const Skip&) { return *this; }
};
struct Small { unsigned int a, b; };
struct Tail { Pair pairs[7]; };
struct Element {
    unsigned int a, b;
    Small c;
    unsigned int d;
    float e;
    unsigned int f, g, h, i;
    float j, k, l;
    unsigned int m, n, o, p;
    Skip skip;
    unsigned int q;
    Tail tail;
    unsigned int t, u;
};

class Holder {
public:
    virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6c();
    virtual Element* get();
};

class HolderArg {
public:
    virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6c();
    virtual Element* get(int);
};

extern "C" void fn_77_556C(Holder* self, int unused, int arg) {
    Element* src = self->get();
    Element* dst = ((HolderArg*)self)->get(arg);
    *dst = *src;
}
