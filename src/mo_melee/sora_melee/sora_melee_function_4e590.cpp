#pragma force_active on
struct Result {
    unsigned char pad[0x10];
    float value;
};

struct Interface {
    virtual void dummy();
    virtual Result* call();
};

struct Object {
    unsigned char pad[0x2c];
    Interface* interface;
};

extern "C" float fn_27_4E590(Object* self) {
    return self->interface->call()->value;
}
