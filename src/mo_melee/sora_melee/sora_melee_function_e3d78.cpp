#pragma force_active on
typedef unsigned int u32;
struct Pair { u32 a, b; Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; } };
struct Base1 { virtual void dummy1(); };
struct Base2 { virtual void dummy2(); };
struct Nested : Base1, Base2 {
    u32 a;
    Pair pairs[6];
    u32 d, e;
};
struct Element { u32 a, b, c, d, e, f, g; Nested nested; };
class Class_1D940 {
public:
    virtual void fn_27_E403C();
    virtual Element* fn_27_E3280(int);
    virtual void fn_27_E3290();
    virtual int fn_27_CD58C();
};
extern "C" void fn_27_E3D78(Class_1D940* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_27_CD58C()) count = self->fn_27_CD58C() - index;
    for (int i = 0; i < count; ++i) *self->fn_27_E3280(index + i) = *value;
}