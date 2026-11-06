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
class Class_2930 {
public:
    virtual void fn_71_D0F4();
    virtual Element* fn_71_C5BC(int);
    virtual void fn_71_C5CC();
    virtual int fn_71_A130();
};
class Class_3A10 {
public:
    virtual void fn_71_103E4();
    virtual Element* fn_71_F804(int);
    virtual void fn_71_F814();
    virtual int fn_71_F6F4();
};
extern "C" void fn_71_100D0(Class_3A10* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_71_F6F4()) {
        count = self->fn_71_F6F4() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_71_F804(index + i) = *value;
    }
}