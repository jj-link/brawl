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

struct Base1 {
    virtual void dummy1();
};

struct Base2 {
    virtual void dummy2();
};

struct Nested : Base1, Base2 {
    u32 b0;
    Pair pairs[6];
};

struct Element {
    u32 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    Nested nested;
    unsigned char f0, f1;
};

class Class_2C60 {
public:
    virtual void fn_62_CA3C();
    virtual Element* fn_62_BF04(int);
    virtual void fn_62_BF14();
    virtual int fn_62_A624();
};

extern "C" void fn_62_C760(Class_2C60* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_62_A624()) {
        count = self->fn_62_A624() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_62_BF04(index + i) = *value;
    }
}
