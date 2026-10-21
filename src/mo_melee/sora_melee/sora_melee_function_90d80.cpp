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
    virtual int invoke(short value);
};

extern "C" int fn_27_90D80(Object* self, int value) {
    return self->invoke((short)value);
}
