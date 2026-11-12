#pragma force_active on

typedef unsigned int u32;

struct Pair {
    u32 a, b;
    Pair& operator=(const Pair& p) {
        a = p.a;
        b = p.b;
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
    u32 a0, a1, a2, a3, a4, a5, a6;
    Nested nested;
    u32 last;
};

class Array {
public:
    virtual void slot0();
    virtual Element* at(int);
    virtual void slot2();
    virtual int size();
};

extern "C" void fn_27_E5F08(Array* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->size()) {
        count = self->size() - index;
    }
    for (int i = 0; i < count; i++) {
        *self->at(index + i) = *value;
    }
}
