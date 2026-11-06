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
class Class_1B18 {
public:
    virtual void fn_78_7040();
    virtual Element* fn_78_6460(int);
    virtual void fn_78_6470();
    virtual int fn_78_57A4();
};
extern "C" void fn_78_6D2C(Class_1B18* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_78_57A4()) {
        count = self->fn_78_57A4() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_78_6460(index + i) = *value;
    }
}