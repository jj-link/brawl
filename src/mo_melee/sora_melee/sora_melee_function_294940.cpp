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
    unsigned char padding[16];
    Interface interface;
};

extern "C" unsigned int fn_27_294940(Object* object) {
    return object->interface.get()->value;
}
