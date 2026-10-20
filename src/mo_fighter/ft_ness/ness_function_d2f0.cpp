#pragma force_active on
class NessObject {
    unsigned char padding[8];

    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2C() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3C() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4C() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;

public:
    virtual void dispatch(void*, int) = 0;
    virtual void slot_5C() = 0;
    virtual unsigned int query() = 0;
};

extern "C" unsigned int fn_101_D2F0(NessObject* object, void* argument, int kind) {
    unsigned int result = object->query();
    if (result == 1) {
        object->dispatch(argument, kind);
    }
    return result;
}
