#pragma force_active on
struct Result {
    char padding[0x9c];
    float value;
};

struct Interface {
    virtual void unused();
    virtual const Result& get() const;
};

struct Object {
    char padding[0x48];
    Interface* interface;
};

extern "C" float fn_27_49428(const Object& object) {
    return object.interface->get().value;
}
