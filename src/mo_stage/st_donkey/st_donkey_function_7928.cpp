#pragma force_active on
typedef unsigned int u32;
struct Pair { u32 a, b; Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; } };
struct Base1 { virtual void dummy1(); };
struct Base2 { virtual void dummy2(); };
struct Nested : Base1, Base2 {
    u32 u4c;
    Pair pairs[7];
    u32 u88, u8c;
};
struct Element {
    u32 u00, u04, u08, u0c, u10;
    float f14;
    u32 u18, u1c, u20, u24;
    float f28, f2c, f30;
    u32 u34, u38, u3c, u40;
    Nested nested;
};
class Class_1DE0 {
public:
    virtual void fn_50_7C3C();
    virtual Element* fn_50_705C(int);
    virtual void fn_50_706C();
    virtual int fn_50_63A0();
};
extern "C" void fn_50_7928(Class_1DE0* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_50_63A0()) {
        count = self->fn_50_63A0() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_50_705C(index + i) = *value;
    }
}