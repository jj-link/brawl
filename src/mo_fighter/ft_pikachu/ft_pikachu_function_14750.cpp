#pragma force_active on
struct PikachuSubObject {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int value);
};

struct PikachuMidObject {
    char reserved[0x64];
    PikachuSubObject* sub;
};

struct PikachuAccesserObject {
    char reserved[0xd8];
    PikachuMidObject* mid;
};

struct PikachuOwnerObject {
    char reserved[0x60];
    PikachuAccesserObject* accesser;
};

extern "C" int fn_98_14750(PikachuOwnerObject* owner) {
    return owner->accesser->mid->sub->slot4(0x10000005);
}
