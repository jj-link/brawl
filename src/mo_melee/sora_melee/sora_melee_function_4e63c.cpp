#pragma force_active on
class Interface {
public:
    virtual void unused();
    virtual char* get() const;
};

struct Object {
    char padding[0x2c];
    Interface* member;
};

extern "C" char* fn_27_4E63C(const Object* self) {
    return self->member->get() + 4;
}
