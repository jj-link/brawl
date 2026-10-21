#pragma force_active on
struct Result {
    float pad[19];
    float value;
};

class Interface {
public:
    virtual ~Interface();
    virtual const Result& get() const = 0;
};

struct Object {
    unsigned int pad[2];
    Interface* object;
};

extern "C" float fn_27_379A0(const Object* self) {
    return self->object->get().value;
}
