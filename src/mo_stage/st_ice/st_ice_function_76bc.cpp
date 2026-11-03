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
class Class_1890 {
public:
    virtual void fn_62_79D0();
    virtual Element* fn_62_6DF0(int);
    virtual void fn_62_6E00();
    virtual int fn_62_6134();
};
class Class_2C60 {
public:
    virtual void fn_62_CA3C();
    virtual Element* fn_62_BF04(int);
    virtual void fn_62_BF14();
    virtual int fn_62_A624();
};
class Class_4768 {
public:
    virtual void fn_62_79D0();
    virtual Element* fn_62_6DF0(int);
    virtual void fn_62_6E00();
    virtual int fn_62_F038();
};
extern "C" void fn_62_76BC(Class_1890* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_62_6134()) {
        count = self->fn_62_6134() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_62_6DF0(index + i) = *value;
    }
}
