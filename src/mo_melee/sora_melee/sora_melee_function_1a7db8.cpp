#pragma force_active on
class soGimmickEventObserver;

template <class T>
struct soEventObserver {
    virtual void initialize(short, signed char);
};

template <>
void soEventObserver<soGimmickEventObserver>::initialize(short arg4, signed char arg5) {
    soEventObserver<soGimmickEventObserver>* self = this;
    self->initialize(arg4, arg5);
}
