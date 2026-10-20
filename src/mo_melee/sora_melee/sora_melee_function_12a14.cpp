#pragma force_active on
struct Base {
    unsigned char padding[8];
};

struct Object : Base {
    virtual void unused0() = 0;
    virtual void unused1() = 0;
    virtual void unused2() = 0;
    virtual void unused3() = 0;
    virtual void unused4() = 0;
    virtual void unused5() = 0;
    virtual void unused6() = 0;
    virtual void unused7() = 0;
    virtual void unused8() = 0;
    virtual void unused9() = 0;
    virtual void unused10() = 0;
    virtual void unused11() = 0;
    virtual void unused12() = 0;
    virtual void unused13() = 0;
    virtual void unused14() = 0;
    virtual void unused15() = 0;
    virtual void unused16() = 0;
    virtual void unused17() = 0;
    virtual void unused18() = 0;
    virtual void unused19() = 0;
    virtual void unused20() = 0;
    virtual void unused21() = 0;
    virtual void unused22() = 0;
    virtual void unused23() = 0;
    virtual void unused24() = 0;
    virtual void unused25() = 0;
    virtual void unused26() = 0;
    virtual void unused27() = 0;
    virtual void unused28() = 0;
    virtual void unused29() = 0;
    virtual void unused30() = 0;
    virtual void unused31() = 0;
    virtual void unused32() = 0;
    virtual void unused33() = 0;
    virtual void unused34() = 0;
    virtual void unused35() = 0;
    virtual void unused36() = 0;
    virtual void unused37() = 0;
    virtual void unused38() = 0;
    virtual void unused39() = 0;
    virtual void unused40() = 0;
    virtual void unused41() = 0;
    virtual void unused42() = 0;
    virtual void unused43() = 0;
    virtual void unused44() = 0;
    virtual void unused45() = 0;
    virtual void unused46() = 0;
    virtual void unused47() = 0;
    virtual void unused48() = 0;
    virtual void unused49() = 0;
    virtual void unused50() = 0;
    virtual void unused51() = 0;
    virtual void callback(int) = 0;

    unsigned char paddingC[0x38];
    unsigned char flags;
};

extern "C" void fn_27_12A14(Object* self) {
    self->callback(0);
    self->flags |= 0x10;
}
