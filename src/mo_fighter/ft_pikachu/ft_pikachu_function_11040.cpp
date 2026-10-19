#pragma force_active on
struct PikachuVirtualObj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual int slot5(int value, unsigned int id);
    virtual void slot6();
    virtual void slot7();
};

struct PikachuMidObj {
    char reserved[0x64];
    PikachuVirtualObj* obj;
};

struct PikachuOwner {
    char reserved[0xd8];
    PikachuMidObj* mid;
};

extern "C" int fn_98_11040(void*, PikachuOwner* owner) {
    return owner->mid->obj->slot5(-1, 0x20000003);
}
