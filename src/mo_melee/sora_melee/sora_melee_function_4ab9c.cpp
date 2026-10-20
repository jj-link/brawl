#pragma force_active on
struct Result {
    char padding[0x90];
    float value;
};

class Interface {
public:
    virtual void unused();
    virtual const Result& get() const;
};

struct Object {
    char padding[0x48];
    Interface* interface;
};

extern "C" float fn_27_4AB9C(const Object* self) {
    return self->interface->get().value;
}
