#pragma force_active on
struct Result {
    unsigned char padding[0x10];
    float value;
};

class Interface {
public:
    virtual ~Interface();
    virtual const Result& get() const = 0;
};

struct Object {
    unsigned char padding[0x8c];
    Interface* interface;
};

extern "C" float fn_27_17374(const Object* self) {
    return self->interface->get().value;
}
