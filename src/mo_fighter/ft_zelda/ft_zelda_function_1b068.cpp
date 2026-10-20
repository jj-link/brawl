#pragma force_active on
#define VIRTUAL_SLOT(name) virtual void unused##name();
#define VIRTUAL_TEN(prefix) \
    VIRTUAL_SLOT(prefix##0) VIRTUAL_SLOT(prefix##1) \
    VIRTUAL_SLOT(prefix##2) VIRTUAL_SLOT(prefix##3) \
    VIRTUAL_SLOT(prefix##4) VIRTUAL_SLOT(prefix##5) \
    VIRTUAL_SLOT(prefix##6) VIRTUAL_SLOT(prefix##7) \
    VIRTUAL_SLOT(prefix##8) VIRTUAL_SLOT(prefix##9)

struct ZeldaBase {
    unsigned char padding[0x3C];
};

struct Zelda : ZeldaBase {
    VIRTUAL_TEN(a)
    VIRTUAL_TEN(b)
    VIRTUAL_TEN(c)
    VIRTUAL_TEN(d)
    VIRTUAL_TEN(e)
    VIRTUAL_TEN(f)
    VIRTUAL_TEN(g)
    VIRTUAL_TEN(h)
    VIRTUAL_TEN(i)
    VIRTUAL_TEN(j)
    VIRTUAL_TEN(k)
    VIRTUAL_TEN(l)
    VIRTUAL_TEN(m)
    VIRTUAL_TEN(n)
    VIRTUAL_TEN(o)
    VIRTUAL_TEN(p)
    VIRTUAL_SLOT(q0)
    VIRTUAL_SLOT(q1)
    VIRTUAL_SLOT(q2)
    VIRTUAL_SLOT(q3)
    VIRTUAL_SLOT(q4)
    virtual void first(int);
    VIRTUAL_SLOT(q5)
    VIRTUAL_SLOT(q6)
    VIRTUAL_SLOT(q7)
    VIRTUAL_SLOT(q8)
    VIRTUAL_SLOT(q9)
    VIRTUAL_SLOT(r0)
    virtual void second(int, int);
};

#undef VIRTUAL_TEN
#undef VIRTUAL_SLOT

extern "C" void fn_104_1B068(Zelda* self, int arg, int value) {
    self->first(value);
    self->second(arg, 0x11E);
}
