#pragma force_active on
class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void invoke(int);
    unsigned char padding[0x18];
    int value;
};

extern "C" void fn_27_B2228(Object* object) {
    int value = object->value;
    if (value != 0) {
        object->invoke(value);
    }
}
