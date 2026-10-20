#pragma force_active on
struct Result {
    int reserved;
    int value;
};

class Object {
public:
    virtual ~Object();
    virtual Result& get() const;
};

struct Context {
    char reserved[0x2C];
    Object* object;
};

extern "C" int& fn_27_4BAC0(const Context* self) {
    return self->object->get().value;
}
