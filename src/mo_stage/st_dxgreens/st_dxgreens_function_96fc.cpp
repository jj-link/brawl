#pragma force_active on

struct Pair {
    unsigned int a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};

struct Base1 {
    virtual void dummy1();
};

struct Base2 {
    virtual void dummy2();
};

struct Nested : Base1, Base2 {
    unsigned int u4c;
    Pair pairs[7];
    unsigned int u88, u8c;
};

struct Element {
    unsigned int u00, u04, u08, u0c, u10;
    float f14;
    unsigned int u18, u1c, u20, u24;
    float f28, f2c, f30;
    unsigned int u34, u38, u3c, u40;
    Nested nested;
};

class Class_1990 {
public:
    virtual void fn_79_801C();
    virtual Element* fn_79_74E4(int);
    virtual void fn_79_74F4();
    virtual int fn_79_59DC();
};

extern "C" void fn_79_96FC(Class_1990* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_79_59DC()) {
        count = self->fn_79_59DC() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_79_74E4(index + i) = *value;
    }
}
