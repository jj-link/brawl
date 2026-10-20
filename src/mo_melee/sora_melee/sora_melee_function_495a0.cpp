#pragma force_active on
struct Data {
    char padding[0xA4];
    float value;
};

struct Interface {
    virtual void unused();
    virtual Data* get();
};

struct Object {
    char padding[0x48];
    Interface* interface;
};

extern "C" float fn_27_495A0(Object self) {
    return self.interface->get()->value;
}
