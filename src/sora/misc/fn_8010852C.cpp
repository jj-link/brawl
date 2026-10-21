#pragma force_active on

extern unsigned int lbl_805A032C;

struct Base {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void target(unsigned int, unsigned int);

    char padding[0xE0];
    unsigned int value;
};

extern "C" void fn_8010852C(Base* self) {
    self->target(self->value, lbl_805A032C);
}
