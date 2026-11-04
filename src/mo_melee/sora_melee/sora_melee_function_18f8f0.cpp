#pragma force_active on

struct Id {
    int value;
};

inline Id makeId(int value) {
    Id id;
    id.value = value;
    return id;
}

struct Fn18F8F0Callee {
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int query(int, void*);
};

struct Fn18F8F0Holder {
    char pad[0x64];
    Fn18F8F0Callee* callee;
};

struct Fn18F8F0Accessor {
    char pad[0xD8];
    Fn18F8F0Holder* holder;
};

extern "C" bool fn_27_18F8F0(int, Fn18F8F0Accessor* accessor) {
    Fn18F8F0Holder* holder = accessor->holder;
    return !holder->callee->query(makeId(0x22000010).value, holder);
}
