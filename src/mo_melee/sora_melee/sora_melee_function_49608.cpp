#pragma force_active on
struct Result {
    float padding[42];
    float value;
};

struct Interface {
    virtual ~Interface();
    virtual Result* get() = 0;
};

struct Object {
    unsigned int padding[18];
    Interface* interface;

    float value() const {
        return interface->get()->value;
    }
};

extern "C" float fn_27_49608(const Object* object) {
    return object->value();
}
