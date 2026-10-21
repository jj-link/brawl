#pragma force_active on
class Object {
public:
    virtual void call(int);
};

extern "C" void fn_802E610C(Object* self) {
    self->call(-1);
}
