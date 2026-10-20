#pragma force_active on
class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void reset();

    unsigned char pad04[0x44];
    int state;
    unsigned char pad4C[0x0D];
    bool flag;
};

struct Params {
    unsigned char pad00[0x0C];
    unsigned int flags;
};

extern "C" void fn_27_5753C(Object* self, void*, void*, Params params) {
    self->flag = 0;
    if (!((params.flags >> 4) & 1)) {
        self->reset();
    }
    self->state = -1;
}
