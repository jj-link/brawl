#pragma force_active on
#define VIRTUAL_16(p) \
    virtual void p##0(); \
    virtual void p##1(); \
    virtual void p##2(); \
    virtual void p##3(); \
    virtual void p##4(); \
    virtual void p##5(); \
    virtual void p##6(); \
    virtual void p##7(); \
    virtual void p##8(); \
    virtual void p##9(); \
    virtual void p##A(); \
    virtual void p##B(); \
    virtual void p##C(); \
    virtual void p##D(); \
    virtual void p##E(); \
    virtual void p##F();

struct FtPoke {
    unsigned char padding[0x3C];

    VIRTUAL_16(slot0_)
    VIRTUAL_16(slot1_)
    VIRTUAL_16(slot2_)
    VIRTUAL_16(slot3_)
    VIRTUAL_16(slot4_)
    VIRTUAL_16(slot5_)
    VIRTUAL_16(slot6_)
    VIRTUAL_16(slot7_)
    VIRTUAL_16(slot8_)
    VIRTUAL_16(slot9_)
    VIRTUAL_16(slotA_)

    virtual void slotB_0();
    virtual void slotB_1();
    virtual void slotB_2();
    virtual void slotB_3();
    virtual void slotB_4();
    virtual void slotB_5();
    virtual void slotB_6();
    virtual void slotB_7();
    virtual void slotB_8();
    virtual void target();
};

#undef VIRTUAL_16

extern "C" {
void fn_27_112BEC();
void fn_27_368988(void*);
void fn_27_3769FC(void*);

void fn_116_9350(FtPoke* self) {
    self->target();
    fn_27_112BEC();
    fn_27_368988(reinterpret_cast<char*>(self) + 0x17FA4);
    fn_27_3769FC(reinterpret_cast<char*>(self) + 0x17FBC);
}
}
