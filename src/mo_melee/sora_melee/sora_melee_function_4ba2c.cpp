#pragma force_active on
struct Target {
    char pad[0x10];
    float value;
};

class Holder {
public:
    virtual void v0();
    virtual Target* get();
};

class Outer {
public:
    char pad[0x2c];
    Holder* m_holder;
};

extern "C" void fn_27_4BA2C(Outer* self, float value) {
    self->m_holder->get()->value = value;
}
