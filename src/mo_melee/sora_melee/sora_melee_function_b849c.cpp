#pragma force_active on
struct Result {
    unsigned char padding[8];
    int value;
};

struct Interface {
    virtual void unused();
    virtual Result& get();
};

struct Object {
    unsigned char padding[0x38];
    Interface* target;

    int getValue() const {
        return target->get().value;
    }
};

extern "C" int fn_27_B849C(const Object* self) {
    return self->getValue();
}
