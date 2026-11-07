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
class Class_2428 {
public:
    virtual void fn_68_E3F0();
    virtual Element* fn_68_D810(int);
    virtual void fn_68_D820();
    virtual int fn_68_D700();
};
class Class_1870 {
public:
    virtual void fn_68_94B0();
    virtual Element* fn_68_8978(int);
    virtual void fn_68_8988();
    virtual int fn_68_64EC();
};
extern "C" void fn_68_E0DC(Class_2428* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_68_D700()) {
        count = self->fn_68_D700() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_68_D810(index + i) = *value;
    }
}