#pragma force_active on
struct Result {
    char padding[0xAC];
    float value;
};

struct Provider {
    virtual ~Provider();
    virtual const Result* get() const;
};

struct Object {
    char padding[0x48];
    Provider* provider;
};

extern "C" float fn_27_495D4(const Object* self) {
    return self->provider->get()->value;
}
