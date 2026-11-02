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

class Class_2250 {
public:
    virtual void fn_51_A60C();
    virtual Element* fn_51_9A2C(int);
    virtual void fn_51_9A3C();
    virtual int fn_51_6738();
};

extern "C" void fn_51_A2F8(Class_2250* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_51_6738()) {
        count = self->fn_51_6738() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_51_9A2C(index + i) = *value;
    }
}
