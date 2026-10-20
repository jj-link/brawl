#pragma force_active on
void operator delete(void*);

class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

struct ObserverBase : soEventObserver<soGimmickEventObserver> {
    ~ObserverBase() {}
};

extern "C" void* fn_101_1D50(void* object, short deleting) {
    if (object != 0) {
        ObserverBase* observer = reinterpret_cast<ObserverBase*>(
            static_cast<unsigned char*>(object) + 4);
        observer->~ObserverBase();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
