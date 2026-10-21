#pragma force_active on
class Object {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
};

extern "C" void fn_802E216C(Object* self) {
    self->slot0(-1);
}
