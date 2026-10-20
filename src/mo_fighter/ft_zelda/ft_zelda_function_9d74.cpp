#pragma force_active on
#define SLOT(n) virtual void slot##n();
#define SLOTS10(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
    SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct Zelda {
    unsigned char pad[0x3c];

    SLOTS10(0) SLOTS10(1) SLOTS10(2) SLOTS10(3)
    SLOTS10(4) SLOTS10(5) SLOTS10(6) SLOTS10(7)
    SLOTS10(8) SLOTS10(9) SLOTS10(10) SLOTS10(11)
    SLOTS10(12) SLOTS10(13) SLOTS10(14) SLOTS10(15)
    SLOT(160) SLOT(161) SLOT(162) SLOT(163) SLOT(164)

    virtual void first(int);

    SLOT(165) SLOT(166) SLOT(167) SLOT(168) SLOT(169) SLOT(170)

    virtual void second(int, int);
};

#undef SLOTS10
#undef SLOT

extern "C" void fn_104_9D74(Zelda* self, int arg, int value) {
    self->first(value);
    self->second(arg, 0x11b);
}
