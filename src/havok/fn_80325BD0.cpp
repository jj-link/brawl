#pragma force_active on
class Object {
public:
    virtual void call(int);
};

extern "C" void fn_80325BD0(Object* self) {
    self->call(-1);
}
