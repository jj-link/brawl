#pragma force_active on
template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, signed char argument);
};

class soGimmickEventObserver
    : public soEventObserver<soGimmickEventObserver> {
};

extern "C" void fn_123_12FDC(
    soGimmickEventObserver* receiver, short id, int argument)
{
    receiver->addObserverSub(
        static_cast<short>(id),
        receiver,
        static_cast<signed char>(argument));
}
