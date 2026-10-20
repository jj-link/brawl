#pragma force_active on
struct Result {
    unsigned char padding[0xB2];
    unsigned char value;
};

class Interface {
public:
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char padding[0x48];
    Interface* interface;
};

extern "C" unsigned char fn_27_4938C(Object object) {
    return object.interface->get()->value;
}
