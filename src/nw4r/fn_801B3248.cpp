#pragma force_active on
extern "C" int fn_801AF838();

struct Obj {
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
    virtual void slot11();
    virtual void slot12(int arg);
};

struct Holder {
    unsigned char pad[0x138];
    int field138;
};

extern "C" int fn_801B3248(Obj* self, int arg1) {
    if (arg1 == 5) {
        Holder* h = reinterpret_cast<Holder*>(self);
        int temp = h->field138;
        self->slot12(temp);
        return temp;
    }
    return fn_801AF838();
}
