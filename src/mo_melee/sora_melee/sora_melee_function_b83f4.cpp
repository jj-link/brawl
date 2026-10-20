#pragma force_active on
struct Result {
    unsigned int unknown;
    unsigned int value;
};

class Interface {
public:
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char padding[0x38];
    Interface* interface;
};

extern "C" bool fn_27_B83F4(Object* __restrict object) {
    return object->interface->get()->value != 0;
}
