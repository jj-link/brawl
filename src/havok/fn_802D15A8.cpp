#pragma force_active on
class Object {
public:
    virtual void call(int);
};

extern "C" void fn_802D15A8(Object* self) {
    self->call(-1);
}
