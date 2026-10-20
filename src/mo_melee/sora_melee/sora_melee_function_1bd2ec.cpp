#pragma force_active on
struct Result {
    unsigned int unused;
    unsigned int value;
};

struct Interface {
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char padding[0x10];
    Interface interface;
};

extern "C" unsigned int fn_27_1BD2EC(Object* object) {
    return object->interface.get()->value;
}
