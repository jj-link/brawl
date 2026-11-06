#pragma force_active on
typedef unsigned int u32;

struct Skip {
    u32 a, b;
    Skip& operator=(const Skip&) { return *this; }
};

struct Small { u32 a, b; };

struct Pair {
    u32 a, b;
    Pair operator=(const Pair& o) { a = o.a; b = o.b; return *this; }
};

struct Tail {
    Pair pairs[7];
};

struct Element {
    u32 f00, f04;
    Small f08;
    u32 f10;
    float f14;
    u32 f18, f1C, f20, f24;
    float f28, f2C, f30;
    u32 f34, f38, f3C, f40;
    Skip skip;
    u32 f4C;
    Tail arr;
    u32 f88, f8C;
};

class Manager {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64();
    virtual Element* at(int);
};

extern "C" void fn_71_103EC(Manager* self, int a, int b) {
    Element* src = self->at(a);
    Element* dst = self->at(b);
    *dst = *src;
}