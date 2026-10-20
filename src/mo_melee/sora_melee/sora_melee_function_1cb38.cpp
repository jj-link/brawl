#pragma force_active on
struct Result {
    char padding[0x1c];
    unsigned int value;
};

struct Interface {
    virtual void unused();
    virtual Result* get();
};

struct Object {
    char padding[0x8c];
    Interface* interface;
};

extern "C" unsigned int fn_27_1CB38(Object* __restrict object) {
    return object->interface->get()->value;
}
