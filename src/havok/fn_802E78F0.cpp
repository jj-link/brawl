#pragma force_active on
class Object {
public:
    virtual void call(int);
};

extern "C" void fn_802E78F0(Object* self) {
    self->call(-1);
}
