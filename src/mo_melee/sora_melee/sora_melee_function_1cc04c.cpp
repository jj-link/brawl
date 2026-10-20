#pragma force_active on
struct Result {
    unsigned int unused;
    unsigned int value;
};

class Interface {
public:
    virtual ~Interface();
    virtual Result* get();
};

struct Object {
    unsigned char padding[0x10];
    Interface interface;
};

extern "C" unsigned int fn_27_1CC04C(Object* object) {
    return object->interface.get()->value;
}
