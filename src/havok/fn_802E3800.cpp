#pragma force_active on
class Object {
public:
    virtual void slot0(int);
};

extern "C" void fn_802E3800(Object* self) {
    self->slot0(-1);
}
