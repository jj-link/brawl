#pragma force_active on
struct Result {
    int unused;
    int value;
};

class Interface {
public:
    virtual ~Interface();
    virtual Result* get();
};

struct Object {
    char padding[0x10];
    Interface interface;
};

extern "C" int fn_27_11B4B0(Object* object) {
    return object->interface.get()->value;
}
