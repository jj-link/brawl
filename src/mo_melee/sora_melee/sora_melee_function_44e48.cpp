#pragma force_active on
struct Result {
    char padding[0x28];
    unsigned int value;
};

class Interface {
public:
    virtual void unused();
    virtual Result* get();
};

struct Object {
    char padding[0x58];
    Interface* interface;
};

extern "C" unsigned int fn_27_44E48(Object object) {
    return object.interface->get()->value;
}
