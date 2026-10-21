#pragma force_active on
class soAnimCmdEventObserver;

template<typename T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, signed char argument);
};

class soAnimCmdEventObserver {
public:
    void addObserver(short id, signed char argument);
};

void soAnimCmdEventObserver::addObserver(short id, signed char argument) {
    ((soEventObserver<soAnimCmdEventObserver>*)this)->addObserverSub(id, this, argument);
}
