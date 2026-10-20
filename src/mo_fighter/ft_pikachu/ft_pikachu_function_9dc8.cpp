#pragma force_active on
class PikachuDispatch {
    unsigned char reserved[0x3C];

public:
#define SLOT(n) virtual void slot##n();
#define TEN(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
    SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

    TEN(00) TEN(01) TEN(02) TEN(03) TEN(04) TEN(05)
    TEN(06) TEN(07) TEN(08) TEN(09) TEN(10) TEN(11)
    TEN(12) TEN(13) TEN(14) TEN(15) TEN(16) TEN(17)
    SLOT(180) SLOT(181) SLOT(182) SLOT(183) SLOT(184) SLOT(185)

#undef TEN
#undef SLOT

    virtual void dispatch();
};

extern "C" void fn_98_9DC8(PikachuDispatch* self) {
    self->dispatch();
}
