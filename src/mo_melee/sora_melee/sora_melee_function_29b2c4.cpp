#pragma force_active on
struct Argument {
    int kind;
    int value;

    Argument(int k, int v) : kind(k), value(v) {}
};

#define SLOT(n) virtual void unused##n();
#define TEN(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
    SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct Object {
    unsigned char padding[0x3C];

    TEN(a) TEN(b) TEN(c) TEN(d) TEN(e) TEN(f) TEN(g) TEN(h)
    TEN(i) TEN(j) TEN(k) TEN(l) TEN(m) TEN(n) TEN(o) TEN(p)
    SLOT(q0) SLOT(q1) SLOT(q2) SLOT(q3) SLOT(q4) SLOT(q5) SLOT(q6)

    virtual void call(const Argument*, int);
};

#undef TEN
#undef SLOT

extern "C" void fn_27_29B2C4(void*, Object* object) {
    Argument argument(0x34, 0);
    object->call(&argument, -1);
}
