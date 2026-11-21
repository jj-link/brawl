#pragma force_active on

struct Pair {
    unsigned int a, b;
    Pair& operator=(const Pair& rhs) {
        a = rhs.a;
        b = rhs.b;
        return *this;
    }
};

struct Base1 { virtual void dummy1(); };
struct Base2 { virtual void dummy2(); };
struct Nested : Base1, Base2 {
    unsigned int b0;
    Pair pairs[6];
};
struct Element {
    unsigned int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    Nested nested;
    unsigned char f0, f1;
};

class Class_18F0 {
public:
    virtual void fn_54_8D28();
    virtual Element* fn_54_81F0(int index);
    virtual void fn_54_8200();
    virtual int fn_54_66E8();
};

extern "C" void fn_54_8A4C(Class_18F0* self, int start, const Element* src, unsigned int countArg) {
    int count = countArg;
    if (count + start >= self->fn_54_66E8()) {
        count = self->fn_54_66E8() - start;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_54_81F0(start + i) = *src;
    }
}
