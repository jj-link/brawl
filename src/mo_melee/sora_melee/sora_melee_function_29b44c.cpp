#pragma force_active on

struct Id {
    int value;
};

inline Id makeId(int value) {
    Id id;
    id.value = value;
    return id;
}

class Chain;

class Callee {
public:
    virtual void isNull();
    virtual void fn_27_2A032C();
    virtual void fn_27_281B1C();
    virtual void fn_27_2839BC();
    virtual void fn_27_284EA0();
    virtual void fn_27_289454();
    virtual void fn_27_289FAC();
    virtual void fn_27_28A178();
    virtual void fn_27_28A1C4();
    virtual void fn_27_28A4F4();
    virtual void fn_27_289518();
    virtual void fn_27_289560();
    virtual void fn_27_29B494();
    virtual void fn_27_287730();
    virtual void fn_27_28B33C();
    virtual void fn_27_29B4C8();
    virtual void fn_27_29B5F4();
    virtual int query(int, Chain*);
};

struct Access {
    char pad[0x64];
    Callee* callee;
};

class Chain {
public:
    char pad[0xD8];
    Access* access;
};

struct Root {
    char pad[0x60];
    Chain* chain;
};

extern "C" int fn_27_29B44C(void*, Root* root) {
    Chain* chain = root->chain;
    return !chain->access->callee->query(makeId(0x12000009).value, chain);
}
