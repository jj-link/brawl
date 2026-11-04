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
    u32 a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
    Nested nested;
    unsigned char f0,f1;
};
class Class_1E10 {
public:
    virtual void fn_74_9ADC();
    virtual Element* fn_74_8FA4(int);
    virtual void fn_74_8FB4();
    virtual int fn_74_6B18();
};
extern "C" void fn_74_9800(Class_1E10* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_74_6B18()) {
        count = self->fn_74_6B18() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_74_8FA4(index + i) = *value;
    }
}