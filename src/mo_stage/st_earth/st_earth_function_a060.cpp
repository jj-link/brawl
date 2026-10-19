#pragma force_active on
struct Interface {
    virtual int unused0();
    virtual int unused1();
    virtual int unused2();
    virtual int unused3() = 0;
};

extern "C" bool fn_66_A060(Interface* self) {
    return self->unused3() == 0;
}
