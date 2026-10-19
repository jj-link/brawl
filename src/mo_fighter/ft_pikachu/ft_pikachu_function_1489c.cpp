#pragma force_active on
struct PikachuObj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void call(int a, int b);
};

struct PikachuInner {
    char reserved[0x64];
    PikachuObj* obj;
};

struct PikachuMid {
    char reserved[0xd8];
    PikachuInner* inner;
};

struct PikachuOwner {
    char reserved[0x60];
    PikachuMid* mid;
};

extern "C" void fn_98_1489C(PikachuOwner* owner, void* storage) {
    owner->mid->inner->obj->call(reinterpret_cast<int>(storage), 0x10000006);
}
