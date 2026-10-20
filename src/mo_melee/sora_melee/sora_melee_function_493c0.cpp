#pragma force_active on
struct Result {
    unsigned char padding[0xB0];
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

extern "C" unsigned char fn_27_493C0(Object* __restrict object) {
    return object->interface->get()->value;
}
