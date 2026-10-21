#pragma force_active on
class Object {
public:
    virtual void slot0(int);
};

extern "C" void fn_802B1A8C(Object* self) {
    if (self != 0) {
        self->slot0(1);
    }
}
