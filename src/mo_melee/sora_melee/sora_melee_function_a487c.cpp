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
    unsigned char padding[0x30];
    Interface* interface;
};

extern "C" unsigned int fn_27_A487C(Object* __restrict self) {
    return self->interface->get()->value;
}
