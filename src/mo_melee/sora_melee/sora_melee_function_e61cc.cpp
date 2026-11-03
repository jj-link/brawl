#pragma force_active on
typedef unsigned int u32;
struct Pair {
    u32 a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};
struct Skip {
    u32 a, b;
    Skip& operator=(const Skip&) { return *this; }
};
struct Tail { Pair pairs[6]; };
struct Small { u32 a, b; };
struct Element {
    u32 a0;
    Small a1, a2, a3;
    Skip skip;
    u32 b0;
    Tail tail;
    u32 last;
};
class soNullable {
public:
    virtual void isNull();
    virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25();
    virtual Element* slot26(int);
};
extern "C" void fn_27_E61CC(soNullable* self, int a, int b) {
    Element* src = self->slot26(a);
    Element* dst = self->slot26(b);
    *dst = *src;
}