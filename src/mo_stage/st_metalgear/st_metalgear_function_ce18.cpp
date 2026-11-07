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
    u32 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    Nested nested;
    unsigned char f0, f1;
};

class Class_2930 {
public:
    virtual void fn_71_D0F4();
    virtual Element* fn_71_C5BC(int);
    virtual void fn_71_C5CC();
    virtual int fn_71_A130();
};

extern "C" void fn_71_CE18(Class_2930* self, int index, const Element* value, unsigned int count) {
    int n = (int)count;
    if (n + index >= self->fn_71_A130()) n = self->fn_71_A130() - index;
    for (int i = 0; i < n; ++i) {
        Element* dest = self->fn_71_C5BC(index + i);
        *dest = *value;
    }
}