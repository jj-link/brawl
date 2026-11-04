#pragma force_active on
typedef unsigned int u32;
struct Pair {
    u32 a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};
struct Skip {
    u32 a, b;
    Skip& operator=(const Skip&) { return *this; }
};
struct Small { u32 a, b; };
struct Tail { Pair pairs[7]; };
struct Element {
    u32 a, b;
    Small c;
    u32 d;
    float e;
    u32 f, g, h, i;
    float j, k, l;
    u32 m, n, o, p;
    Skip skip;
    u32 q;
    Tail tail;
    u32 t, u;
};
class Array {
public:
    virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6c();
    virtual Element* at(int);
};
extern "C" void fn_49_AD64(Array* self, int a, int b) {
    *self->at(b) = *self->at(a);
}