#pragma force_active on
class Object {
public:
    unsigned char padding[0x38];
    virtual ~Object();
    virtual void call();
};

struct State {
    Object first;
    Object second;
    unsigned char padding[0xC];
    int value;
};

extern "C" void fn_27_C0FD8(State* self) {
    self->value = 50;
    self->first.call();
    self->second.call();
}
