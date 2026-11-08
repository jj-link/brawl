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
class Class_19A8 {
public:
    virtual void fn_49_AD5C();
    virtual Element* fn_49_A17C(int);
    virtual void fn_49_A18C();
    virtual int fn_49_6E88();
};
class Class_1700 {
public:
    virtual void fn_49_9368();
    virtual void fn_49_8830();
    virtual void fn_49_8840();
    virtual void fn_49_6D28();
};
extern "C" void fn_49_AA48(Class_19A8* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_49_6E88()) {
        count = self->fn_49_6E88() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_49_A17C(index + i) = *value;
    }
}
