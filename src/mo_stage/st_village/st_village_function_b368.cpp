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
class Class_3790 {
public:
    virtual void fn_70_B644();
    virtual Element* fn_70_AB0C(int index);
    virtual void fn_70_AB1C();
    virtual int fn_70_9164();
};
extern "C" void fn_70_B368(Class_3790* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_70_9164()) {
        count = self->fn_70_9164() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_70_AB0C(index + i) = *value;
    }
}
