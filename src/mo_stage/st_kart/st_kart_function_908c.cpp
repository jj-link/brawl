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

class Class_1700 {
public:
    virtual void fn_49_9368();
    virtual Element* fn_49_8830(int index);
    virtual void fn_49_8840();
    virtual int fn_49_6D28();
};

extern "C" void fn_49_908C(Class_1700* self, int start, const Element* value, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->fn_49_6D28()) {
        count = self->fn_49_6D28() - start;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_49_8830(start + i) = *value;
    }
}