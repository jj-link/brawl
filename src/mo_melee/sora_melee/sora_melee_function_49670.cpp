#pragma force_active on
struct Result {
    char padding[6];
    short value;
};

class Interface {
public:
    virtual ~Interface();
    virtual const Result& get() const = 0;
};

struct Object {
    char padding[0x48];
    Interface* interface;
};

extern "C" short fn_27_49670(const Object* self) {
    return self->interface->get().value;
}
