#pragma force_active on
struct Result {
    unsigned char padding[0xB1];
    unsigned char value;
};

struct Interface {
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char padding[0x48];
    Interface* interface;
};

extern "C" unsigned char fn_27_493F4(Object self) {
    return self.interface->get()->value;
}
