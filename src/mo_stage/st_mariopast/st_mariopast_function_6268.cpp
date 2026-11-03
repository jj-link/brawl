#pragma force_active on

typedef unsigned int u32;

struct Pair {
    u32 a, b;

    Pair& operator=(const Pair& rhs) {
        a = rhs.a;
        b = rhs.b;
        return *this;
    }
};

struct Base1 { virtual void dummy1(); };
struct Base2 { virtual void dummy2(); };

struct Nested : Base1, Base2 {
    u32 b0;
    Pair pairs[6];
};

struct Element {
    u32 a0, a1;
    u32 data[8];
    Nested nested;
    unsigned char f0, f1;
};

class Self {
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

class SelfArg {
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

extern "C" void fn_48_6268(Self* self, int, Element* arg) {
    Element* src = self->get();
    Element* dst = ((SelfArg*)self)->get(arg);
    *dst = *src;
}