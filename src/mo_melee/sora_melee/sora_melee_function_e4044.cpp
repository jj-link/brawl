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
struct Tail { Pair pairs[6]; };
struct Element {
    u32 a0;
    Small a1, a2, a3;
    Skip skip;
    u32 b0;
    Tail tail;
    u32 last;
    u32 last2;
};

class Holder {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25();
    virtual Element* get();
};

class HolderArg {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25();
    virtual Element* get(Element* p);
};

extern "C" void fn_27_E4044(Holder* self, int, Element* arg) {
    Element* src = self->get();
    Element* dst = ((HolderArg*)self)->get(arg);
    *dst = *src;
}
