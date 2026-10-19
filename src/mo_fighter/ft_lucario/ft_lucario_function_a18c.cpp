#pragma force_active on
#define SLOT(n) virtual void slot##n() = 0;
#define TEN(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
    SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct ObjectPrefix {
    unsigned char data[0x3C];
};

class Object : private ObjectPrefix {
public:
    TEN(a) TEN(b) TEN(c) TEN(d) TEN(e) TEN(f)
    TEN(g) TEN(h) TEN(i) TEN(j) TEN(k) TEN(l)
    TEN(m) TEN(n) TEN(o) TEN(p) TEN(q) TEN(r)
    SLOT(s0) SLOT(s1) SLOT(s2) SLOT(s3) SLOT(s4) SLOT(s5)
    virtual void callback() = 0;
};

#undef TEN
#undef SLOT

extern "C" void fn_118_A18C(Object* object) {
    object->callback();
}
