#pragma force_active on
struct Result {
    char pad[0xA0];
    float value;
};

struct Interface {
    virtual void unused();
    virtual Result* get() const;
};

struct Object {
    char pad[0x48];
    Interface* member;
};

extern "C" float fn_27_4956C(const Object& self) {
    return self.member->get()->value;
}
