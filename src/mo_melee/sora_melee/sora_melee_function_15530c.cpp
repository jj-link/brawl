#pragma force_active on

struct Id {
    int value;
};

inline Id makeId(int value) {
    Id id;
    id.value = value;
    return id;
}

class Method {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int query(int, void*);
};

struct ManagerAccess {
    char pad[0x64];
    Method* method;
};

struct Accessor {
    char pad[0xD8];
    ManagerAccess* access;
};

extern "C" bool fn_27_15530C(void*, Accessor* accessor) {
    ManagerAccess* access = accessor->access;
    return access->method->query(makeId(0x10000026).value, access) <= 0;
}
