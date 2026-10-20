#pragma force_active on
struct Data {
    unsigned char padding[0x98];
    float value;
};

class Module {
public:
    virtual ~Module();
    virtual const Data* get() const = 0;
};

struct Object {
    unsigned char padding[0x48];
    const Module* module;
};

extern "C" float fn_27_49B7C(const Object* object) {
    return object->module->get()->value;
}
