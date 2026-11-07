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
class Object_vptr_0 {
public:
    virtual void fn_48_6260();
    virtual Element* fn_48_5728(int);
    virtual void fn_48_5738();
    virtual int slot3();
};
extern "C" void fn_48_5F84(Object_vptr_0* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->slot3()) {
        count = self->slot3() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_48_5728(index + i) = *value;
    }
}