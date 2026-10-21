#pragma force_active on
class Object {
public:
    virtual void slot0(int);
};

extern "C" void fn_802F0080(Object* self) {
    self->slot0(-1);
}
