#pragma force_active on
struct MarioVirtualTarget {
    virtual int slot0();
    virtual int slot1();
    virtual int slot2();
    virtual int slot3();
    virtual int slot4();
    virtual int slot5();
};

extern "C" bool fn_91_BD88(MarioVirtualTarget* target) {
    return !target->slot3();
}
