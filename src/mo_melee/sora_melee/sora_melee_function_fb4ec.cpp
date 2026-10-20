#pragma force_active on
struct Result {
    unsigned int reserved;
    unsigned int value;
};

class Interface {
public:
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char padding[16];
    Interface interface;
};

extern "C" unsigned int fn_27_FB4EC(Object* object) {
    return object->interface.get()->value;
}
