#pragma force_active on
struct soAnimCmdEventObserver;
template <class T> struct soEventObserver {
    void addObserverSub(long, T*, signed char);
};
extern "C" {
void fn_91_A36C(void* a, short b, signed char c) {
    soEventObserver<soAnimCmdEventObserver>* self = reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(a);
    self->addObserverSub(b, reinterpret_cast<soAnimCmdEventObserver*>(a), c);
}
}
