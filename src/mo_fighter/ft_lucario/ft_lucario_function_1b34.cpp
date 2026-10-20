#pragma force_active on
void operator delete(void*);

class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

class Observer : public soEventObserver<soGimmickEventObserver> {
public:
    ~Observer() {}
};

extern "C" void* fn_118_1B34(void* object, short deleting) {
    if (object != 0) {
        Observer* observer = reinterpret_cast<Observer*>(
            static_cast<unsigned char*>(object) + 4);
        observer->~Observer();

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
