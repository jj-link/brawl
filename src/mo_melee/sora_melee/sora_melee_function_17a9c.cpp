#pragma force_active on
struct Result {
    char padding[0x28];
    unsigned int value;
};

struct Interface {
    virtual void unused();
    virtual Result* get();
};

struct Object {
    char padding[0x90];
    Interface* interface;
};

extern "C" unsigned int fn_27_17A9C(Object* __restrict object) {
    return object->interface->get()->value;
}
