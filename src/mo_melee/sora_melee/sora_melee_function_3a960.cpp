#pragma force_active on
struct Result {
    char padding[0x88];
    unsigned int value;
};

struct Interface {
    virtual ~Interface();
    virtual Result* get() const = 0;
};

struct Object {
    char padding[0x30];
    Interface* interface;
};

extern "C" unsigned int fn_27_3A960(const Object* object) {
    return object->interface->get()->value;
}
