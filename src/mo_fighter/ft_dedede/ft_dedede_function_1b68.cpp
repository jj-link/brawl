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

extern "C" void* fn_117_1B68(void* object, short deleting) {
    if (object != 0) {
        reinterpret_cast<ObserverBase*>(
            static_cast<char*>(object) + 4)->~ObserverBase();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
